//======================================================
//  Encryption class
//          Author: YanXiang (Ben) Huang
//          Date;       02/02/2013
//
//          A simple encryption class that uses cstdlib's random() and srandom()
//          Base on exercises from "A Introduction to Design Patterns in C++ with Qt"
//                - Exercise 5.12 (page 164 ~ ?)
//======================================================
#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <cstdlib>             // for rand() and srand()
#include <string>
using std::string;
#include <QString>
#include <vector>
using std::vector;
#include <exception>
using std::exception;
// experimental
#include <random>
// end experimental

class Encryption
{
private:
	unsigned short m_Key;                           // key to seed srand()
	string m_OpSequence ;                          // sequence of operation
	unsigned short m_CharSetSize;
	vector<int> m_Perm;                             // permutation seq

	// shift each char via rand() after srand(key)
	string shift(const string & text, const unsigned key);
	// shift each char via rand() after srand(key), QString ver
	QString shift(const QString & text, const unsigned key);
	// opposite of shift(%)
	string unshift(const string & text) const;
	// opposite of shift(%), QString ver
	QString unshift(const QString & text) const;
	// permutation the order of the chars
	string permute(const string & str);
	// permutation the order of the chars, QString ver
	QString permute(const QString & str);
	// oppsoite of permute(%)
	string unpermute(const string & str);
	// oppsoite of permute(%), QString ver
	QString unpermute(const QString & str);

public:
	Encryption(unsigned short key, string & opseq , unsigned short charsiz = 128);
	Encryption(unsigned short key, QString & opseq, unsigned short charsiz = 128);

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
