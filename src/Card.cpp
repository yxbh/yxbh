#include "Card.h"

//================================================
// static members
//================================================
// the following 2 variables will not compile under vs2010 as they require initilize_list

#ifdef __MINGW32__  // mingw on windows
const QStringList Card::s_Faces({"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "K", "Q"});
const QStringList Card::s_Suits( {"Spades", "Hearts", "Diamonds", "Clubs"});
#elif defined _MSC_VER
static const QStringList iniFaces(void)
{
	QStringList returnList;
	returnList  <<"A" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "T" << "J" << "K" << "Q";
	return returnList;
}
const QStringList Card::s_Faces = iniFaces();
static const QStringList iniSuits(void)
{
	return QStringList() << "Spades" << "Hearts" << "Diamonds" << "Clubs";
}
const QStringList Card::s_Suits = iniSuits();

#endif
//================================================
// Constructor
//================================================
Card::Card(int faceNbr, int suitNbr)
	: m_FaceNbr(faceNbr), m_SuitNbr(suitNbr)
{
}

const QString Card::toString(void) const
{
	return QString("Suit: [%1] Face:[%2]").arg(getSuit()).arg(getFace());
}

const QString Card::getFace(void) const
{
	return Card::s_Faces[m_FaceNbr-1];
}

const QString Card::getSuit(void) const
{
	return Card::s_Suits[m_SuitNbr];
}

int Card::getValue(void) const
{
	switch (m_FaceNbr)
	{
	case Ace:
		return 4;
		break;
	case King:
		return 3;
	case Queen:
		return 2;
	case Jack:
		return 1;
	default:
		return 0;
	}
}



