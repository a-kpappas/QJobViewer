#ifndef JOBMODEL_H
#define JOBMODEL_H

#include <QObject>
#include <QFile>
#include <QAbstractTableModel>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>

class JobModel : public QObject
{
    Q_OBJECT

public:
    explicit JobModel(QObject *parent = nullptr);

signals:
private:
    void load(QJsonObject *json);
};

class SettingsTabModel: public QAbstractTableModel{
    Q_OBJECT

public:
    explicit SettingsTabModel(QObject *parent = nullptr);
    SettingsTabModel(const QList<std::pair<QString,QString>> list, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
private:
    QList<QPair<QString,QString>> m_list;
};

#endif // JOBMODEL_H
