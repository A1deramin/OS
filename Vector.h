//
// Created by a1deramin on 28.03.2021.
//

#ifndef LAB1_VECTOR_H
#define LAB1_VECTOR_H
#include <cmath>
#include "Number.h"

class Vector {
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


#endif //LAB1_VECTOR_H
