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
#include <QString>

class Encryption
{
private:
      unsigned int m_key;
     mutable  QString m_buf;

public:
      Encryption();

      QString shift(const QString & text, const unsigned key);
      QString unshift(const QString & text) const;
};

#endif // ENCRYPTION_H
