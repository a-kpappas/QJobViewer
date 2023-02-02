#include "jobfetcher.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QRegularExpression>

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

//void JobFetcher::fetch(QUrl url){
//    QString host = url.host();
//    QRegularExpression trim_http("^(http|https)://)"
//    QRegularExpression re('(.*).(.*).(.*)');
//}
