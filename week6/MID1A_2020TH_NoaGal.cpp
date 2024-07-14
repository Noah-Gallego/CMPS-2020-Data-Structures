#include <iostream>

using namespace std;

class Encoder {
    public:
        virtual string convert(string input) = 0;
};

class WeakEncoder : public Encoder {
    public:
        string convert(string input) {
            for (int i = 0; i < input.length(); i++) {
                switch(tolower(input[i])) {
                    case 'a':
                        input[i] = '@';
                        break;
                    case 'e':
                        input[i] = '#';
                        break;
                    case 'i':
                        input[i] = '!';
                        break;
                    case 'o':
                        input[i] = '*';
                        break;
                    case 'u':
                        input[i] = '?';
                        break;
                    default:
                        break;
                }
            }

            return input;
        }
};

class StrongEncoder : public Encoder {
    public:
        string groupings[9] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
        string convert(string input) {
            // WEAK ENCODING
            for (int i = 0; i < input.length(); i++) {
                switch(tolower(input[i])) {
                    case 'a':
                        input[i] = '@';
                        break;
                    case 'e':
                        input[i] = '#';
                        break;
                    case 'i':
                        input[i] = '!';
                        break;
                    case 'o':
                        input[i] = '*';
                        break;
                    case 'u':
                        input[i] = '?';
                        break;
                    default:
                        break;
                }
            }
            
            // STRONG(ER) ENCODING
            for (int i = 0; i < input.length(); i++) {
                if (isalpha(input[i])) {
                    for (int j = 0; j < 9; j++) {
                        if (groupings[j].find(toupper(input[i])) != string::npos) {
                            input[i] = '0' + j + 2;
                            break;
                        }
                    }
                }
            }

            return input;
        }
};

int main() {
    Encoder *e = new WeakEncoder;
    cout << e->convert("arsenious") << endl;
    delete e;

    e = new StrongEncoder;
    cout << e->convert("arsenious") << endl;
    delete e;

    return 0;
}