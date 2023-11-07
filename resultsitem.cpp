#include "resultsitem.h"
#include <set>
bool ResultsItem::getAlways_rollback() const
{
    return always_rollback;
}

QString ResultsItem::getCategory() const
{
    return category;
}

QJsonObject ResultsItem::getDetails() const
{
    return details;
}

QString ResultsItem::getExecution_time() const
{
    return execution_time;
}

bool ResultsItem::getFatal() const
{
    return fatal;
}

bool ResultsItem::getHas_parser_text_result() const
{
    return has_parser_text_result;
}

bool ResultsItem::getMilestone() const
{
    return milestone;
}

QString ResultsItem::getName() const
{
    return name;
}

QString ResultsItem::getTestresult() const
{
    return testresult;
}

ResultsItem::ResultsItem()
{

}

QJsonValue ValueOrDeath(const QJsonObject& jsonObject, QString key){
    if (jsonObject.value(key) == QJsonValue::Undefined){
        qFatal()<<"Aborting because key "<<key<<" was not found in json.";
    }
    return jsonObject.value(key);
}

ResultsItem::ResultsItem(const QJsonObject &result_data)
{

    always_rollback = ValueOrDeath(result_data, "always_rollback").toBool();
    details = ValueOrDeath(result_data,"details").toObject();
    execution_time = ValueOrDeath(result_data,"execution_time").toString();
    fatal = ValueOrDeath(result_data,"fatal").toBool();
    has_parser_text_result = ValueOrDeath(result_data,"has_parser_text_result").toBool();
    milestone = ValueOrDeath(result_data,"milestone").toBool();
    name = ValueOrDeath(result_data,"name").toString();
    testresult = ValueOrDeath(result_data,"result").toString();

    //category is an optional value so we won't die for it.
    category = result_data.value("category").toString();
}

