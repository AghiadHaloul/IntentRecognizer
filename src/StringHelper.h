//
// Created by Aghiad Haloul on 24.01.22.
//

#ifndef INTENTRECOGNIZER_STRINGHELPER_H
#define INTENTRECOGNIZER_STRINGHELPER_H

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class StringHelper {
public:
    StringHelper();
    static void string_to_words_vec(const string& input, vector<string>& words_vec);
    static void words_vec_to_string(const vector<string>& words_vec, string& merged, bool capitalize = false);
    static string capitalize_first_char(const string& str);
private:

};


#endif //INTENTRECOGNIZER_STRINGHELPER_H
