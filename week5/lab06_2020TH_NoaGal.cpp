#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

class ConfigFileError : public exception {
    public: 
        const char *what() const throw() {
            return "Configuration file is badly formed";
        }
};

class ConfigFileMissingKey : ConfigFileError {
    public:
        const char *what() const throw() {
            return "Missing Key";
        }
};

class ConfigFileBadKey : ConfigFileError {
    public:
        const char *what() const throw() {
            return "Bad Key Specification";
        }
};

class ConfigFileMissingSeperator : ConfigFileError {
    public:
        const char *what() const throw() {
            return "Missing Seperator";
        }
};

class ConfigFile {
    private:
        bool containsSeperator(string line, char sep = '=') {
            return line.find(sep) >= line.length();
        }

        bool isNameValid(string name) {
            bool flag;
            if (name[0] != '=') {
                flag = (name[0] == '_' || isalpha(name[0]));
            } else {
                flag = !(name[0] == '_' || isalpha(name[0]));
            }

            // name[0] != '=' && (name[0] == '_' || isalpha(name[0]));

            return flag;
        }

        bool isComment(string line) {
            return line[0] == ';';
        }

        bool isMissingKey(string line) {
            return line[0] == '=';
        }

    public:
        bool load(string fileName) {
            string line;
            ifstream fin;

            fin.open(fileName);
            while(getline(fin, line)) {
                // TODO   
                if(isComment(line) || line == "")
                    continue;
                if(!isNameValid(line))
                    throw ConfigFileBadKey();
                if(isMissingKey(line)) 
                    throw ConfigFileMissingKey();
                if (!containsSeperator(line))
                    throw ConfigFileMissingSeperator();
            }  
            
            fin.close();
            return true; 
        }
};

int main() {
    ConfigFile config;

    try {
        if (config.load("config.ini"))
            cout << "Config file verified" << endl;
    } catch (ConfigFileMissingKey &ex) {
        cerr << ex.what() << endl;
    } catch (ConfigFileBadKey &ex) {
        cerr << ex.what() << endl;
    } catch (ConfigFileMissingSeperator &ex) {
        cerr << ex.what() << endl;
    } catch (...) {
        cerr << "Something else happened and you broke my program :(" << endl;
    }

    return 0;
}