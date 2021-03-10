#pragma once
#include <iostream>
class Vector
{
public:
        int x;//начало вектора
        int y;//конец вектора
    int *values;//длина
    Vector();//по умолчанию
    Vector(const Vector& other);//копирование
    explicit Vector(const size_t& size);//с параметрами
    Vector& operator=(const Vector& other);//оператор присваивания копированием
    ~Vector();//деструктор
     int& operator[](const size_t& index) const;
     size_t size() const;
     void push_back(const int& value);
     void replace(const int& oldValue, const int& newValue) const;
    int find(int value) const;
};
std::ostream& operator<<(std::ostream& out, Vector& vector);