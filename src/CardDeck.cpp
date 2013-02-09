#include "CardDeck.h"

CardDeck::CardDeck()
{
	restoreDeck();
}

CardHand CardDeck::deal(int handSize)
{
	int deckSize = this->size();
	if (deckSize < handSize)
		handSize = deckSize; // make sure hand size is not bigger than deck size
	if (deckSize <= 0)
	{
		if (QMessageBox::question(nullptr, QString("Deck's finished!"),
								  QString("Deck's finished!\nAnother deck?"),
								  QMessageBox::Yes | QMessageBox:: No)
				== QMessageBox::Yes)
		{
			this->restoreDeck();
		}
		else
		{
			QMessageBox::information(nullptr, QString("Exit!"),
									 QString("Exiting now..."),
									 QMessageBox::Ok);
			exit(0); // EXIT_SUCCESSFUL
		}
	}

	srand(time(0));
	CardHand cardHand;
	cardHand.clear();
	for (int deck_index, i = 0; i < handSize; ++i)
	{
		int dsize = this->size();
		if (1 != dsize)
			deck_index = (rand() % (dsize-1));
		else
			deck_index = 0;

		Card card = (*this)[deck_index];
		cardHand.append(card);
		this->removeAt(deck_index);
	}
	return cardHand;
}

const QString CardDeck::toString(void) const
{
	QString str("");
	int size = this->size();
	for ( int i = 0; i < size; ++i)
	{
		str += (*this)[i].toString() + "\n";
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
