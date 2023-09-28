#include "Vector.hpp"
#include <cmath>

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::getX() const { return x; }

double Vector::getY() const { return y; }

Vector Vector::operator+(const Vector &rhs)
{
    Vector lhs = *this;
    lhs += rhs;
    return lhs;
}

Vector Vector::operator-(const Vector &rhs)
{
    Vector lhs = *this;
    lhs -= rhs;
    return lhs;
}

Vector &Vector::operator*=(const Vector &rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vector Vector::operator-() const
{
    return Vector(-x, -y);
}

Vector &Vector::operator-=(const Vector &rhs)
{
    *this += -rhs;
    return *this;
}

Vector &Vector::operator+=(const Vector &rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector &Vector::operator*=(double scalaire)
{
    x *= scalaire;
    y *= scalaire;
    return *this;
}

Vector Vector::operator*(double scalaire)
{
    Vector lhs = *this;
    lhs *= scalaire;
    return lhs;
}

Vector &Vector::operator=(double v)
{
    x = v;
    y = v;
    return *this;
}

bool Vector::operator==(const Vector &otherVector) const
{
    if (this->x == otherVector.x && this->y == otherVector.y)
        return true;
    else
        return false;
};

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    std::cout << v.x << " " << v.y;
    return os;
}

double Vector::computeDistance2(const Vector &Vector) const
{
    const double dx = getX() - Vector.getX();
    const double dy = getY() - Vector.getY();
    const double distance2 = dx * dx + dy * dy;
    return distance2;
}

