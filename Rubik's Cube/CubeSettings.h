#ifndef visualSettings_h
#define visualSettings_h
#define GL_SILENCE_DEPRECATION
#define GLEW_STATIC // Определение, что используется статическая библиотека GLEW
#include <glut.h>

ifstream inputStream("input.txt"); // Открытие файла для чтения
ofstream outputStream("output.txt"); // Открытие файла для записи

enum cubeColors { // Определение перечисления цветов кубика Рубика
    yellow = 0xFFD700,
    blue = 0x0000FF,
    green = 0x32CD32,
    red = 0xFF0000,
    orange = 0xFF8C00,
    white = 0xFFFFFF
};

const int ROTATE_SPEED_STEP = 10, ROTATE_START_VALUE = 30; // Константы для вращения кубика Рубика
GLfloat CUBE_SIZE = 12; // Размер кубика Рубика

// Проекция угла поворота на ось
int xRot = 25, yRot = -45;

// Перемещение по оси Z
GLfloat translateZ = -35;

#endif /* visualSettings_h */ 
