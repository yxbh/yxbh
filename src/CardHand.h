#ifndef CARDHAND_H
#define CARDHAND_H
#include <QString>
#include <QList>
#include "Card.h"
#include <QDebug>

class CardHand : public QList<Card>
{
public:
	CardHand() : QList<Card>() {}

	int getValue(void);
	const QString toString(void) const;
};

#endif // CARDHAND_H
