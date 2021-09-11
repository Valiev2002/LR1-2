#include<iostream>
#include "lab1_2.h"
#include<vector>
#include<algorithm>
Vector::Vector() {//по умолчанию
    values = new int[10];
    length = 0;
    capacity=10;
}
Vector::Vector(const Vector &other) {//копирование
    capacity=other.capacity;
    length=other.length;
    values=new int[capacity];
    for(int i=0;i<length;++i)//проходимся по текущей длине вектора
    {
        values[i]=other.values[i];
    }
}
Vector::Vector(const size_t &size, const int &initValue) {// с параметрами
   capacity = size;
    length= size;
    values = new int [capacity];
    for (int i = 0; i < length; ++i)
        values[i] = initValue;
    }
Vector &Vector::operator = (const Vector &other) {//присваивание копированием
    if (this != &other)
    {
        capacity = other.capacity;
        length=other.length;
        delete[] values;
        values = new int[capacity];
        for (size_t i = 0; i < length; ++i)
            values[i] = other.values[i];
    }
    return* this;
}
Vector::~Vector() {
    delete[] values;
}
int &Vector::operator[](const size_t &v) const {
    return values[v];
}
size_t Vector::size() const {
    return length;
}
int Vector::find(int value) const {
    {
        for (int i = 0; i < length; i++)
        {
            if (values[i] ==value)
            {
                return i;
            }
        }
        return -1;
    }
}
void Vector::push_back(const int &value) {
    if (capacity == length)
    {
 int new_cap = capacity*2;
 int *array = new int[new_cap];//создаем массив с новой еикостью
for (int i = 0; i <length;++i)//обновляем информацию
    array[i] = values[i];
delete[] values;//удаляем старый мвссив
values = array;//присваиваем новый массив(если так можно сказать)
capacity =new_cap;//обнволяем емкость
    }
    values[length++] = value;
}
void Vector::replace(const int &oldValue, const int &newValue) const {
    for (int i = 0; i < length; i++)
        if (values[i] == oldValue){
            values[i] = newValue;
            break;
        }
}
std::ostream& operator<<(std::ostream& out, Vector& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        out << vec[i] << " ";
    }
    out << std::endl;
    return out;
}