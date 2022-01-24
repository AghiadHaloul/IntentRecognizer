//
// Created by Aghiad Haloul on 24.01.22.
//

#include "IntentRecognizer.h"
#include <iostream>

IntentRecognizer::IntentRecognizer() {
    TextAnalyser text_analyser;
}

string IntentRecognizer::get_intent(const string& query) {
    string input = text_analyser.clean(query);
    map<string, string> attr = text_analyser.get_attributes(input);
    string intent = "";
    for (auto&[key, val]: attr) {
        intent += " ";
        if (key == "location") {
            intent += "City [" + val + "]";
        }
        if (key == "topic") {
            // TODO move to a string manipulator class
            string tmp = val;
            if (tmp.size() > 0) {
                tmp[0] = toupper(tmp[0]);
            }
            intent += tmp;
        }
        cout << key << " -> " << val << endl;
    }
    cout << "----------\n";
    if (intent == "") {
        cout << "No intent was detected in the string.\n";
    }
    return "(Intent: Get" + intent + ")\n";
}
