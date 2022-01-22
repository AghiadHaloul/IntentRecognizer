//
// Created by Aghiad Haloul on 22.01.22.
//

#ifndef INTENTRECOGNIZER_TEXTANALYSER_H
#define INTENTRECOGNIZER_TEXTANALYSER_H

#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;
class TextAnalyser {
public:
    TextAnalyser();
    unordered_map<string,string>get_attributes(const string& input);
    string clean(const string& input);
private:
    unordered_set<string> topics_list;
    unordered_set<string> locations_list;
    unordered_set<string> times_list;
};


#endif //INTENTRECOGNIZER_TEXTANALYSER_H
