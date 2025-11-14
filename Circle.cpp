//Исходный файл класса Circle (Circle.cpp)

#include "Circle.h"

void Circle::Draw(Graphics^ g) {
    if (radius <= 0)
        throw gcnew ArgumentException("Radius must be positive");

    if (center.X - radius < 0 || center.X + radius > g->VisibleClipBounds.Width ||
        center.Y - radius < 0 || center.Y + radius > g->VisibleClipBounds.Height) {
        throw gcnew ArgumentOutOfRangeException("Circle is outside drawing area");
    }

    Pen^ pen = gcnew Pen(borderColor, thickness);
    SolidBrush^ brush = gcnew SolidBrush(fillColor);

    g->FillEllipse(brush, center.X - radius, center.Y - radius,
        radius * 2, radius * 2);
    g->DrawEllipse(pen, center.X - radius, center.Y - radius,
        radius * 2, radius * 2);

    delete pen;
    delete brush;
}}
