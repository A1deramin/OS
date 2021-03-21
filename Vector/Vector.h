#pragma once
#include "pch.h"
#include <ostream>
#include "..//Number/Number.h"
#define VECTOR_EXPORT __declspec(dllexport)
#define VECTOR_IMPORT __declspec(dllimport)
#define VECTOR_SELECTANY __declspec(selectany)
class Number;
class VECTOR_EXPORT Vector {
public:
	Vector();
	explicit Vector(Number _x, Number _y);;


	[[nodiscard]] Number GetX() const;

	void SetX(const Number& _x);

	[[nodiscard]] Number GetY() const;

	void SetY(const Number& _y);

	// friend std::ostream& operator<<(std::ostream& os, const Vector& obj) {
	// 	return os
	// 		<< "("<< obj.x_
	// 		<< ", " << obj.y_ << ")";
	// }

	[[nodiscard]] Vector operator+(const Vector& rhs) const;

	Vector& operator+=(const Vector& rhs);
	[[nodiscard]] Number GetAngle() const;
	[[nodiscard]] Number GetModule() const;

private:
	Number x_;
	Number y_;
}; // class Vector
