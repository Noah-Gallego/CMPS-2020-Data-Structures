#include <iostream>
#include <fstream>
#include <iomanip>
#include <iterator>

using namespace std;

struct CountyInfo {
    string name;
    double infections;
};

class CoronaData {
    protected:
        CountyInfo data[5];
    public:
        CoronaData() {
            // hard-coded data. Could load from any source.
            data[0].name = "Los Angeles";
            data[0].infections = 255000;
            data[1].name = "Riverside";
            data[1].infections = 55766;
            data[2].name = "Orange";
            data[2].infections = 52166;
            data[3].name = "San Bernardino";
            data[3].infections = 50709;
            data[4].name = "San Diego";
            data[4].infections = 42950;
        }

        virtual void saveToFile(string fileName) = 0;
};

class CoronaDataJson : public CoronaData {  
    void saveToFile(string fileName) {
        ofstream jsonFile;
        jsonFile.open(fileName);
        
        if (jsonFile.is_open()) {
            jsonFile << "{\n    \"data\" : [\n"; 
            for (int i = 0; i < size(data); i++) {
                jsonFile << "\t" << "{ \"name\" : \"" << data[i].name << "\", \"infections\" : \"" << std::fixed << std::setprecision(4) << data[i].infections << "\" }";
                if (i < 4) jsonFile << ","; 
                jsonFile << "\n";
            }

            jsonFile << "    ]\n}\n";
            jsonFile.close();
        }  else {
            cout << "Unable to open file :_(" << endl;
        }
    }
};

class CoronaDataCSV : public CoronaData {
    void saveToFile(string fileName) {
        ofstream csvFile;
        csvFile.open(fileName);

        if (csvFile.is_open()) {
            csvFile << "County, Infections\n";
        
            for (int i = 0; i < size(data); i++) {
                csvFile << "\"" << data[i].name << "\", " << data[i].infections << "\n";
            }

        } else {
            cout << "Unable to open file :_(" << endl;
        }

        csvFile.close();
    }
};

void save(CoronaData *cd, string filename) {
    cd->saveToFile(filename);
    cout << "File is ready." << endl;
}

int main() {
    CoronaData *cData;
    char input;
    
    cout << "Would you like the data formatted as a CSV 'C' or a JSON 'J' file? (C/J): "; 
    cin >> input;

    switch(tolower(input)) {
        case 'j':
            cData = new CoronaDataJson;
            save(cData, "JSON_Corona_Data");
            break;
        case 'c':
            cData = new CoronaDataCSV;
            save(cData, "CSV_Corona_Data");
            break;
        default:
            cout << "CSV nor JSON file selected." << endl;
            break;
    }

    delete cData;
}