#include "Fraction.h"

Fraction::Fraction(int numberator, int denominator)
{
     m_Numerator = numberator;
     m_Denominator = denominator;
}

Fraction::~Fraction(void)
{

}

void Fraction::set(int numberator, int denominator)
{
     m_Numerator = numberator;
     m_Denominator = denominator;
}

QString Fraction::toString(void) const
{
     return QString("%1/%2").arg(m_Numerator).arg(m_Denominator);
}

double Fraction::toDouble(void) const
{
     return double(m_Numerator / m_Denominator);
}

Fraction  Fraction::operator+(const Fraction & other) const
{
     return Fraction(m_Numerator * other.m_Denominator + other.m_Numerator * m_Denominator,
                     m_Denominator * other.m_Denominator);
}

Fraction  Fraction::operator-(const Fraction & other) const
{
     return Fraction(m_Numerator * other.m_Denominator - other.m_Numerator * m_Denominator,
                     m_Denominator * other.m_Denominator);
}

Fraction  Fraction::operator*(const Fraction & other) const
{
     return Fraction(m_Numerator * other.m_Numerator, m_Denominator * other.m_Denominator);
}

Fraction  Fraction::operator/(const Fraction & other) const
{
     return Fraction(m_Numerator * other.m_Denominator, m_Denominator * other.m_Numerator);
}

void Fraction::simplify(void)
{
     int gcd_val = gcd();
     m_Numerator /= gcd_val;
     m_Denominator /= gcd_val;
}

int Fraction::gcd(void) const
{
      int smallest = (m_Numerator < m_Denominator) ? m_Numerator : m_Denominator;
     int gcd = smallest;
     for (; gcd >= 1; gcd--)
     {
          if (m_Numerator % gcd == 0 &&
                    m_Denominator % gcd == 0)
               return gcd;
     }
     return 1;
}

bool Fraction::even(int val) const
{
     return ((val % 2 == 0) ? true : false);
}
