//
// Created by Aghiad Haloul on 24.01.22.
//

#include "StringHelper.h"

void StringHelper::string_to_words_vec(const string &input, vector<string> &words_vec) {
    // Convert an input string into a vector of words
    istringstream ss(input);
    string tmp_word;
    while(getline(ss, tmp_word, ' ')) {
        words_vec.push_back(tmp_word);
    }
}

void StringHelper::words_vec_to_string(const vector<string> &words_vec, string &merged, bool capitalize) {
    for (int k = 0; k < words_vec.size(); k++) {
        string str = words_vec[k];
        if (capitalize) {
            str = StringHelper::capitalize_first_char(str);
        }
        merged += str;
        if (k < words_vec.size() - 1) {
            merged += ' ';
        }
    }
}

string StringHelper::capitalize_first_char(const string &str) {
    if (str == "") {
        return "";
    }
    string tmp = str;
    tmp[0] = toupper(tmp[0]);
    return tmp;
}
