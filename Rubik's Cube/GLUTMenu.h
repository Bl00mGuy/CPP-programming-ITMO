#include <glut.h>
#ifndef RUBIKCUBE_GLUTMENU_H
#define RUBIKCUBE_GLUTMENU_H

// Менюшка
void createGLUTMenus() {
    glutCreateMenu(processMenu);
    glutAddMenuEntry("Read Cube from file", 1);
    glutAddMenuEntry("Print Cube in console", 2);
    glutAddMenuEntry("Print Cube in file", 3);
    glutAddMenuEntry("Shuffle", 4);
    glutAddMenuEntry("Find Solution", 5);
    glutAddMenuEntry("Create solved Cube", 6);
    glutAddMenuEntry("Print solving information in console", 7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Действия
void processMenu(int action) {
    try {
        switch (action) {
            case 1:
                Cube.ReadRubikCube(inputStream);
                break;

            case 2:
                cout << "\nCube's unfolding:\n\n";
                Cube.PrintRubikCube();
                break;

            case 3:
                outputStream << "\nCube's unfolding:\n\n";
                Cube.PrintRubikCube(outputStream);
                break;

            case 4:
                Cube.Shuffle(false);
                cout << "\n\nCube's unfolding after shuffling:\n\n";
                Cube.PrintRubikCube();
                break;

            case 5:
                Cube.FindSolution();
                outputStream << "\n\nCube's unfolding after solving:\n\n";
                Cube.PrintRubikCube(outputStream);
                break;

            case 6:
                Cube.CreateRubikCube();
                Cube.setVisualCube(CUBE_SIZE, colors);
                break;

            case 7:
                Cube.PrintCubeInfo();
                break;

            default:
                break;
        }

    } catch (exception &e) {
        cout << e.what();
    }
}

#endif //RUBIKCUBE_GLUTMENU_H
