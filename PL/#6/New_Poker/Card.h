//
// Programmed by cskim HUFS.ac.kr 2008/5/6
//
#ifndef MY_CARD_H
#define MY_CARD_H

#include <iostream>
#include <string>
#include "String.h"
using namespace std;

enum PIP { ACE=1, JACK=11, QUEEN, KING };

// 카드 순위 : 클로버 < 하트 < 다이아몬드 < 스페이스
enum SUIT { CLUB=1, HEART, DIAMOND, SPADE };

class Card {
private:
	SUIT	suit;
	PIP		rank;
	static int curCount; // New
	static int maxCount; // New

public:
	Card ();
	Card (int s, int r);
	string	tostring() const;
	String	toString() const;
	//ostream& outstr(ostream& sout) const;
	int compare (const Card& c) const;
	static int get_curCount() { return  curCount; } // new
    static void set_curCount(int n) { curCount = n; } // new
	static int get_maxCount() { return  maxCount; } // new
	static Card getHighValue(); // New
	//추가, 카드 상태를 알기 위함.
	int getSuit();
	int getRank();

};

bool operator<(const Card& left, const Card& right);
bool operator<=(const Card& left, const Card& right);
bool operator==(const Card& left, const Card& right);
bool operator!=(const Card& left, const Card& right);
bool operator>=(const Card& left, const Card& right);
bool operator>(const Card& left, const Card& right);

ostream& operator<<(ostream& out, const Card& value);

#endif
