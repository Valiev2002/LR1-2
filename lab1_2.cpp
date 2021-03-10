#include<iostream>
#include "lab1_2.h"
#include<vector>
#include<algorithm>
Vector::Vector() {//по умолчанию
    values= new int[10];
x=1;
y=5;
}
Vector::Vector(const Vector &other) {//копирование
x=other.x;
y=other.y;
    values=new int[y];
    for(int i=0;i<10;++i)
    {
        values[i]=other.values[i];
    }
}
Vector::Vector(const size_t& x1) {//с парамаетрами
    x = x1;
    y = 10;
    values= new int[y];
    for (int i = 0; i < x; ++i) {
        values[i] =rand();
    }
}
Vector &Vector::operator = (const Vector &other) {//присваивание копированием
    delete[] values;
    x=other.x;
    y=other.y;
    values = new int[x];
    for (int i = 0; i < y; i++) {
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
   return y;
}
int Vector::find(int value) const {
    {
        for (int i = 0; i < y; i++)
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
    if (x == y)
    {
        x += 10;
        int* Newdata = new int[x];
        for (int i = 0; i < y; i++)
        {
            Newdata[i] = values[i];
        }
        delete[] values;
        values = Newdata;
    }
    values[y] = value;
    y++;
}
void Vector::replace(const int &oldValue, const int &newValue) const {
    for (int i = 0; i < y; i++)
        if (values[i] == oldValue){
            values[i] = newValue;
            break;
        }
 }
std::ostream& operator<<(std::ostream& out, Vector& vec)
{
    for (int i = 0; i < vec.y; i++)
    {
        out << vec[i] << " ";
    }
    out << std::endl;
return out;
}