#pragma once
#include <iostream>
class Vector
{
    int mem{};//выделенная память
    int length{};//размер
    int *values;//массив значений
public:
    Vector();//по умолчанию
    Vector(const Vector& other);//копироание
    Vector(const size_t &size, const int &initValue);
    Vector& operator=(const Vector& other);//оператор присваивания копированием
    ~Vector();//деструктор
    int& operator[](const size_t& index) const;
    size_t size() const;
    void push_back(const int& value);
    void replace(const int& oldValue, const int& newValue) const;
    int find(int value) const;
};
std::ostream& operator<<(std::ostream& out, Vector& vector);
