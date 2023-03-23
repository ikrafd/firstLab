#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

void enterDataInFileStr(ofstream &outputFile, const string& fileNameInput); //запис даних у файл для першого методу
void readStringFromFile(ifstream &fileWithData, ofstream &outputFile,const string &outFile, const string &fileNameInput); //зчитування та обробка рядка з файлу
int findSmallStr(string numStr); //пошук найменшого значення у рядку
void shiftElementStr(string& str, int n); //запис чисел у зворотньому порядку
void enterDataInOutputFile(ofstream &outputFile,const string &outFile, string str); //заповнення вихідного файлу
void outputFileStr(ifstream &fileWithData, ofstream &outputFile,const string &outFile, const string &fileNameInput);//вивід вхідного та вихідного файлів