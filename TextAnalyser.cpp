//
// Created by Aghiad Haloul on 22.01.22.
//

#include "TextAnalyser.h"
#include <sstream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

unordered_map<string, string> TextAnalyser::get_attributes(const string& input) {
    // Convert the input into a vector of words
    istringstream ss(input);
    string tmp_word;
    vector<string> words_vec;
    unordered_map<string, string> attributes;
    while(getline(ss, tmp_word, ' ')) {
        words_vec.push_back(tmp_word);
    }
    for (auto w : words_vec) {
        // Check if the word is a topic:
        if (topics_list.find(w) != topics_list.end()) {
            attributes["topic"] = w;
            continue;
        }
        // Check if the word is a location
        if (locations_list.find(w) != locations_list.end()) {
            attributes["location"] = w;
            continue;
        }
        // Check if the word is a time
        if (times_list.find(w) != times_list.end()) {
            attributes["time"] = w;
            continue;
        }
    }
    return attributes;
}

TextAnalyser::TextAnalyser() {
    topics_list = {"weather", "fact", "directions", "reminder"}; // Can be extended here.
    times_list = {"today", "now", "tomorrow", "o'clock", "Uhr"}; // Can be extended here.
    // locations_list will be populated from a file.
    // License: CC BY 4.0
    // Dataset Identifier: geonames-all-cities-with-a-population-1000@public
    fstream file_stream("data/opendatasoft/names_coordinates.csv");
    if (!file_stream.is_open()) {
        throw runtime_error("Could not open cities_list file.");
    }
    string line, word;
    while(getline(file_stream, line)) {
        stringstream str(line);
        vector<string> csv_line;
        while(getline(str, word, ';')) {
            csv_line.push_back(word);
        }
        locations_list.insert(csv_line[0]);
    }
}
