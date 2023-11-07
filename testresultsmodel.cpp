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
    return parent.isValid()? 0: 4;
}

QVariant TestresultsModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row()>=0 && index.row() < this->testresults.size()){
        auto i = testresults.at(index.row());

        switch (index.column()) {
        case 0:
            return i.getName();
            break;
        case 1:
            return i.getTestresult();
            break;
        case 2:
            return i.getCategory();
            break;
        case 3:
            return i.getExecution_time();
            break;
        default:
            break;
        }
    }
    return QVariant();
}


