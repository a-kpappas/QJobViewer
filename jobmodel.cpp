#include "jobmodel.h"
#include <QNetworkAccessManager>
#include <QJsonValue>
#include <QJsonArray>
JobModel::JobModel(QObject *parent)
    : QObject{parent}
{
    settingsModel = new SettingsTabModel(this);
}
void JobModel::load(QJsonObject json)
{
    auto root = json.value("job").toVariant().toMap();
    auto settings = root["settings"].toMap();
    qDebug()<<settings;
    settingsModel->load(settings);
//    for (auto iter = test.begin(); iter!=test.end(); ++iter) {
//        qDebug() << '[' << iter.key() << "] = " << iter.value().toString()<< "; ";
//    }

}

SettingsTabModel::SettingsTabModel(QObject *parent)
    : QAbstractTableModel{parent}
{}

//SettingsTabModel::SettingsTabModel(const QMap<QString, QString> list, QObject *parent)
//    : QAbstractTableModel{parent}
//{
//    m_list = list;
//}

void SettingsTabModel::load(const QVariantMap& map)
{
    beginResetModel();
    m_list.clear();
    for (QVariantMap::ConstIterator it = map.cbegin();it!=map.cend();++it){
        m_list.push_back(std::make_pair(it.key(),it.value().toString()));
    }
//    for (std::size_t i = 0; i<m_list.size();++i){
//        auto first = createIndex( i,0);
//        emit this->dataChanged(first,first,{Qt::DisplayRole});
//        auto second = createIndex(i,1);
//        emit this->dataChanged(second,second,{Qt::DisplayRole});
//        //emit this->dataChanged()
//    }
//    emit this->dataChanged(QModelIndex(),QModelIndex());
    endResetModel();
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


