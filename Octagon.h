//Заголовочный файл класса Octagon (Octagon.h)
#pragma once
#include "Figure.h"

public ref class Octagon : public Figure {
public:
    Octagon(Point center, int radius, int thickness, Color borderColor, Color fillColor)
        : Figure(center, radius, thickness, borderColor, fillColor) {
    }

    virtual void Draw(Graphics^ g) override;
};
