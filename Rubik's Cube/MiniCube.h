#ifndef RUBIKCUBE_MINICUBE_H
#define RUBIKCUBE_MINICUBE_H

// MiniCube which contain from RubikCube
class MiniCube {
    private:
        // Переменные для хранения цветов кубика по разным сторонам (up, down, left, right, front, back), изначально установлены в "black"
        string up = "black", down = "black", left = "black", right = "black", front = "black", back = "black";

    public:
        MiniCube() = default;

        explicit MiniCube(string &up, string &down, string &left, string &right, string &front, string &back) : up(up), down(down), left(left), right(right), front(front), back(back) {}

        // Геттеры для цветов кубика
        [[nodiscard]] string UpColor() const { return this->up; }

        [[nodiscard]] string DownColor() const { return this->down; }

        [[nodiscard]] string LeftColor() const { return this->left; }

        [[nodiscard]] string RightColor() const { return this->right; }

        [[nodiscard]] string FrontColor() const { return this->front; }

        [[nodiscard]] string BackColor() const { return this->back; }

        // Сеттеры для цветов кубика
        void setUpColor(string color) { this->up = move(color); }

        void setDownColor(string color) { this->down = move(color); }

        void setLeftColor(string color) { this->left = move(color); }

        void setRightColor(string color) { this->right = move(color); }

        void setFrontColor(string color) { this->front = move(color); }

        void setBackColor(string color) { this->back = move(color); }
};


#endif //RUBIKCUBE_MINICUBE_H
