#ifndef CARDDECK_H
#define CARDDECK_H
#include <QString>
#include <QList>
#include "Card.h"
#include "CardHand.h"
#include <cstdlib>	// for srand() & rand()
#include <ctime>		// for time()
#include <QMessageBox>
#include <exception>
using std::exception;

class CardDeck : public QList<Card>
{
private:

public:
	CardDeck();

	// using available cards, deal a hand. Create and returns a CardHand obj
	CardHand deal(int handSize);
	const QString toString(void) const;
	int getCardsLeft(void) const;
	void restoreDeck(void);
};

#endif // CARDDECK_H
