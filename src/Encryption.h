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
using std::string;
#include <QString>
#include <vector>
using std::vector;
#include <exception>
using std::exception;

class Encryption
{
private:
      unsigned short m_Key;   // key to seed srand()
      string m_OpSequence ;   // sequence of operation
      unsigned short m_CharSetSize;
      vector<int> m_Perm;

      // shift each char via rand() after srand(key)
      string shift(const string & text, const unsigned key);
      QString shift(const QString & text, const unsigned key);
      // opposite of shift(%)
      string unshift(const string & text) const;
      QString unshift(const QString & text) const;
      string permute(const string & str);
      string unpermute(const string & str);

public:
      Encryption(unsigned short key, string & opseq , unsigned short charsiz = 0);
      Encryption(unsigned short key, QString & opseq, unsigned short charsiz = 0)
            : m_Key(key), m_OpSequence(opseq.toStdString()), m_CharSetSize(charsiz)
      {
      }

      // encrypt std::string
      string encrypt(const string & str);
      // encrypt QString. (converted to std::string first)
      QString encrypt(const QString & str)
      {
            return QString(encrypt(str.toStdString()).c_str());
      }
      // decrypt std::string
      string decrypt(const string & str);
      // decrypt QString. (converted to std::string first)
      QString decrypt(const QString &str)
      {
            return QString(decrypt(str.toStdString()).c_str());
      }

};

#endif // ENCRYPTION_H
