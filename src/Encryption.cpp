#include "Encryption.h"

Encryption::Encryption()
      : m_key(0)
{
}

string Encryption::shift(const string & text, const unsigned key)
{
      m_key = key;
      srand(m_key);
      string m_buf = "";
      int size = text.length();
      for (int i = 0; i < size; i++)
      {
            m_buf += char((text[i] +rand()) % 128);
      }
      return m_buf;
}

string Encryption::unshift(const string & text) const
{
      srand(m_key);
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
