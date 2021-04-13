#include<iostream>
#include "lab1_2.h"
#include<vector>
#include<algorithm>
Vector::Vector() {//по умолчанию
    values = new int[10];
    length = 10;
}
Vector::Vector(const Vector &other) {//копирование
mem=other.mem;
length=other.length;
    values=new int[length];
    for(int i=0;i<length;++i)
    {
        values[i]=other.values[i];
    }
}
Vector::Vector(const size_t &size, const int *initValue) {
    values = new int[mem];
    for(int i = 0; i < mem; ++i){
        values[i] = initValue[i];
    }
}
Vector &Vector::operator = (const Vector &other) {//присваивание копированием
    if (this != &other)
    {
        mem = other.mem;
        length=other.length;
        delete[] values;
        values = new int[mem];
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
    if (mem == length)
    {
        mem += 10;
        int* Newdata = new int[mem];
        for (int i = 0; i < length; i++)
        {
            Newdata[i] = values[i];
        }
        delete[] values;
        values = Newdata;
    }
    values[length] = value;
    length++;
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
