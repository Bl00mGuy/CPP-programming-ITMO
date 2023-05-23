#ifndef visualFunctions_h
#define visualFunctions_h
#pragma once

#include "RubikCube.h"

extern RubikCube Cube;

void display() {
    glPushMatrix(); // сохраняем текущую матрицу видовой модели
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищаем буферы цвета и глубины
    glColor3f(1, 0, 0); // устанавливаем цвет
    glTranslatef(0, 0, translateZ); // транслируем по осям X, Y и Z
    glRotatef(xRot, 1, 0, 0); // вращаем по оси X
    glRotatef(yRot, 0, 1, 0); // вращаем по оси Y
    glTranslatef(CUBE_SIZE / -2, CUBE_SIZE / -2, CUBE_SIZE / -2); // смещаем куб в центр координатной оси
    Cube.draw(); // отображаем куб
    glPopMatrix(); // восстанавливаем матрицу видовой модели
    glutSwapBuffers(); // смена переднего и заднего буферов
}

void init() {
    // Установка цвета фона
    glClearColor(0.36, 0.18, 0.38, 0.4);
    // Установка освещения
    float matSpecular[] = {0.3, 0.3, 0.3, 0}; // установка характеристик материала
    float diffuseLight[] = {0.2, 0.2, 0.2, 1}; // установка диффузного света
    float ambientLight[] = {0.9, 0.9, 0.9, 1}; // установка окружающего света
    glShadeModel(GL_SMOOTH); // установка режима заливки
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular); // установка цвета отражаемого света
    glMateriali(GL_FRONT, GL_SHININESS, 128); // установка коэффициента отражения света
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight); // установка диффузного света
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight); // установка окружающего света
    glEnable(GL_LIGHT0); // включение источника света
    glEnable(GL_COLOR_MATERIAL); // включение материала для цвета
    glColorMaterial(GL_FRONT, GL_AMBIENT); // выбор цвета материала
    glEnable(GL_DEPTH_TEST); // включение буфера глубины
    glEnable(GL_LIGHTING); // включение освещения

    // Инициализация куба
    Cube.setVisualCube(CUBE_SIZE, colors);
}

void specialKeys(int key, int, int) {
    // Обработка клавиш со стрелками для вращения объекта в разных направлениях
    if (key == GLUT_KEY_DOWN) {
        xRot -= 10;
        if (xRot >= 360)
            xRot -= 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_UP) {
        xRot += 10;
        if (xRot < 0)
            xRot += 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_RIGHT) {
        yRot -= 10;
        if (yRot >= 360)
            yRot -= 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_LEFT) {
        yRot += 10;
        if (yRot < 0)
            yRot += 360;
        glutPostRedisplay();
    }

    // Обработка клавиш 'F1'-'F6' для вращения грани кубика
    if (key == GLUT_KEY_F1) {
        Cube.RotateUpPlane('+');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F7) {
        Cube.RotateUpPlane('-');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F2) {
        Cube.RotateLeftPlane('+');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F8) {
        Cube.RotateLeftPlane('-');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F3) {
        Cube.RotateFrontPlane('+');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F9) {
        Cube.RotateFrontPlane('-');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F4) {
        Cube.RotateRightPlane('+');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F10) {
        Cube.RotateRightPlane('-');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F5) {
        Cube.RotateBackPlane('+');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F11) {
        Cube.RotateBackPlane('-');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F6) {
        Cube.RotateDownPlane('+');
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_HOME) { //Если биндить F12 он почему-то вызывает ошибку ;(
        Cube.RotateDownPlane('-');
        glutPostRedisplay();
    }
}

void timer(int) {
    glutTimerFunc(5, timer, 0);
    // Визуальное вращение выбранной грани кубика при помощи мини-машинки, если текущая грань не равна -1
    if (Cube.currentPlane != -1) {
        Cube.visualRotateMiniMachineGun(Cube.currentPlane, ROTATE_START_VALUE, -1);
    }
    display();
}

void processMenu(int action);

void reshape(int width, int height) {
    // Изменение размеров окна
    glViewport(0, 0, width, height);

    // Устанавливаем матрицу проекции
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Вычисляем соотношение сторон окна
    GLfloat fAspect = (GLfloat)width / (GLfloat)height;

    // Устанавливаем параметры перспективной проекции
    gluPerspective(60, fAspect, 1, 1000);

    // Устанавливаем матрицу моделирования-вида
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

#endif /* visualFunctions_h */
