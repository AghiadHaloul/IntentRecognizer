#include <iostream>
#include <string>

using namespace std;


int main() {
    cout << "Welcome to the intent recognition tool.\nEnter a sentence to predict its intent (Type in '-1' at anytime to exit):\n";
    string input;
    cin >> input;
    if (input == "-1") {
        cout << "-1 was entered. Exiting the tool.";
        return 0;
    }

    return 0;
}
