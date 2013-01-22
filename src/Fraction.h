#ifndef FRACTION_H
#define FRACTION_H
#include <QString>

class Fraction
{

private:
     int m_Numerator;
     int m_Denominator;


     // whether val is even
     bool even(int val) const;
     // return greatest common divider
     int gcd(void) const;
protected:

public:
     Fraction(int numberator = 0, int denominator = 1);
     ~Fraction();

     void set(int numberator, int denominator);
     // return the fraction in "n/d" form
     QString toString(void) const;
     // return the fraction in double
     double toDouble(void) const;
     // simplify the fraction
     void simplify(void);

     Fraction operator+(const Fraction & other) const;
     Fraction operator-(const Fraction & other) const;
     Fraction operator*(const Fraction & other) const;
     Fraction operator/(const Fraction & other) const;

};





#endif // FRACTION_H
