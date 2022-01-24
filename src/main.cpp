#include "IntentRecognizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <cassert>

using namespace std;


int main(int argc, char **argv) {
    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
    cout << "Welcome to the intent recognition tool.\n";
    cout << "Enter a sentence to predict its intent (Type in '-1' at anytime to exit):\n\n";
    vector<pair<string, string>> test_cases {
            {"What is the weather like today?",
             "(Intent: Get Weather Time [Hint: Today])"},

            {"What is the weather like in Paris today?",
             "(Intent: Get Weather City [Hint: Paris] Time [Hint: Today])"},

            {"Tell me an interesting fact.",
             "(Intent: Get Fact)"},

            {"Whats the weather tomorrow in Clausthal-Zellerfeld?",
             "(Intent: Get Weather City [Hint: Clausthal Zellerfeld] Time [Hint: Tomorrow])"},


            {"Directions to Frankfurt am Main",
             "(Intent: Get Directions City [Hint: Frankfurt Am Main])"},

            {"Show me the directions to Frankfurt(oder)",
             "(Intent: Get Directions City [Hint: Frankfurt Oder])"},

            {"What's the weather in Bad Lauterberg im Harz tomorrow?",
             {"(Intent: Get Weather City [Hint: Bad Lauterberg Im Harz] Time [Hint: Tomorrow])"}}
    };
    IntentRecognizer recognizer;
    for (auto& test_case : test_cases) {
        string input = test_case.first;
        string output = recognizer.get_intent(input);
        cout << input << "\n=> " << output << endl;
        assert(output == test_case.second);
        cout << "========= Test case passed! =========\n";
    }

    string input;
    while(getline(cin, input)) {
        if (input == "-1") {
            cout << "-1 was entered. Exiting the tool.";
            return 0;
        }
        cout << recognizer.get_intent(input) << endl;
    }
    return 0;
}