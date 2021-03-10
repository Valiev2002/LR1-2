#include "lab1_2.h"
#include <iostream>
int main() {
    Vector vec1;
    Vector vec2(7);
    std::cout << vec2;
    std::cout << vec2.size() << std::endl;
    vec2.push_back(2);
    std::cout << vec2;
    std::cout << vec2.size() << std::endl;
    vec2.replace(2, 5);
    std::cout << vec2;
    std::cout << vec2.size() << std::endl;
    std::cout << vec2.find(6334) << std::endl;
    Vector vec3;
    return 0;
}

