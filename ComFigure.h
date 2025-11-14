Заголовочный файл класса ComFigure (ComFigure.h)

#pragma once
#include "Circle.h"
#include "Octagon.h"

public ref class ComFigure : public Figure {
private:
    Circle^ circle;
    Octagon^ octagon;

public:
    ComFigure(Point center, int radius, int thickness,
        Color circleBorder, Color circleFill,
        Color octagonBorder, Color octagonFill);

    virtual void Draw(Graphics^ g) override;
    virtual void Hide(Graphics^ g) override;
    virtual void MoveTo(Point newCenter, Graphics^ g) override;

    ~ComFigure();
};
