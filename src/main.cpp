#include "TextAnalyser.h"
#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

int square_fun(int n) {
    return n * n;
}

/*TEST(test_suite_name, test_name) {
    EXPECT_EQ(square_fun(2), 4);
}*/

int main(int argc, char **argv) {
    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
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
