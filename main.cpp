#include <iostream>
#include "Number.h"
#include "Vector.h"
int main() {
    Number x = {10.0};
    Number y = { 20 };
    Vector vector(x, y);
    Number angle = vector.GetAngle();
    Number modue = vector.GetModule();
    std::cout << "angle: " << angle << " module: " << modue << std::endl;
    return 0;
}

