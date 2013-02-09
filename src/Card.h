#ifndef CARD_H
#define CARD_H
#include <QStringList>
#include <assert.h>

class Card
{
private: // static members.  ini in cpp
	static const QStringList s_Faces;
	static const QStringList s_Suits;

public:
	// used for s_Suits
	enum suit {Spades, Hearts, Diamonds, Clubs};


private:
	int m_FaceNbr;	// range 1~13 (inclusive)
	int m_SuitNbr;	// range 0~3 (inclusive)
	enum {Ace, King, Queen, Jack};


public:
	// ctor
	Card(int faceNbr, int suitNbr);
	// dtor
	virtual ~Card(void) {}

	const QString toString(void) const;
	// return the face name
	const QString getFace(void) const;
	// return the suit name
	const QString getSuit(void) const;
	// return val base on face number. (in accordance to rules of game of bridge)
	int getValue(void) const;

};



#endif // CARD_H
