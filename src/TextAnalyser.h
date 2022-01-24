//
// Created by Aghiad Haloul on 22.01.22.
//

#ifndef INTENTRECOGNIZER_TEXTANALYSER_H
#define INTENTRECOGNIZER_TEXTANALYSER_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map>
#include <vector>

using namespace std;

class TextAnalyser {
public:
    TextAnalyser();
    map<string,string>get_attributes(const string& input);
    string clean(const string& input);
private:
    unordered_set<string> topics_list;
    unordered_set<string> times_list;
    unordered_set<string> stop_words;
    unordered_set<string> locations_list;
    unordered_map<string, vector<vector<string>>> multiword_locations_list;
    static void string_to_words_vec(const string& input, vector<string>& words_vec);
    static void words_vec_to_string(const vector<string>& words_vec, string& merged);
};


#endif //INTENTRECOGNIZER_TEXTANALYSER_H
