#pragma once

#include "superclass.h"

class eqTriangle : public Figure {
private:
    CVector2D a;
    CVector2D b;
    CVector2D c;
    double weight;
public:
    eqTriangle();

    double lenght() const;

    double square() override;

    double perimeter() override;

    double mass() const override;

    CVector2D position() override;

    bool operator==(const IPhysObject &ob) const override;

    bool operator<(const IPhysObject &ob) const override;

    void draw() override;

    void initFromDialog() override;

    const char *classname() override;

    unsigned int size() override;
};