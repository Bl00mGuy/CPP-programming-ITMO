#include "Cube/RubikCube.h"
#include "Cube/VisualFunctions.h"
#include "Other/GLUTMenu.h"
#include <glut.h>

extern RubikCube Cube;

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Инициализируем генератор случайных чисел
    glutInit(&argc, argv); // Инициализируем библиотеку GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Устанавливаем параметры дисплея
    glutInitWindowSize(640, 640); // Устанавливаем размер окна
    glutInitWindowPosition(1, 1); // Устанавливаем позицию окна на экране
    glutCreateWindow("CUBE window"); // Создаем окно с заголовком "Rubik's Cube"
    init(); // Вызываем функцию инициализации
    glutDisplayFunc(display); // Устанавливаем функцию для отображения графики
    glutReshapeFunc(reshape); // Устанавливаем функцию для изменения размеров окна
    glutTimerFunc(5, timer, 0); // Устанавливаем функцию-таймер с интервалом в 5 миллисекунд
    glutSpecialFunc(specialKeys); // Устанавливаем функцию для обработки специальных клавиш
    createGLUTMenus(); // Создаем меню
    glutMainLoop(); // Запуск главного цикла обработки запросов
    return 0;
}
