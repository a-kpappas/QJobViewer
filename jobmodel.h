#ifndef JOBMODEL_H
#define JOBMODEL_H

#include <QObject>
#include <QFile>
#include <QAbstractTableModel>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>

class SettingsTabModel: public QAbstractTableModel{
    Q_OBJECT

public:
    explicit SettingsTabModel(QObject *parent = nullptr);
    //SettingsTabModel(const QMap<QString,QString> list, QObject *parent = nullptr);

    void load(const QVariantMap& map);

    // Required by interface
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
private:
    std::vector<std::pair<QString,QString>> m_list;
};


class InfoModel: public QAbstractListModel{
    Q_OBJECT

    explicit InfoModel(QObject *parent = nullptr);
    void load(const QVariant& map);
};

class JobModel : public QObject
{
    Q_OBJECT

public:
    explicit JobModel(QObject *parent = nullptr);
    SettingsTabModel *settingsModel;
public slots:
    void load(QJsonObject json);

signals:

private:
};



#endif // JOBMODEL_H
