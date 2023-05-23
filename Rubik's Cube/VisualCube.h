#ifndef visualCube_h
#define visualCube_h

#include "CubeSettings.h"

// Цвета
unsigned int colors[6] = { green, blue, yellow, white, orange, red };

class VisualCube {
    private:
        // Этот массив используется для передачи компонентов цвета
        // в функцию glColor3ubv, которая устанавливает текущий цвет
        // рисования для отображения грани куба определенным цветом. (RGB)
        unsigned char RGBColor[3];

    public:
        int color[6]; // Массив цветов граний куба
        GLfloat visualSize; // Размер отображаемого куба

        // Функция для поворота цветов куба по часовой стрелке на 90 градусов
        void rotateORb() {
            int temp = color[5];
            color[5] = color[3];
            color[3] = color[4];
            color[4] = color[2];
            color[2] = temp;
        }

        // Функция для поворота цветов куба по часовой стрелке на 180 градусов
        void rotateRR() {
            int temp = color[5];
            color[5] = color[3];
            color[3] = color[4];
            color[4] = color[2];
            color[2] = temp;
        }

        // Функция для поворота цветов куба по часовой стрелке на 270 градусов
        void rotateGR() {
            int temp = color[2];
            color[2] = color[1];
            color[1] = color[3];
            color[3] = color[0];
            color[0] = temp;
        }

        // Функция для поворота цветов куба против часовой стрелки на 90 градусов
        void rotateGD() {
            int temp = color[0];
            color[0] = color[4];
            color[4] = color[1];
            color[1] = color[5];
            color[5] = temp;
        }

        // Функция для поворота цветов куба против часовой стрелки на 180 градусов
        void rotateGU() {
            int temp = color[0];
            color[0] = color[4];
            color[4] = color[1];
            color[1] = color[5];
            color[5] = temp;
        }

        // Установка цвета для определенной стороны куба
        void setColor(int i, int color) { this->color[i] = color; }

        // Преобразование цвета из формата 0xFF0000 в формат RGB - разделение цвета[i] на 3 компонента (R, G, B)
        unsigned char* getRGB(int i) {
            RGBColor[0] = color[i] >> 16;
            RGBColor[1] = color[i] >> 8;
            RGBColor[2] = color[i];
            return RGBColor;
        }

        /*** Отображение куба ***/
        // Установка цветов и векторов нормали
        void draw() {
            glPushMatrix();  // Сохраняем текущую матрицу просмотра в стеке
            glBegin(GL_QUADS);  // Начинаем определение вершин для рисования четырехугольников

            // Верх
            glColor3ubv(getRGB(0));  // Устанавливаем цвет вершин в формате RGB
            glNormal3f(0, 0, 1);  // Устанавливаем нормаль (вектор перпендикулярен плоскости)
            glVertex3f(visualSize, visualSize, visualSize);  // Указываем координаты вершины (x, y, z)
            glVertex3f(0, visualSize, visualSize);  // Указываем координаты вершины (x, y, z)
            glVertex3f(0, 0, visualSize);  // Указываем координаты вершины (x, y, z)
            glVertex3f(visualSize, 0, visualSize);  // Указываем координаты вершины (x, y, z)

            // Низ
            glColor3ubv(getRGB(1));
            glNormal3f(0, 0, -1);
            glVertex3f(visualSize, 0, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(0, visualSize, 0);
            glVertex3f(visualSize, visualSize, 0);

            // Перед
            glColor3ubv(getRGB(2));
            glNormal3f(0, -1, 0);
            glVertex3f(visualSize, 0, visualSize);
            glVertex3f(0, 0, visualSize);
            glVertex3f(0, 0, 0);
            glVertex3f(visualSize, 0, 0);

            // Зад
            glColor3ubv(getRGB(3));
            glNormal3f(0, 1, 0);
            glVertex3f(visualSize, visualSize, 0);
            glVertex3f(0, visualSize, 0);
            glVertex3f(0, visualSize, visualSize);
            glVertex3f(visualSize, visualSize, visualSize);

            // Лево
            glColor3ubv(getRGB(4));
            glNormal3f(-1, 0, 0);
            glVertex3f(0, visualSize, visualSize);
            glVertex3f(0, visualSize, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 0, visualSize);

            // Право
            glColor3ubv(getRGB(5));
            glNormal3f(1, 0, 0);
            glVertex3f(visualSize, visualSize, 0);
            glVertex3f(visualSize, visualSize, visualSize);
            glVertex3f(visualSize, 0, visualSize);
            glVertex3f(visualSize, 0, 0);

            glEnd();
            glPopMatrix();
        }

        // Отображение куба с смещением по (x, y, z)
        void draw(double x, double y, double z) {
            glPushMatrix();
            glTranslated(x, y, z);
            draw();
            glPopMatrix();
        }

};

#endif /* visualCube_h */
