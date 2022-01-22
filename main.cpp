#include "TextAnalyser.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    cout << "Welcome to the intent recognition tool.\nEnter a sentence to predict its intent (Type in '-1' at anytime to exit):\n";
    TextAnalyser txt_analyser;
    string input;
    vector<string> examples {
            "What is the weather like today?",
            "What is the weather like in Paris today?",
            "Tell me an interesting fact.",
            // TODO: create a map of first_word -> list of cities_beginning_with_this_word
            "Whats the weather tomorrow in Clausthal-Zellerfeld?"
    };
    for (auto& ex : examples) {
        cout << ex << endl;
        input = txt_analyser.clean(ex);
        unordered_map<string, string> attr = txt_analyser.get_attributes(input);
        for (auto&[key, val]: attr) {
            cout << key << " -> " << val << endl;
        }
        cout << "----------\n";
    }
    while(getline(cin, input)) {
        if (input == "-1") {
            cout << "-1 was entered. Exiting the tool.";
            return 0;
        }
        input = txt_analyser.clean(input);
        unordered_map<string, string> attr = txt_analyser.get_attributes(input);
        for (auto& [key,val] : attr) {
            cout << key << " -> " << val << endl;
        }
    }
    return 0;
}
