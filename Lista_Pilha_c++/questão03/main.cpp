#include <iostream>
#include <string>

using namespace std;

string reverterString(const string& input) {
    string invertido;
    for (int i = input.length() - 1; i >= 0; i--) {
        invertido += input[i];
    }
    return invertido;
}

int main() {
    string inputString = "Pericles";
    string invertido = reverterString(inputString);

    cout << "String original: " << inputString << endl;
    cout << "String revertida: " << invertido << endl;

    return 0;
}

