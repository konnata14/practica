Исходный файл класса Figure (Figure.cpp)
#include "Figure.h"

Figure::Figure(const int _x, const int _y, Color PC, Color BC, Graphics^ b) {
    if (_x >= 0 && _y >= 0 && _x <= 1000 && _y <= 590) {
        center.X = _x;
        center.Y = _y;
        penColor = PC;
        brushColor = BC;
        a = b;
    }
    else {
        throw gcnew MyEx("Неправильное расположение фигуры!");
    }
}

void Figure::Move(Point newPoint) {
    PaintOver();
    center = newPoint;
    Print();
}

void Figure::SetCentre(Point newPoint) {
    center = newPoint;
}

Figure::~Figure() {

}
