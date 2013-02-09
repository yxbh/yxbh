#include "Card.h"

//================================================
// static members
//================================================
const QStringList Card::s_Faces({"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "K", "Q"});
const QStringList Card::s_Suits( {"Spades", "Hearts", "Diamonds", "Clubs"});

//================================================
// Constructor
//================================================
Card::Card(int faceNbr, Card::suit suitNbr)
	: m_FaceNbr(faceNbr), m_SuitNbr(suitNbr)
{
}

const QString Card::toString(void) const
{
	return QString(""); // TODO implementation
}

const QString Card::getFace(void) const
{
	return Card::s_Faces[m_FaceNbr-1]; // ?
}

const QString Card::getSuit(void) const
{
	return Card::s_Suits[m_SuitNbr];
}
