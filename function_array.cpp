#include "function_array.h"
void enterDataArr(FILE* fileWork, const char* fileName) {
    const int bufferSize = 100;
    char* dataFile = new char[bufferSize];

    fileWork = fopen(fileName, "w");
    if (fileWork == nullptr) {
        cout << "Impossible to open the file\nfurther behavior of the program is unpredictable" << endl;
        delete[] dataFile;
        return;
    }

    bool stop = false; // зуинка вводу або помилка
    cout << "Enter a line (or '~' to finish): "<< endl;
    while (!stop) {
        if (fgets(dataFile, bufferSize, stdin) == nullptr) {
            cout << "EROR" << endl;
            stop = true;
        }
        else if (strcmp(dataFile, "~\n") == 0) {
            stop = true;
        }
        else {
            fprintf(fileWork, "%s", dataFile);
        }
    }
    fclose(fileWork);
    delete[] dataFile;
}

void readFileArr(FILE* fileWork, const char* fileName) {
    int bufferSize = 100;
    char *fileString = new char [bufferSize];
    fileWork = fopen(fileName, "r");
    if (fileWork == nullptr) {
        cout << "Impossible to open the file\n" << endl;
        return;
    } while (fgets(fileString, bufferSize, fileWork)) {
        readStringArr( fileString);
    }
    delete [] fileString;
    fclose(fileWork);
}

int findMinAr(const int* arr, int n)
{
    int min = arr[0], pos=0; // Початкове значення мінімального числа
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int shiftElement(int arr[], int n, int x) {
    int left = arr[0], i, pos = 0, temp;
// запис масиву у зворотьному орядку
    for (i = 0; i < n / 2; i++) {
        int right = arr[n - 1 - i];
        arr[n - i - 1] = left;
        arr[i] = right;
        left = arr[i + 1];
    }
// пошук індексу найменшого елменту
    while (arr[pos] != x) {
        pos++;
    }
// зсув елементів вправо
    for (pos; pos > 0; pos--) {
        arr[pos] = arr[pos - 1];
    }
    arr[0] = x;
    return (n);
}

void outDataArr(int *arrayNum, char *textStrArr, int numberNum, int countAlf){

    FILE *fileP;
    char nameFile[] = "out_array.txt";

    fileP= fopen(nameFile, "a");

    if (fileP == nullptr) {
        cout << "Impossible to open the file\nfurther behavior of the program is unpredictable" << endl;
        return;
    }

    if (textStrArr[0]!=' ') {
        for (int a = 0; a < numberNum; a++) {
            if (a!=numberNum-1) {
                fprintf(fileP, "%d, ", *(arrayNum + a));
            } else  if (a==numberNum-1){
                fprintf(fileP,"%d ",*(arrayNum + a));
            }
        }
        for (int qwert = 0; qwert <= countAlf - 1; ++qwert) {
            if (textStrArr[qwert] == ' ') {
                fprintf(fileP, ",%c", *(textStrArr + qwert));
            } else {
                fprintf(fileP, "%c",*(textStrArr + qwert));
            }
        }
    }
    fprintf(fileP, "\n");
    fclose(fileP);
}

void readStringArr(char* Arr){
    int findMinAr( const int* arr, int n);
    int numberNum=0, min=0;
    int bufferSize = strlen(Arr)+1;
    int *arrayNum = new int [bufferSize];
    char *helpArray = new char [bufferSize];
    char *numStr = new char [bufferSize];
    char *textStr = new char[bufferSize];
    int j = 0, countN=0, countAlf=0;

    do {
        if (isdigit(Arr[j])) {
            if (countN < bufferSize - 1) {
                numStr[countN] = Arr[j];
                countN ++;
                if (textStr[countAlf-1]!=' '&& countAlf!=0){
                    textStr[countAlf]= ' ';
                    countAlf++;
                }
            }
        } else if (isalpha(Arr[j])) {
            if (countAlf < bufferSize - 1) {
                textStr[countAlf] = Arr[j];
                countAlf++;
                if (numStr[countN-1]!=' ') {
                    numStr[countN] = ' ';
                    countN++;
                }

            }
        } else if (isspace(Arr[j])) {
            if ((countN < bufferSize - 1) && (numStr[countN-1]!=' ')) {
                numStr[countN] = ' ';
                countN++;
            }
            if ((countAlf < bufferSize - 1) && (textStr[countAlf-1]!=' ')) {
                textStr[countAlf] = ' ';
                countAlf++;
            }
        }
        j++;
    } while (Arr[j] != '\n' && Arr[j] != '\0');
    numStr[countN] = '\0';
    textStr[countAlf] = '\0';

    for (int d = 0; d <bufferSize; d++) {
        helpArray[d] = NULL; // перезапис кожного елемента на 0
    }

    // переведення чисел у масив
    int l=0;
    int i=0;

    while (numStr[i] != '\0') {
        if (('0' <= numStr[i]) && (numStr[i] <= '9')) {
            helpArray[l] = numStr[i];
            l++;
        } else if (i!=0&&numStr[i-1]!=' '&&numStr[i]==' ') {
            arrayNum[numberNum] = atoi(helpArray);
            numberNum++;
            for (int q=0; q<l; q++){
                helpArray[q] = NULL;
            }
            l = 0;
        }
        i++;
    }
    if (numStr[i]=='\0') {
        if (numStr[i-1]!=' ') {
            arrayNum[numberNum] = atoi(helpArray);
            numberNum++;
        }
    }

// робота з числами
    min = findMinAr(arrayNum, numberNum);
    shiftElement(arrayNum, numberNum, min);
    outDataArr(arrayNum, textStr, numberNum, countAlf);

    delete [] numStr;
    delete [] helpArray;
    delete [] textStr;
}

void appendFileArr(FILE* fileWork, const char* fileName){
    FILE *fileP;
    char nameFile[] = "out_array.txt";
    fileP = fopen(nameFile, "w");
    fclose(fileP);

    fileWork= fopen(fileName, "a");
    const int bufferSize = 100;
    char* dataFile = new char[bufferSize];

    if (fileWork == nullptr) {
        cout << "Impossible to open the file\nfurther behavior of the program is unpredictable" << endl;
        return;
    }

    bool stop = false; // зуинка вводу або помилка
    cout << "Enter a line (or '~' to finish): "<< endl;
    while (!stop) {
        if (fgets(dataFile, bufferSize, stdin) == nullptr) {
            cout << "EROR" << endl;
            stop = true;
        }
        else if (strcmp(dataFile, "~\n") == 0) {
            stop = true;
        }
        else {
            fprintf(fileWork, "%s", dataFile);
        }
    }
    fclose(fileWork);
    delete[] dataFile;
    readFileArr(fileWork, fileName);
}

void outputFileArr(FILE* fileWork, const char* fileNameStart){
    FILE *fileP;
    char nameFileEnd[] = "out_array.txt";
    char *fileString = new char [100];
    char *fileString2 =new char [100];

    fileWork = fopen(fileNameStart, "r");
    if (fileWork == nullptr) {
        cout << "Can`t open file\n" << endl;
        return;
    }
    cout << "Start file"<< endl;
    while (fgets(fileString, 100, fileWork)) {
         cout << fileString;
    }
    fclose(fileWork);
    delete [] fileString;

    fileP = fopen(nameFileEnd, "r");
    if (fileP == nullptr) {
        cout << "Impossible to open the file\n" << endl;
        return;
    }
    cout << "End file"<< endl;
    while (fgets(fileString2, 100, fileP)) {
            cout <<fileString2;
    }
    fclose(fileP);
    delete [] fileString2;
}