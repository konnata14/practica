//Заголовочный файл класса Circle (Circle.h)
#pragma once
#include "Figure.h"

public ref class Circle : public Figure {
public:
    Circle(Point center, int radius, int thickness, Color borderColor, Color fillColor)
        : Figure(center, radius, thickness, borderColor, fillColor) {
    }

    virtual void Draw(Graphics^ g) override;
