//
// Created by Aghiad Haloul on 24.01.22.
//

#ifndef INTENTRECOGNIZER_INTENTRECOGNIZER_H
#define INTENTRECOGNIZER_INTENTRECOGNIZER_H
#include "TextAnalyser.h"
#include "StringHelper.h"

class IntentRecognizer {
public:
    IntentRecognizer();
    string get_intent(const string& query);
private:
    TextAnalyser text_analyser;

};


#endif //INTENTRECOGNIZER_INTENTRECOGNIZER_H
