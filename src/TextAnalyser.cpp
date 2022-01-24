//
// Created by Aghiad Haloul on 22.01.22.
//

#include "TextAnalyser.h"
#include <sstream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

unordered_map<string, string> TextAnalyser::get_attributes(const string& input) {
    unordered_map<string, string> attributes;
    vector<string> words_vec;
    StringHelper::string_to_words_vec(input, words_vec);
    for (int i = 0; i < words_vec.size(); i++) {
        string w = words_vec[i];
        // Skip, if the word is in the stop words list
        if (stop_words.find(w) != stop_words.end()) {
            continue;
        }
        // Check if the word is a topic:
        if (topics_list.find(w) != topics_list.end()) {
            attributes["topic"] = w;
            continue;
        }
        // Check if the word is a time
        if (times_list.find(w) != times_list.end()) {
            attributes["time"] = w;
            continue;
        }
        // Check if the word is a location
        if (attributes.find("location") == attributes.end() &&
            multiword_locations_list.find(w) != multiword_locations_list.end()) {
            // The word _might_ be a first part of a multi-word location
            int longest_name_found = -1;
            for (auto& potential_match : multiword_locations_list[w]) {
                int potential_len = potential_match.size();
                // Only compare if the possible name is longer than what we found so far
                if (potential_len < longest_name_found) {
                    continue;
                }
                // Skip candidate if longer than input
                if (i + potential_len > words_vec.size()){
                    continue;
                }
                // Compare if the next n words in input match the candidate name
                vector<string> sub_vector(words_vec.begin() + i, words_vec.begin() + i + potential_len);
                if (sub_vector == potential_match) {
                    // Re-concatenate the location_words
                    string merged = "";
                    StringHelper::words_vec_to_string(potential_match, merged, true);
                    attributes["location"] = merged;
                    longest_name_found = potential_match.size();
                }
            }
        }
        // if no location is set, check if the word itself is a location.
        if (attributes.find("location") == attributes.end() && locations_list.find(w) != locations_list.end()) {
            attributes["location"] = w;
            continue;
        }
    }
    return attributes;
}

TextAnalyser::TextAnalyser() {
    topics_list = {"weather", "fact", "directions", "reminder", "joke"}; // Can be read & extended from a file.
    times_list = {"today", "now", "tomorrow", "o'clock", "Uhr"}; // Can be read & extended from a file.

    // Load cities from file
    fstream file_stream("../data/opendatasoft/names_coordinates.csv");
    if (!file_stream.is_open()) {
        throw runtime_error("Could not open cities_list file.");
    }
    string line, word;
    // Iterate through the lines in the CSV file
    while(getline(file_stream, line)) {
        stringstream s_str(line);
        vector<string> csv_line;
        while(getline(s_str, word, ';')) {
            csv_line.push_back(word);
        }

        // Clean the city names (Clausthal-Zellerfeld -> "Clausthal Zellerfeld")
        string city_ascii = clean(csv_line[0]);
        locations_list.insert(city_ascii);

        // If the city name has multiple words, group them by the first one
        // to check which location the user means. For example;
        // "San" -> {{"San", "Francisco"}, {"San", "Diego"}, {"San", "Jose", "del", "Monte"}}
        vector<string> city_name_vec;
        StringHelper::string_to_words_vec(city_ascii, city_name_vec);
        if (city_name_vec.size() > 1) {
            string first_word = city_name_vec[0];
            multiword_locations_list[first_word].push_back(city_name_vec);
        }
    }
    file_stream.close();

    // Load stop words from file:
    file_stream.open("../data/stopwords/stop_words_en.txt");
    if (!file_stream.is_open()) {
        throw runtime_error("Could not open stop_words_en.txt file.");
    }
    while(getline(file_stream, line)) {
        stop_words.insert(line);
    }
    file_stream.close();
}

string TextAnalyser::clean(const string &input) {
    string cleaned_str = "";
    for (int i = 0; i < input.size(); i++) {
        // Avoid repeated empty spaces
        if(input[i] == ' ' && cleaned_str.size() > 0 && cleaned_str[cleaned_str.size() - 1] != ' ') {
            cleaned_str += ' ';
            continue;
        }
        // Ignore non-alphanumeric digits
        if(!isalnum(input[i])) {
            // avoid double white spaces
            if (cleaned_str.size() > 0 && cleaned_str[cleaned_str.size() - 1] != ' ') {
                cleaned_str += ' ';
            }
            continue;
        }
        // Convert to lower letters
        if (isupper(input[i])) {
            cleaned_str += tolower(input[i]);
            continue;
        }
        cleaned_str += input[i];
    }
    return cleaned_str;
}


