#include "CardHand.h"

int CardHand::getValue(void)
{
	int val = 0;
	int size = this->size();
	for ( int i = 0; i < size; ++i)
	{
		val += this[i].getValue();
	}
	return val;
}

const QString CardHand::toString(void) const
{
	QString str("");
	int size = this->size();
	for ( int i = 0; i < size; ++i)
	{
		str += this[i].toString() + "\n";
	}
	return str;
}
