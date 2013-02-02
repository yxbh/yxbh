#include "Encryption.h"

Encryption::Encryption()
      : m_buf(""), m_key(0)
{
}

QString Encryption::shift(const QString & text, const unsigned key)
{
      m_key = key;
      srand(m_key);
      m_buf = "";
      int size = text.length();
      for (int i = 0; i < size; i++)
      {
            m_buf += text[i].digitValue() + (rand() % 128);
      }
      return m_buf;
}

QString Encryption::unshift(const QString & text) const
{
      srand(m_key);
      m_buf = "";
      int size = text.length();
      for (int i = 0; i < size; i++)
      {
            m_buf += text[i].digitValue() - (rand() % 128);
      }
      return m_buf;
}
