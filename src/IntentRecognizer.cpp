//
// Created by Aghiad Haloul on 24.01.22.
//

#include "IntentRecognizer.h"
#include <iostream>

IntentRecognizer::IntentRecognizer() {
    TextAnalyser text_analyser;
}

string IntentRecognizer::get_intent(const string& query) {
    string input = StringHelper::clean(query);
    unordered_map<string, string> attr = text_analyser.get_attributes(input);
    // Next, simply iterating over attr would suffice, but this will maintain the coding challenge output order
    vector<string> keywords = {"topic", "location", "time", "destination"};
    string intent = "";
    for (auto& keyword : keywords) {
        if (attr.find(keyword) == attr.end()) {
            continue;
        }
        intent += " ";
        if (keyword == "topic") {
            intent += StringHelper::capitalize_first_char(attr[keyword]);
        } else if (keyword == "location") {
            intent += "City";
        }else if (keyword == "time") {
            intent += "[Optionally: Time]";
        }
        // Not implemented, but an example for extending the extracted attributes.
        else if (keyword == "directions") {
            intent += "[Optionally: Destination]";
        }
    }
    if (attr.find("topic") == attr.end() || intent == "") {
        return "No intent was detected in the string.";
    }
    return "(Intent: Get" + intent + ")";
}
