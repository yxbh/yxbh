#include "Encryption.h"
#include <QDebug> // DEBUG

Encryption::Encryption(unsigned short key, string & opseq, unsigned short charsiz)
      : m_Key(key), m_OpSequence(opseq), m_CharSetSize(charsiz), m_Perm(0)
{}

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
                  //buf = shift(buf, m_Key);
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
                  //buf = unshift(buf);
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
            m_buf += char((text[i] +rand()) % 128);
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
            int val = (text[i] - rand()) % 128;
            val = ( val < 0 ) ? (val + 128) : val;
            m_buf += char(val);
      }
      return m_buf;
}

QString Encryption::unshift(const QString & text) const
{
      return QString(unshift(text.toStdString()).c_str());
}

string Encryption::permute(const string & str)
{
      //qDebug() << QString(" DEBUG(file:%1, Linee:%2: permute begin").arg(__FILE__).arg(__LINE__) << endl;
      srand(m_Key);
      string str_buf(str);
      int perm_c = 0;
      const int str_len = str.length();
      int i1, i2;
      char c_buf;
      do // for str_len times
      {
            ++perm_c;  // range starts from 1, NOT 0.
            i1 = rand() % str_len; i2 = rand()  % str_len;               // generate 2 random indexs
            m_Perm.push_back(i1); m_Perm.push_back(i2);     // append to m_Perm
            // swap char
            c_buf = str_buf[i1];
            str_buf[i1]  = str_buf[i2];
            str_buf[i2] = c_buf;
      }
      while (perm_c < str_len);
      return str_buf;
}

QString Encryption::permute(const QString &str)
{
      return QString(permute(str.toStdString()).c_str());
}

string Encryption::unpermute(const string & str)
{
      //qDebug() << QString(" DEBUG(file:%1, Linee:%2: unpermute begin").arg(__FILE__).arg(__LINE__) << endl;
      srand(m_Key);
      string str_buf(str);
      const unsigned str_len = str.length();

      vector<int> m_Perm(0);
      const unsigned range = str_len * 2;
      /*for (unsigned i = 0; i < range; ++i)  // get the m_Perm used permutation
            m_Perm.push_back(rand() % str_len);
*/
      char c_buf;
      for (int i = range -1; i > 0; i -= 2)
      {
            c_buf = str_buf[m_Perm[i]];
            str_buf[m_Perm[i]]  = str_buf[m_Perm[i-1]];
            str_buf[m_Perm[i-1]] = c_buf;
            //qDebug() << QString(str_buf.c_str());
      }
      //qDebug() << QString(" DEBUG(file:%1, Linee:%2: unpermute completed").arg(__FILE__).arg(__LINE__) << endl;
      return str_buf;
}

QString Encryption::unpermute(const QString & str)
{
      return QString(unpermute(str.toStdString()).c_str());
}
