#include "function_string.h"

void enterDataArr (FILE *fileWork, const char *fileName);//запис у вхідний файл
void readFileArr(FILE* fileWork, const char* fileName);//читання даних з файлу
void readStringArr(char* charArr);//обробка рядку з файлу як масиву
void outDataArr(int *arrayNum, char *textStrArr, int numberNum, int countAlf);//запис даних у вихідний файл
void appendFileArr(FILE* fileWork, const char* fileName);//доповнення файлу
void outputFileArr(FILE* fileWork, const char* fileName);//вивід вхідного і вихідного файлів