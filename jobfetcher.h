#ifndef JOBFETCHER_H
#define JOBFETCHER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>

class JobFetcher : public QNetworkAccessManager
{
    Q_OBJECT
public:
    explicit JobFetcher(QObject *parent = nullptr);
    QJsonObject getJson(int job);
    QJsonObject getJson(QUrl job);
    void createServerDir(QUrl url);
signals:


private:
    QByteArray queryServer(QUrl job);
};

#endif // JOBFETCHER_H
