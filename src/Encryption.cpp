#include "Encryption.h"
#include <QDebug> // DEBUG

// std::string version
Encryption::Encryption(unsigned short key, string & opseq, unsigned short charsiz)
	: m_Key(key), m_OpSequence(opseq), m_CharSetSize(charsiz), m_Perm(0)
{}

// QString version
Encryption::Encryption(unsigned short key, QString & opseq, unsigned short charsiz)
	: m_Key(key), m_OpSequence(opseq.toStdString()), m_CharSetSize(charsiz)
{}

string Encryption::encrypt(const string & str)
{
	int n = m_OpSequence.length();
	//qDebug() << " DEBUG: encrypt() string size = " << n << endl;
	string buf = str;
	for (int i  = 0; i <n; ++i)
	{
		switch(m_OpSequence[i])
		{
		case 'p':
			buf = permute(buf);
			break;
		case 's':
			buf = shift(buf, m_Key);
			break;
		default:
			throw exception();
			break;
		}
	}
	//qDebug() << QString(" DEBUG(line%1): encrypt completed").arg(__LINE__) <<endl;
	return buf;
}

string Encryption::decrypt(const string &str)
{
	int n = m_OpSequence.length();
	string buf = str;
	for (int i  = n - 1; i  >= 0; --i)
	{
		switch(m_OpSequence[i])
		{
		case 'p':
			buf = unpermute(buf);
			break;
		case 's':
			buf = unshift(buf);
			break;
		default:
			throw exception();
			break;
		}
	}
	return buf;
}

string Encryption::shift(const string & text, const unsigned key)
{
	m_Key = key;
	srand(m_Key);
	string m_buf = "";
	int size = text.length();
	for (int i = 0; i < size; i++)
	{
		m_buf += char((text[i] +rand()) % m_CharSetSize);
	}
	return m_buf;
}

QString Encryption::shift(const QString & text, const unsigned key)
{
	return QString(shift(text.toStdString(), key).c_str());
}

string Encryption::unshift(const string & text) const
{
	srand(m_Key);
	string m_buf = "";
	int size = text.length();
	for (int i = 0; i < size; i++)
	{
		int val = (text[i] - rand()) % m_CharSetSize;
		val = ( val < 0 ) ? (val + m_CharSetSize) : val;
		m_buf += char(val);
	}
	return m_buf;
}

QString Encryption::unshift(const QString & text) const
{
	return QString(unshift(text.toStdString()).c_str());
}

// given string, return a new string with char orders permutated
string Encryption::permute(const string & str)
{
	//qDebug() << QString(" DEBUG(file:%1, Linee:%2: permute begin").arg(__FILE__).arg(__LINE__) << endl;
	srand(m_Key);
	const int str_len = str.length();
	gen_perm_seq(str_len);
	string str_buf(str);
	int s = m_Perm.size();
	char c_buf;		// char buffer
	//qDebug() << "permute() input string size = " << str_len;
	//qDebug() << "permute() m_Perm size =" << s;
	for (int i = 0; i+1 <= s; i+=2)
	{
		c_buf = str_buf[m_Perm[i]];
		str_buf[m_Perm[i]]  = str_buf[m_Perm[i+1]];
		str_buf[m_Perm[i+1]] = c_buf;
		//qDebug() <<i << ": " << QString(str_buf.c_str()) ;
	}
	return str_buf;
}

// given QString, return a new string with char orders permutated
QString Encryption::permute(const QString &str)
{
	return QString(permute(str.toStdString()).c_str());
}

string Encryption::unpermute(const string & str)
{
	//qDebug() << QString(" DEBUG(file:%1, Linee:%2: unpermute begin").arg(__FILE__).arg(__LINE__) << endl;
	srand(m_Key);
	string str_buf(str);
	//const unsigned str_len = str.length();
	//const unsigned range = str_len * 2;
	const unsigned range = m_Perm.size();
	char c_buf;
	for (int i = range -1; i-1 >= 0; i -= 2)
	{
		c_buf = str_buf[m_Perm[i]];
		str_buf[m_Perm[i]]  = str_buf[m_Perm[i-1]];
		str_buf[m_Perm[i-1]] = c_buf;
		//qDebug() <<i << ": " << QString(str_buf.c_str());
	}
	//qDebug() << QString(" DEBUG(file:%1, Linee:%2: unpermute completed").arg(__FILE__).arg(__LINE__) << endl;
	return str_buf;
}

QString Encryption::unpermute(const QString & str)
{
	return QString(unpermute(str.toStdString()).c_str());
}

// generate m_Perm sequence
void Encryption::gen_perm_seq(const unsigned str_len)
{
	srand(m_Key);
	m_Perm.clear();
	// generate a random indexs & append to m_Perm
	for (int i = 0; i < static_cast<int>(str_len); ++i)
	{
	   m_Perm.push_back(rand() % str_len);
	   m_Perm.push_back(rand() % str_len);
	}
}
