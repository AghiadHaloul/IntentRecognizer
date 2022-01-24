#include "IntentRecognizer.h"
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
    vector<string> examples {
            "What is the weather like today?",
            "What is the weather like in Paris today?",
            "Tell me an interesting fact.",
            "Whats the weather tomorrow in Clausthal-Zellerfeld?"
    };
    IntentRecognizer ir;
    for (auto& ex : examples) {
        cout << ex << endl;
        cout << ir.get_intent(ex);
    }
    string input;
    while(getline(cin, input)) {
        if (input == "-1") {
            cout << "-1 was entered. Exiting the tool.";
            return 0;
        }
        cout << ir.get_intent(input);
    }
    return 0;
}
