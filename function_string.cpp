#include "function_string.h"
void shiftElementStr(string& str, int n) {
    string shiftedStr = str.substr(n % str.length()) + str.substr(0, n % str.length());

    stringstream ss(shiftedStr);
    string token;
    string result = "";
    while (ss >> token) {
        if (result == "") {
            result = token;
        } else {
            result = token + ", " + result;
        }
    }
    str = result;
}

void replaceNumberStr(string &numString, int min)
{
    int position;
    string numberF;
    istringstream number(numString);
    numberF = to_string(min);
    int longer;
    position = (int) numString.find(numberF);
    if (position >=0) {
        string num, firstNum;
        longer = (int) numberF.length();
        numString.erase(numString.begin() + position - 1, numString.begin() + position + longer);
        shiftElementStr(numString, numString.length());
        numString = numberF + ", " + numString;
    }
}

void breakingStringStr(string &str){
    void replaceNumber(string , int); //зміна порядку слідування чисел у рядку чисел
    int small=0; //найменше значення
    int spase =0; //наявність пробілу
    int num = 0;
    int count = 0; //лічильник кількості чисел у рядку

    string numStr, textStr="";
    for(int j=0; j<str.length(); j++) {
        do {
            if (isdigit(str[j])) {
                numStr += str[j];
                spase =0;
            } else if (isalpha(str[j])) {
                textStr += str[j];
                if (spase==0) {
                    numStr += " ";
                    spase=1;
                }
            } else if (isspace(str[j])) {
                numStr += " ";
                spase=1;
                if (textStr!="")
                    textStr += ", ";
            }
            j++;
        } while (j < str.length() && str[j] != '\n' && str[j] != '\0');
    }

    stringstream ss(numStr);

    while (ss >> num) {
        count++;
    }

    if (!numStr.empty()) {
        if (count >1) {
            small = findSmallStr(numStr);
            replaceNumberStr(numStr, small);
        }
    }
    if (textStr!="") {
        str = numStr + ", " + textStr;
    } else {
        str = numStr;
    }

}

void readStringFromFile(ifstream &fileWithData, ofstream &outputFile,const string &outFile, const string &fileNameInput)
{
    void breakingStringStr(string &str); // внутрішня функція розбиття рядка на числа та слова з літер
    string str = "";

    outputFile.open(outFile, ios::trunc); //очищення вмісту файлу
    outputFile.close();

    fileWithData.open (fileNameInput);
    if (fileWithData.is_open()) {
        string sa;
        while (getline(fileWithData, sa)) {
            str = sa;
            breakingStringStr(str);
            enterDataInOutputFile(outputFile,outFile, str);
        }
    } else{
        cout << "Can`t open"<<endl;
    }
    fileWithData.close();
}

int findSmallStr(string numStr) {
    istringstream iss(numStr);
    string numberFirst, workNumber;
    int firstWord=0;
    int number1, number2;
    do {

        if (firstWord==0) {
            iss >> numberFirst;
            firstWord=1;
        } else {
            iss >> workNumber;
            if (workNumber!="") {
                number1 = stoi(numberFirst);
                number2 = stoi(workNumber);
                if (number1 > number2) {
                    numberFirst = workNumber;
                }
            }
        }
    } while (iss);
    return number1;
}

void enterDataInFileStr(ofstream &outputFile, const string& fileNameInput){
    string input;
    outputFile.open(fileNameInput, ios::app);
    cout << "Enter a string:\n";
    while (input != "~") {
        fflush(stdin);
        getline(cin, input);
        if (input != "~") {
            outputFile << input << endl;
        }
    }
    outputFile.close();
}

void enterDataInOutputFile(ofstream &outputFile,const string &outFile, string str){

    outputFile.open(outFile, ios::app);
    if (outputFile.is_open()){
        outputFile << str << endl;
    } else{
        cout << "Can`t open" << endl;
    }
    outputFile.close();
}

void outputFileStr(ifstream &fileWithData, ofstream &outputFile,const string &outFile, const string &fileNameInput){
    char fileSymbol, fileSymbol2;
    fileWithData.open(fileNameInput);
    if (!fileWithData.is_open()) {
        cout << "Impossible to open the file\nfurther behavior of the program is unpredictable" << endl;
        return;
    }while (fileWithData.get(fileSymbol))
        cout << fileSymbol;
    fileWithData.close();

    fileWithData.open(outFile);
    if (!fileWithData.is_open()) {
        cout << "Impossible to open the file\nfurther behavior of the program is unpredictable" << endl;
        return;
    }while (fileWithData.get(fileSymbol2))
        cout << fileSymbol2;
    fileWithData.close();

}
