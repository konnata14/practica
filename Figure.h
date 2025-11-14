//Заголовочный файл класса Figure (Figure.h)
#pragma once
#include <windows.h>
#include <gdiplus.h>

using namespace System;
using namespace System::Drawing;

public ref class Figure abstract {
protected:
    int radius;
    int thickness;
    Point center;
    Color borderColor;
    Color fillColor;

public:
    Figure(Point center, int radius, int thickness, Color borderColor, Color fillColor)
        : center(center), radius(radius), thickness(thickness),
        borderColor(borderColor), fillColor(fillColor) {
    }

    virtual void Draw(Graphics^ g) abstract;

    virtual void Hide(Graphics^ g) {
        Color oldBorder = borderColor;
        Color oldFill = fillColor;
        borderColor = Color::Transparent;
        fillColor = Color::Transparent;
        Draw(g);
        borderColor = oldBorder;
        fillColor = oldFill;
    }

    virtual void MoveTo(Point newCenter, Graphics^ g) {
        Hide(g);
        center = newCenter;
        Draw(g);
    }

    property Point Center {
        Point get() { return center; }
        void set(Point value) { center = value; }
    }

    property int Radius {
        int get() { return radius; }
        void set(int value) { radius = value; }
    }

