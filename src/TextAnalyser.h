//
// Created by Aghiad Haloul on 22.01.22.
//

#ifndef INTENTRECOGNIZER_TEXTANALYSER_H
#define INTENTRECOGNIZER_TEXTANALYSER_H

#include "StringHelper.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map>
#include <vector>

using namespace std;

class TextAnalyser {
public:
    TextAnalyser();
    unordered_map<string,string>get_attributes(const string& input);
private:
    unordered_set<string> topics_list;
    unordered_set<string> times_list;
    unordered_set<string> stop_words;
    unordered_set<string> locations_list;
    unordered_map<string, vector<vector<string>>> multiword_locations_list;
    void load_from_file(const string& path_to_file, unordered_set<string>& list);

};


#endif //INTENTRECOGNIZER_TEXTANALYSER_H
