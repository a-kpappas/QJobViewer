#ifndef TESTRESULTMODEL_H
#define TESTRESULTMODEL_H

#include <QAbstractItemModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <resultsitem.h>

class TestresultsModel : public QAbstractTableModel
{
    Q_OBJECT
    std::vector<ResultsItem> testresults;

public:
    explicit TestresultsModel(QObject *parent = nullptr);
    void loadData(const QJsonArray &data);

    // Obligatory implementation of virtual functions
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
signals:

};

#endif // TESTRESULTMODEL_H
