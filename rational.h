/**
 * @file rational.h
 * @author Justin Bradshaw
 * @brief .h file for main for CS151 PA3
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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
    // Rational(const Rational a, const Rational b);
    friend std::ostream& operator<<(std::ostream &out, Rational const& obj);
    friend Rational operator+(const Rational& one, const Rational& two);
    friend Rational operator-(const Rational& one, const Rational& two);
    friend Rational operator/(const Rational& one, const Rational& two);
    friend Rational operator*(const Rational& one, const Rational& two);
    operator double();

    void reduce();

    ~Rational(){
    }
private:
    int denominator,
        numerator;
};




#endif