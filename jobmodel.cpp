#include "jobmodel.h"
#include <QNetworkAccessManager>
#include <QJsonValue>
#include <QJsonArray>
JobModel::JobModel(QObject *parent)
    : QObject{parent}
{
}
void JobModel::load(QJsonObject json)
{
    QVariantMap map;
    qDebug()<<json.keys();
    auto root = json.value("job");
    auto bracket = json.value("job").toObject()["settings"];
    auto arr = bracket.toArray();
    auto val = bracket.toVariant();
    auto variant = json.toVariantMap();
    auto var = variant["job"].toMap()["settings"];
    auto test = var.toMap();
    for (auto iter = test.begin(); iter!=test.end(); ++iter) {
        qDebug() << '[' << iter.key() << "] = " << iter.value().toString()<< "; ";
    }
    for(;;){
        qDebug()<< val;
    }
}

SettingsTabModel::SettingsTabModel(QObject *parent)
    : QAbstractTableModel{parent}
{}

SettingsTabModel::SettingsTabModel(const QList<std::pair<QString, QString>> list, QObject *parent)
    : QAbstractTableModel{parent}
{
    m_list = list;
}

int SettingsTabModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : m_list.size();
}

int SettingsTabModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 2;
}

QVariant SettingsTabModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_list.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        auto row = m_list.at(index.row());

        switch (index.column()) {
        case 0:
            return row.first;
        case 1:
            return row.second;
        default:
            break;
        }
    }
    return QVariant();
}

QVariant SettingsTabModel::headerData(int section, Qt::Orientation orientation, int role) const
{  
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Variable");
        case 1:
            return tr("Value");
        default:
            break;
        }
    }
    return QVariant();
}


