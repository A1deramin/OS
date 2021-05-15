//
// Created by a1deramin on 28.03.2021.
//

#include "Number.h"
Number::Number(): value_(0) {
}

Number Number::operator+(const Number& _rhs) const {
    return {value_ + _rhs.value_};
}

Number& Number::operator+=(const Number& _rhs) {
    value_ += _rhs.value_;
    return *this;
}

Number Number::operator-(const Number& _rhs) const {
    return {value_ - _rhs.value_};
}

Number& Number::operator-=(const Number& _rhs) {
    value_ -= _rhs.value_;
    return *this;
}

Number Number::operator-() const {
    return {-value_};
}

Number Number::operator*(const Number& _rhs) const {
    return {value_ * _rhs.value_};
}

Number& Number::operator*=(const Number& _rhs) {
    value_ *= _rhs.value_;
    return *this;
}

Number Number::operator/(const Number& _rhs) const {
    return {value_ / _rhs.value_};
}

Number& Number::operator/=(const Number& _rhs) {
    value_ /= _rhs.value_;
    return *this;
}