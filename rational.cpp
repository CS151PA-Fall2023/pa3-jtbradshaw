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


Rational& operator+(Rational const& one, Rational const& two){
    Rational temp;
    temp.numerator = one.numerator + two.numerator;
    temp.denominator = one.denominator + two.denominator;
    return temp;
}


// Rational& operator-(Rational const& one, Rational const& two){

// }


// Rational& operator/(Rational const& one, Rational const& two){

// }


// Rational& operator*(Rational const& one, Rational const& two){

// }


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
    if(denominator < 0){
        denominator = denominator * -1;
        if (numerator > 0){
            numerator = numerator * -1;
        }
    }
}