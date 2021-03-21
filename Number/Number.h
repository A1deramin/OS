// Number.cpp : Defines the functions for the static library.
//
#pragma once
#include "pch.h"

#include <ostream>

class Number {

public:
	Number();

	template <class T>

	Number(T _value) : value_(static_cast<double>(_value)) {
	}


	[[nodiscard]] operator double() const {
		return value_;
	}

	[[nodiscard]] Number operator+(const Number& _rhs) const;

	Number& operator+=(const Number& _rhs);

	[[nodiscard]] Number operator-(const Number& _rhs) const;

	Number& operator-=(const Number& _rhs);

	[[nodiscard]] Number operator-() const;

	[[nodiscard]] Number operator*(const Number& _rhs) const;

	Number& operator*=(const Number& _rhs);

	[[nodiscard]] Number operator/(const Number& _rhs) const;

	Number& operator/=(const Number& _rhs);

	friend std::ostream& operator<<(std::ostream& os, const Number& obj) {
		return os << obj.value_;
	}

private:
	double value_;
}; // class Number
