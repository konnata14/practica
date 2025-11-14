Исходный файл класса Octagon (Octagon.cpp)

#include "Octagon.h"
#include <math.h>

void Octagon::Draw(Graphics^ g) {
    if (radius <= 0)
        throw gcnew ArgumentException("Radius must be positive");

    array<Point>^ points = gcnew array<Point>(8);
    double angle = 0;
    double angleIncrement = Math::PI * 2 / 8;

    for (int i = 0; i < 8; i++) {
        points[i] = Point(
            center.X + (int)(radius * cos(angle)),
            center.Y + (int)(radius * sin(angle))
        );
        angle += angleIncrement;
    }

    Pen^ pen = gcnew Pen(borderColor, thickness);
    SolidBrush^ brush = gcnew SolidBrush(fillColor);

    g->FillPolygon(brush, points);
    g->DrawPolygon(pen, points);

    delete pen;
    delete brush;
}

