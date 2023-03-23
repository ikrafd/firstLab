#include "function_string.h"
#include "function_array.h"

int main(int argc, char* argv[]){

    char a;
    string fileNameInput = "example.txt"; //вхідний файл для першого методу
    string outFile = "output.txt"; //вихідний файл для першого методу
    string stt = "";
    ofstream outputFile;
    ifstream fileWithData;
    FILE *filePointer;
    char nameFile[] = "array.txt"; //вхідний файл для другого методу

    //вибір режиму роботи прогруми
    if ((argc>=3) && (strcmp(argv[2],"FileString")==0)){
        enterDataInFileStr(outputFile, fileNameInput);
        readStringFromFile(fileWithData, outputFile, outFile, fileNameInput);
        cout << "Enter something for append or * for end"<< endl;
        cin >> a;
        while (a!='*') {
            enterDataInFileStr(outputFile, fileNameInput);
            readStringFromFile(fileWithData, outputFile, outFile, fileNameInput);
            cout << "Enter something for append or * for end"<< endl;
            cin >> a;
        }
        outputFileStr(fileWithData, outputFile, outFile, fileNameInput);
    } else if ((argc>=3) && (strcmp(argv[2],"FilePointer")==0)){
        enterDataArr(filePointer, nameFile);
        readFileArr(filePointer, nameFile);
        cout << "Enter something for append or * for end"<< endl;
        cin >> a;
        while (a!='*') {
            appendFileArr(filePointer, nameFile);
            cout << "Enter something for append or * for end"<< endl;
            cin >> a;
        }
        outputFileArr(filePointer, nameFile);
    } else {
        cout<<"Not correct argument"<<endl;
    }
    system("pause");

    return 0;
}