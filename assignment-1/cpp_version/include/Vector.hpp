#pragma once
#include <iostream>

class Vector
{
private:
    double x;
    double y;

public:
    Vector(double = 0, double = 0);

    Vector operator+(const Vector &);

    Vector &operator+=(const Vector &);

    Vector operator-() const;

    Vector operator-(const Vector &);

    Vector &operator*=(double);

    Vector operator*(double);

    Vector &operator*=(const Vector &);

    Vector &operator-=(const Vector &);

    Vector &operator=(double);

    bool operator==(const Vector &otherVector) const;

    friend std::ostream &operator<<(std::ostream &, const Vector &);

    double getX() const;

    double getY() const;

    double computeDistance2(const Vector &point) const;


};

