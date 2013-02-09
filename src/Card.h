#ifndef CARD_H
#define CARD_H
#include <QStringList>

class Card
{
private:
	static const QStringList s_Faces;

	static const QStringList s_Suits;

public:
	// used for s_Suits
	enum suit {Spades, Hearts, Diamonds, Clubs};


private:
	int m_FaceNbr;
	int m_SuitNbr;


public:
	Card(int faceNbr, suit suitNbr);

	const QString toString(void) const;
	const QString getFace(void) const;
	const QString getSuit(void) const;
	int getValue(void) const;

};



#endif // CARD_H
