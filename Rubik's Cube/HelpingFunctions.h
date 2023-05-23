#ifndef HELPING_FUNCTIONS_H
#define HELPING_FUNCTIONS_H

#include <iostream>
#include <fstream>
using namespace std;

const unsigned long maxWordSize = 1;

void PrintColor(const string &color, ostream &outputStream = cout) {
    string result(maxWordSize, ' '), strColor;
    unsigned long lengthField = result.size() + 1, step = (lengthField - color.size()) / 2;
    strColor = color;
    copy(strColor.begin(), strColor.end(), result.begin() + step);
    outputStream << result << " ";
}

int setRGBColor(const string &color) {
    int result = 0;
    if (color[0] == 'G' or color[0] == 'g') result = 0x32CD32; // Если первый символ color равен 'G' или 'g', присваиваем result значение 0x32CD32
    else if (color[0] == 'B' or color[0] == 'b') result = 0x0000FF; // Если первый символ color равен 'B' или 'b', присваиваем result значение 0x0000FF
    else if (color[0] == 'Y' or color[0] == 'y') result = 0xFFD700; // Если первый символ color равен 'Y' или 'y', присваиваем result значение 0xFFD700
    else if (color[0] == 'W' or color[0] == 'w') result = 0xFFFFFF; // Если первый символ color равен 'W' или 'w', присваиваем result значение 0xFFFFFF
    else if (color[0] == 'O' or color[0] == 'o') result = 0xFF8C00; // Если первый символ color равен 'O' или 'o', присваиваем result значение 0xFF8C00
    else if (color[0] == 'R' or color[0] == 'r') result = 0xFF0000; // Если первый символ color равен 'R' или 'r', присваиваем result значение 0xFF0000
    return result;
}

#endif /* HELPING_FUNCTIONS_H */
