#pragma

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#include <QByteArray>
#include <QFile>

bool handleErrors();
bool encryptData(QByteArray& data, const QString& publicKeyPath, const QString& passPhrase);
bool decryptData(QByteArray& data, const QString& privateKeyPath, const QString& passPhrase);
