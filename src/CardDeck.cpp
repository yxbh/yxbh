#include "CardDeck.h"

CardHand CardDeck::deal(int handSize)
{
	int deckSize = this->size();
	if (deckSize < handSize)
		handSize = deckSize; // make sure hand size is not bigger than deck size
	srand(time(0));
	CardHand cardHand;
	cardHand.clear();
	for (int i = 0; i < handSize; ++i)
	{
		int deck_index = rand() % handSize;
		cardHand.append(this[deck_index]);
		cardHand.removeAt(deck_index);
	}
	return cardHand;
}

const QString CardDeck::toString(void) const
{
	QString str("");
	int size = this->size();
	for ( int i = 0; i < size; ++i)
	{
		str += this[i].toString() + "\n";
	}
	return str;
}

int CardDeck::getCardsLeft(void) const
{
	return this->size();
}

void CardDeck::restoreDeck(void)
{
	this->clear();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			this->append(Card( j+1, i ) );
		}
	}
	assert(this->size() == 52);
}
