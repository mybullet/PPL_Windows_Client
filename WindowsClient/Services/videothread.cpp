#include <opencv2/opencv.hpp>
#include "videothread.h"
#include <QDateTime>
#include <QDir>
#include <QImage>
#include <QReadWriteLock>
#include <iostream>
#include "imagesaver.h"
#include <QWidget>
#include <QLabel>

using namespace cv;
using namespace std;

VideoThread::VideoThread(QObject *parent)
    : QThread{parent}
{


}

VideoThread::~VideoThread()
{
    StopRun();
}

void VideoThread::StopRun()
{
    m_bRunning = false;
}



void VideoThread::run()
{
    qDebug()<<"     VideoThread thread ID:"<<QThread::currentThreadId()<<'\n';

    m_bRunning = true;

    // 打开电脑摄像头
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "无法打开摄像头" << endl;
        return;
    }

    bool bVideoloaded = false;

    // 创建窗口
    //namedWindow("Camera", WINDOW_NORMAL);

    while (m_bRunning)
    {
        Mat frame;
        cap >> frame;

        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        Mat edges;
        Canny(gray, edges, 100, 200);

        //imshow("edges", edges);

        vector<vector<Point>> contours;
        findContours(edges, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        // Find all rectangular contours
        vector<vector<Point>> rect_contours;
        for (const auto& contour : contours)
        {
            vector<Point> approx;
            approxPolyDP(contour, approx, arcLength(contour, true) * 0.02, true);
            if (approx.size() == 4 && isContourConvex(approx))
            {
                double contour_area = contourArea(contour);
                double image_area = frame.rows * frame.cols;
                if (contour_area >= image_area * 0.01)
                {
                    rect_contours.push_back(approx);
                }
            }
        }

        // Find the largest rectangular contour
        if (!rect_contours.empty())
        {
            int max_contour_index = 0;
            double max_area = 0;
            for (int i = 0; i < rect_contours.size(); i++)
            {
                double area = contourArea(rect_contours[i]);
                if (area > max_area)
                {
                    max_area = area;
                    max_contour_index = i;
                }
            }

            // Draw the largest rectangular contour
            Rect rect = boundingRect(rect_contours[max_contour_index]);
            rectangle(frame, rect, Scalar(0, 0, 0), 5);

            // Set area outside of the rectangular contour to gray
            Mat mask(frame.size(), CV_8UC1, Scalar(0));
            drawContours(mask, rect_contours, max_contour_index, Scalar(255), FILLED);
            Mat gray_mask;
            cvtColor(mask, gray_mask, COLOR_GRAY2BGR);
            frame = frame & gray_mask;

            // Convert frame to QImage and store in threadImage
            qimg = QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

            // Read m_bSpaceFlag using a read lock
            m_spaceFlagLock.lockForRead();
            bool spaceFlag = m_bSpaceFlag;
            m_spaceFlagLock.unlock();

            if (spaceFlag && !qimg.isNull())
            {
                // Create a new thread to save the image
                QThread* saveThread = new QThread();
                ImageSaver* imageSaver = new ImageSaver(qimg);
                imageSaver->moveToThread(saveThread);

                // Connect the signal to start the saving process
                connect(this, &VideoThread::SignalSaveImage, imageSaver, &ImageSaver::SlotSaveImage);

                // Connect the finished signal to delete the objects and the thread
                connect(imageSaver, &ImageSaver::finished, imageSaver, &ImageSaver::deleteLater);
                connect(saveThread, &QThread::finished, saveThread, &QThread::deleteLater);

                connect(imageSaver, &ImageSaver::SignalUpdateImage,this,&VideoThread::SignalUpdateImage);

                // Start the thread and emit the signal
                saveThread->start();
                emit SignalSaveImage();

                // Write to m_bSpaceFlag using a write lock
                m_spaceFlagLock.lockForWrite();
                m_bSpaceFlag = false;
                m_spaceFlagLock.unlock();
            }


        }

        //imshow("Camera", frame);
        emit SignalUpdateVideoFrame(QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888));


        //qDebug() << "cv window is created!111111111111111111";

        if(!bVideoloaded)
        {
            bVideoloaded = true;
            emit SignalVideoLoaded();
        }

        QThread::msleep(200);
    }

    // Clean up
    cap.release();
    destroyAllWindows();

    exec();

}

void VideoThread::SlotSpacePressed()
{
    m_spaceFlagLock.lockForWrite();
    m_bSpaceFlag = true;
    m_spaceFlagLock.unlock();
}
