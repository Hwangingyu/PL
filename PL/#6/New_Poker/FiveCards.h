//
// Programmed by cskim HUFS.ac.kr 2008/5/6
//
#ifndef MY_FIVECARDS_H
#define MY_FIVECARDS_H

#include <cassert>
#include "Card.h"

const int FIVE = 5;

enum Hands { NoPair, OnePair, TwoPair, Triple, Straight, Flush, FullHouse, FourCard, StraightFlush, RoyalFlush };

class FiveCards {
public:
	FiveCards();
	FiveCards(const FiveCards& r);
	FiveCards& operator=(const FiveCards& r);
	Card& operator[](int i);
	Card operator[](int i) const;
	~FiveCards();
	int compare(const FiveCards& right) const;
	string tostring() const;
	void Sort();// 카드의 상태를 보기 쉽게 정렬함
	static FiveCards& getHighValue();
	void Poker();// 카드 상태를 나타
	Hands GetHands(Card card[]) const; // 카드족보 리턴.
private:
	Card* pelem;
};
bool operator<(const FiveCards& left, const FiveCards& right);
bool operator>(const FiveCards& left, const FiveCards& right);
bool operator==(const FiveCards& left, const FiveCards& right);
ostream& operator<<(ostream& out, const FiveCards& value);

#endif
