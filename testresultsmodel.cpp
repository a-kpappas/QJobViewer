#include "testresultsmodel.h"

TestresultsModel::TestresultsModel(QObject *parent)
    : QAbstractTableModel{parent}
{
}


void TestresultsModel::loadData(const QJsonArray& data){
    beginResetModel();
    qDebug()<<"Got here";

    for (const auto& i: data){
        testresults.emplace_back(i.toObject());
    }
    endResetModel();
}

int TestresultsModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid()? 0: this->testresults.size();
}

int TestresultsModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid()? 0: 3;
}

QVariant TestresultsModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row()>=0 && index.row() < this->testresults.size() && role == Qt::DisplayRole){
        auto i = testresults.at(index.row());

        switch (index.column()) {
        case 0:
            return i.getName();
        case 1:
            return i.getTestresult();
        case 2:
            return i.getExecution_time();
        default:
            break;
        }
    }
    return QVariant();
}


QVariant TestresultsModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Name");
        case 1:
            return tr("Test Result");
        case 2:
            return tr("Execution Time");
        default:
            break;
        }
    }
    return QVariant();
}

