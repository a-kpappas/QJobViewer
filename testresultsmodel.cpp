#include "testresultsmodel.h"

TestresultsModel::TestresultsModel(QObject *parent)
    : QAbstractItemModel{parent}
{
}


void TestresultsModel::loadData(const QJsonArray& data){
    beginResetModel();
    for (const auto& i: data){
        testresults.emplace_back(i.toObject());
    }
    endResetModel();
}
