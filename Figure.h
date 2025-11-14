// Figure.h
#pragma once

#include <stdexcept>
#include <cmath>

using namespace System;
using namespace System::Drawing;

namespace WindowsFormsApp1 {

    public ref class BorderException : public Exception {
    public:
        BorderException(String^ message) : Exception(message) {}
    };

    public ref class NegativeException : public Exception {
    public:
        NegativeException(String^ message) : Exception(message) {}
    };

    public ref class Figure abstract {
    protected:
        int r;
        int a;
        Point center;
        Color color1;
        Color color2;

    public:
        Figure(Point t, int r, int a, Color c1, Color c2)
            : center(t), r(r), a(a), color1(c1), color2(c2) {
        }

        virtual void Draw(Graphics^ g) = 0;

        virtual void Hide(Graphics^ g) {
            // Temporary draw with background-like color (use White to actually hide on white background)
            Color save1 = color1;
            Color save2 = color2;
            color1 = Color::White;
            color2 = Color::White;
            Draw(g);
            color1 = save1;
            color2 = save2;
        }

        virtual void Replace(Point t) {
            center = t;
        }

        virtual void SetBorderColor(Color color) {
            color1 = color;
        }

        virtual void SetFillColor(Color color) {
            color2 = color;
        }

        property Point Center{
            Point get() { return center; }
        }

            property int Radius{
                int get() { return r; }
        }
    };

    public ref class Circle : public Figure {
    public:
        Circle(Point t, int r, int a, Color c1, Color c2) : Figure(t, r, a, c1, c2) {}

        virtual void Draw(Graphics^ g) override {
            if (center.X < 0 || center.Y < 0) {
                throw gcnew NegativeException("Circle has negative coordinates.");
            }
            if (r < 0) {
                throw gcnew NegativeException("Circle has negative radius.");
            }
            // VisibleClipBounds can return float, use panel size checking earlier,
            // but still check approximate bounds here
            if (center.X - r < 0 || center.Y - r < 0) {
                throw gcnew BorderException("Circle is out of left/top border.");
            }
            Pen^ pen = gcnew Pen(color1, 4);
            SolidBrush^ brush = gcnew SolidBrush(color2);
            g->DrawEllipse(pen, center.X - r, center.Y - r, r * 2, r * 2);
            g->FillEllipse(brush, center.X - r, center.Y - r, r * 2, r * 2);
            delete pen;
            delete brush;
        }
    };

    public ref class Octagon : public Figure {
    public:
        Octagon(Point t, int r, int a, Color c1, Color c2) : Figure(t, r, a, c1, c2) {}

        virtual void Draw(Graphics^ g) override {
            if (center.X < 0 || center.Y < 0) {
                throw gcnew NegativeException("Octagon has negative coordinates.");
            }
            if (r < 0) {
                throw gcnew NegativeException("Octagon has negative radius.");
            }
            array<PointF>^ points = gcnew array<PointF>(8);
            double angle = -M_PI / 8.0; // rotate a bit for nicer orientation
            for (int i = 0; i < 8; ++i) {
                points[i].X = center.X + r * (float)cos(angle);
                points[i].Y = center.Y + r * (float)sin(angle);
                angle += 2 * M_PI / 8.0;
            }
            Pen^ pen = gcnew Pen(color1, 4);
            SolidBrush^ brush = gcnew SolidBrush(color2);
            g->DrawPolygon(pen, points);
            g->FillPolygon(brush, points);
            delete pen;
            delete brush;
        }
    };

    public ref class ComFigure : public Figure {
    private:
        Circle^ circle;
        Octagon^ octagon;
    public:
        ComFigure(Point t, int r, int a, Color c1, Color c2, Color c3, Color c4)
            : Figure(t, r, a, c1, c2)
        {
            circle = gcnew Circle(t, r, a, c1, c2);
            octagon = gcnew Octagon(t, r, a, c3, c4);
        }

        virtual void Draw(Graphics^ g) override {
            circle->Draw(g);
            octagon->Draw(g);
        }

        virtual void Hide(Graphics^ g) override {
            circle->Hide(g);
            octagon->Hide(g);
        }

        virtual void Replace(Point t) override {
            circle->Replace(t);
            octagon->Replace(t);
            Figure::Replace(t);
        }

        virtual void SetBorderColor(Color color) override {
            circle->SetBorderColor(color);
            octagon->SetBorderColor(color);
            Figure::SetBorderColor(color);
        }

        virtual void SetFillColor(Color color) override {
            circle->SetFillColor(color);
            octagon->SetFillColor(color);
            Figure::SetFillColor(color);
        }
    };

} // namespace WindowsFormsApp1
