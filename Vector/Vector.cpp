#include "pch.h"
#include "Vector.h"
#include "cmath"

Vector::Vector() : x_(0), y_(0) {
}

Vector::Vector(Number _x, Number _y) : x_(_x), y_(_y) {
}

Number Vector::GetX() const {
		return x_;
}

void Vector::SetX(const Number& _x) {
	x_ = _x;
}

Number Vector::GetY() const {
	return y_;
}

void Vector::SetY(const Number& _y) {
	y_ = _y;
}

Vector Vector::operator+(const Vector& rhs) const {
	return Vector(x_ + rhs.x_, y_ + rhs.y_);
}

Vector& Vector::operator+=(const Vector& _rhs) {
	x_ += _rhs.x_;
	y_ += _rhs.y_;
	return *this;
}

Number Vector::GetAngle() const {
	if (x_ != Number(0))
		return {std::atan(y_ / x_)};
	return {0};
}

Number Vector::GetModule() const {
	return {std::sqrt(x_ * x_ + y_ * y_)};
}
