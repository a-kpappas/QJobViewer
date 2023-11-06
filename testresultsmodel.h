#ifndef TESTRESULTMODEL_H
#define TESTRESULTMODEL_H

#include <QAbstractItemModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <resultsitem.h>

class TestresultsModel : public QAbstractItemModel
{
    Q_OBJECT
    std::vector<ResultsItem> testresults;

public:
    explicit TestresultsModel(QObject *parent = nullptr);
    void loadData(const QJsonArray &data);
signals:

};

#endif // TESTRESULTMODEL_H
