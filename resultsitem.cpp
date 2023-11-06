#include "resultsitem.h"

ResultsItem::ResultsItem()
{

}

ResultsItem::ResultsItem(const QJsonObject &result_data)

{
    always_rollback = result_data["always_rollback"].toBool();
    category = result_data["category"].toString();
    details = result_data["details"].toObject();
    execution_time = result_data["execution_time"].toString();
    fatal = result_data["fatal"].toBool();
    has_parser_text_result = result_data["has_parser_text_result"].toBool();
    milestone = result_data["milestone"].toBool();
    name = result_data["name"].toString();
    testresult = result_data["testresult"].toString();
}

