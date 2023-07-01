import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Window 2.12
import MyQmlModel 1.0
import QtQuick.LocalStorage 2.0

ApplicationWindow {
    id : mainWin
    visible: true
    height: 480+50
    width: 640

    //title: qsTr("图片编辑")

    flags: Qt.Window | Qt.MSWindowsFixedSizeDialogHint | Qt.WindowStaysOnTopHint


    Item {
        focus: true

        Keys.onPressed: {
            console.log("Key pressed:", event.key);
            if (event.key === Qt.Key_Return) {
                saveButton.clicked()
            }
            else
            {
                abandonButton.clicked()
            }

        }
    }

    Column {

        anchors.left: parent.left
        anchors.right: parent.right

        Image {
            id: imageEle


        }

        Row{
            spacing: 40
            Button {
                id: abandonButton
                text: "放弃"
                font.pixelSize: 20 // set the font size to 30 pixels
                background: Image {
                        source: "qrc:/Image/gray_button.png"
                        fillMode: Image.PreserveAspectFit
                    }
                height: 50
                width : 300
                anchors.bottom: parent.bottom

                onClicked: {
                    QmlModel.bShowQmlWin = false
                }
            }

            Button {
                id: saveButton
                text: "保存"
                font.pixelSize: 20
                background: Image {
                        source: "qrc:/Image/yellow_button.png"
                        fillMode: Image.PreserveAspectFit
                    }
                height: 50
                width : 300
                anchors.bottom: parent.bottom

                onClicked: {
                    QmlModel.bShowQmlWin = false
                    QmlModel.slotSaveImage()
                }
            }
        }

    }

    Component.onCompleted:
    {

        if (QmlModel.bShowQmlWin)
        {
            console.log("source : ",QmlModel.qmlImage);
            imageEle.source = QmlModel.qmlImage
            //显示主窗口
            mainWin.show()
            //mainWin.forceActiveFocus() // set focus on the window
        }
        else
        {
            //隐藏主窗口
            mainWin.hide()
        }
    }



    Connections{
        target: QmlModel
        function onBShowQmlWinChanged()
        {
            console.log("source : Connections.onBShowQmlWinChanged:");
            if (QmlModel.bShowQmlWin)
            {

                console.log("source : ",QmlModel.qmlImage);
                imageEle.source = QmlModel.qmlImage


                //显示主窗口
                mainWin.show()
                //mainWin.forceActiveFocus() // set focus on the window
            }
            else
            {

                //隐藏主窗口
                mainWin.hide()
            }
        }
    }




}
