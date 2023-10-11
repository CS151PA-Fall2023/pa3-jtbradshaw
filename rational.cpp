/**
 * @file rational.cpp
 * @author Justin Bradshaw
 * @brief Functions file for main.cpp for CS151 PA3.
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "rational.h"

/**
 * @brief Construct a new Rational:: Rational object
 * 
 */
Rational::Rational(){
        numerator = 0;
        denominator = 0;
}

/**
 * @brief Construct a new Rational:: Rational object
 * 
 * @param i is the integer numerator used to construct the Rational
 * @param t is the integer denominator used to construct the Rational
 */
Rational::Rational(const int i, const int t){
        numerator = i;
        denominator = t;
}

/**
 * @brief Construct a new Rational:: Rational object
 * 
 * @param s is the string that was used to construct the Rational
 */
Rational::Rational(const std::string& s){
    std::string temp;
    bool neumerator = true;
    const char *cString = s.c_str();
    for(size_t i = 0; i <= strlen(cString); i++){
        if(cString[i] == '/' || cString[i] == '\n'){
            if(neumerator){
                numerator = stoi(temp);
                temp = ' ';
                neumerator = false;
            }
                
        } else
            temp += cString[i];
    }
    denominator = stoi(temp);

}

/**
 * @brief Construct a new Rational:: Rational object
 * 
 * @param c is the c_string that was used to construct the Rational
 */
Rational::Rational(const char *c){
    std::string temp;
    bool neumerator = true;
    for(size_t i = 0; i <= strlen(c); i++){
        if(c[i] == '/' || c[i] == '\n'){
            if(neumerator){
                numerator = stoi(temp);
                temp = ' ';
                neumerator = false;
            }
                
        } else
            temp += c[i];
    }
    denominator = stoi(temp);
}

/**
 * @brief Overrides the << operator so that you can cout<<Rational in the class.
 * 
 * @param out the ostream that is returned to the cout
 * @param obj the class object that needs to be cout
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream &out, Rational const& obj){
    out<<obj.numerator<<"/"<<obj.denominator;
    return out;
}

/**
 * @brief Overloads addition operator so that addition can be preformed on Rational class
 * 
 * @param one first object of class
 * @param two second object of class
 * @return Rational 
 */
Rational operator+(const Rational& one, const Rational& two){
    int newNumerator = (one.numerator * two.denominator) + (two.numerator* one.denominator);
    int newDenominator = one.denominator * two.denominator;
    Rational temp(newNumerator, newDenominator);
    temp.reduce();
    return temp;
}

/**
 * @brief Overloads subtraction operator so that subtraction can be preformed on Rational class
 * 
 * @param one first object of class
 * @param two second object of class
 * @return Rational 
 */
Rational operator-(const Rational& one, const Rational& two){
    int newNumerator = (one.numerator * two.denominator) - (two.numerator* one.denominator);
    int newDenominator = one.denominator * two.denominator;
    Rational temp(newNumerator, newDenominator);
    temp.reduce();
    return temp;
}

/**
 * @brief Overloads division operator so that mdivision can be preformed on Rational class
 * 
 * @param one first object of class
 * @param two second object of class
 * @return Rational 
 */
Rational operator/(const Rational& one, const Rational& two){
    int newNumerator = one.numerator * two.denominator;
    int newDenominator = one.denominator * two.numerator;
    Rational temp(newNumerator, newDenominator);
    temp.reduce();
    return temp;
}

/**
 * @brief Overloads multiplication operator so that multiplication can be preformed on Rational class
 * 
 * @param one first object of class
 * @param two second object of class
 * @return Rational 
 */
Rational operator*(const Rational& one, const Rational& two){
    int newNumerator = one.numerator * two.numerator;
    int newDenominator = one.denominator * two.denominator;
    Rational temp(newNumerator, newDenominator);
    temp.reduce();
    return temp;
}

/**
 * @brief Overloads double so that Rational can be converted to double.
 * 
 * @return double 
 */
Rational::operator double(){
    return (double)numerator/(double)denominator;
}

/**
 * @brief Reduces the fraction as far as possible.
 * 
 */
void Rational::reduce(){
    for (int i = numerator * denominator; i > 1; i--) {  
            if ((denominator % i == 0) && (numerator % i == 0)) {  
                denominator /= i;  
                numerator /= i;  
            }  
        }
    for (int i = numerator * denominator; i < 0; i++) {  
            if ((denominator % i == 0) && (numerator % i == 0)) {  
                denominator /= i;  
                numerator /= i;  
            }  
        }
    if(denominator < 0){
        denominator = denominator * -1;
        if (numerator > 0){
            numerator = numerator * -1;
        }
    }
}