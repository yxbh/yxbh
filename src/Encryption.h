//================================================
//  Encryption class
//          Author: YanXiang (Ben) Huang
//          Date;       02/02/2013
//
//          A simple encryption class that uses cstdlib's random() and srandom()
//================================================
#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <cstdlib>
#include <string>
#include <string>
using std::string;

class Encryption
{
private:
      unsigned int m_key;
     //mutable  string m_buf;

public:
      Encryption();

      string shift(const string & text, const unsigned key);
      string unshift(const string & text) const;
};

#endif // ENCRYPTION_H
