#ifndef RESULTSITEM_H
#define RESULTSITEM_H

#include <QString>
#include <QJsonObject>

/*
 * This class aims to model a single item of data that is shown in the json under the jobsettings hash.
 * As we are parsing the JSON we will assign the data directly to the class members.
 * I might try to map this closer to the Perl in os-autoinst but I am not sure I will ever have the time.
 * Hopefully the MVC seperation will be good enough that I will be able to change the model without changing the view too much.
 */
class ResultsItem
{
    bool always_rollback=0;
    QString category;
    QJsonObject details;     // This will be turned into a submodel. (Do submodels make any sense?)
    QString execution_time;
    bool fatal=0;
    bool has_parser_text_result=0;
    bool milestone=0;
    QString name;
    QString testresult;
public:
    explicit ResultsItem();
    ResultsItem(const QJsonObject& result_data);


signals:

};

#endif // RESULTSITEM_H
