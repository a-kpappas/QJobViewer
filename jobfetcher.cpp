#include "jobfetcher.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QRegularExpression>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDir>

JobFetcher::JobFetcher(QObject *parent)
    : QNetworkAccessManager{parent}
{

}


QJsonObject JobFetcher::getJson(QUrl job)
{
    QByteArray data = this->queryServer(job);
    if (data.isEmpty()){
        qCritical()<<"Json is empty";
    }
    QJsonParseError *error_ptr = nullptr;
    QJsonDocument doc = QJsonDocument::fromJson(data,error_ptr);
    if (error_ptr!=nullptr && error_ptr->error){
        qCritical()<<"Parse error at"<<error_ptr->offset;
        qCritical()<<error_ptr->errorString();
    }
    return doc.object();
}

QByteArray JobFetcher::queryServer(QUrl job)
{
    QString data;
    QNetworkRequest request(job);
    QNetworkReply *reply = this->get(request);
    if (reply->error()){
        qCritical()<<"Network request failed to"<<job<<"with error"<<reply->error()<<".";
    }
    else{
    data = reply->readAll();
    }
    return data.toUtf8();
}

void JobFetcher::createServerDir(QUrl url){
#ifdef QT_DEBUG
    url = QUrl("https://openqa.opensuse.org/tests/3084627");
#endif
    QDir data_path = QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    if (!data_path.exists()){
        if (QFileInfo::exists(data_path.absolutePath())){
            qCritical()<<"Can't make data directory. File"<<data_path.absolutePath()<<"exists already.";
        }
        if (!data_path.mkdir(data_path.absolutePath())){
            qCritical()<<"Can't make data directory"<<data_path.absolutePath()<<"for unknown reasons.";
            abort();
        }
    }

    // Reverse the hostname url to create , like org.opensuse.openqa
    QString host = url.host();
    QStringList list = host.split(".");
    QString dir_name;
    for (const auto& i: list){
        dir_name.prepend(i+".");
    }
    Q_ASSERT(dir_name.endsWith('.'));
    dir_name.remove(QRegularExpression(".$"));


    QDir server_path = data_path.absoluteFilePath(dir_name);
    if (!server_path.exists()){
        if (QFileInfo::exists(server_path.absolutePath())){
            qCritical()<<"Can't make server directory. File"<<server_path.absolutePath()<<"exists already.";
            abort();
        }
        if (!server_path.mkdir(dir_name)){
            qCritical()<<"Can't make data directory"<<server_path.absolutePath()<<"for unknown reasons.";
            abort();
        }
    }
}

void JobFetcher::fetchImages(QUrl server, QString md5name, QString filename){
    //https://openqa.opensuse.org/image/f57/1ad/24708fc31b1cf9722f80bdb231.png
    server.setPath(md5name+"/"+filename+".png");

}
