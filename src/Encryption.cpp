#include "Encryption.h"
#include <QDebug>

Encryption::Encryption(unsigned short key, string & opseq, unsigned short charsiz)
      : m_Key(key), m_OpSequence(opseq), m_CharSetSize(charsiz)
{
}

string Encryption::encrypt(const string &str)
{
      int n = m_OpSequence.length();
      qDebug() << "encrypt() string size = " << n << endl;
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
      return buf;
}

string Encryption::decrypt(const string &str)
{
      int n = m_OpSequence.length();
      string buf = str;
      for (int i  = 0; i <n; ++i)
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

string Encryption::permute(const string &str)
{
      return str; // TODO : implementation
}

string Encryption::unpermute(const string & str)
{
      return str; // TODO : implementation
}


