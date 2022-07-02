#include "jobmodel.h"

JobModel::JobModel(QObject *parent)
    : QObject{parent}
{

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
