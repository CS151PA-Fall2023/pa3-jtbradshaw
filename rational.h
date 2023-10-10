
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Rational{
public:
    Rational();
    Rational(const int i,const int t);
    Rational(const std::string& s);
    Rational(const char *c);
    friend std::ostream& operator<<(std::ostream &out, Rational const& obj);
    friend Rational& operator+(Rational const& one, Rational const& two);
    // friend Rational& operator-(Rational const& one, Rational const& two);
    // friend Rational& operator/(Rational const& one, Rational const& two);
    // friend Rational& operator*(Rational const& one, Rational const& two);
    operator double();

    void reduce();

    ~Rational(){
    }
private:
    int denominator,
        numerator;
};




#endif