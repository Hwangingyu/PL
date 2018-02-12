//
// Programmed by cskim HUFS.ac.kr 2008/5/6
//

#include "FiveCards.h"

void BubbleSort(Card card[], int size);

Card FIVEHIGHCARD[] = { Card(1,15), Card(1,15), Card(1,15), Card(1,15), Card(1,15) };
FiveCards& FiveCards::getHighValue(){
	FiveCards* p5Cards = new FiveCards();
	p5Cards->pelem = FIVEHIGHCARD;
	return *p5Cards;
}

FiveCards::FiveCards() {
	pelem = new Card[FIVE];
}

FiveCards::FiveCards(const FiveCards& right) {
	pelem = new Card[FIVE];
	 for(int i=0; i<FIVE; ++i) 
		 pelem[i] = right.pelem[i];
}

FiveCards& FiveCards::operator=(const FiveCards& right) {
	if(this != &right) {
		delete[] pelem;
		pelem = new Card[FIVE];
		for(int i=0; i<FIVE; ++i) 
			pelem[i]=right.pelem[i];
	}
	return *this;
}

FiveCards::~FiveCards() {
	delete[] pelem;
}
Card& FiveCards::operator[](int index) {
	assert((index >= 0) && (index < FIVE));
	return pelem[index];
}

Card FiveCards::operator[](int index) const {
	assert((index >= 0) && (index < FIVE));
	return pelem[index];
}

int FiveCards::compare(const FiveCards& right) const
{
	Card leftCard[5];
	Card rightCard[5];

	// 족보와 그에 따른 카드를 얻는다.
	Hands ha = GetHands(leftCard);
	Hands hb = right.GetHands(rightCard);

	// 족보가 같을때,
	if (ha == hb)
	{
		// 선택된 카드의 우선순위로 크기를 결정한다.
		for (int i = 0; i < 5; i++)
		{
			if (leftCard[i] < rightCard[i])
				return -1;
			else if (leftCard[i] > rightCard[i])
				return 1;
		}
		return 0;
	}
	else
		return ha - hb;
}

void FiveCards::Sort()
{
	Card pos;//
	Card temp;

	for(int i=0; i<FIVE; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if (pelem[i].tostring() < pelem[j].tostring())
			{
				temp = pelem[j];
				pelem[j] = pelem[i];
				pelem[i] = temp;
			}
		}
	}

}

string FiveCards::tostring() const {

	string result = "[";
	for(int i=0; i<FIVE; ++i) {
		 if ( i != 0 ) result+=", ";
		 result += pelem[i].tostring();
	}
	result += "]\n";
	return result;
}

bool operator<(const FiveCards& left, const FiveCards& right)  {
   return left.compare(right) < 0;
}
bool operator>(const FiveCards& left, const FiveCards& right)  {
   return left.compare(right) > 0;
}

ostream& operator<<(ostream& out, const FiveCards& cards) {
	out << cards.tostring();
	return out;
}

bool operator==(const FiveCards& left, const FiveCards& right) {
	if (left.compare(right) == 0)
		return true;
	else return false;
}

// 카드 족보를 구하고, 해당 카드를 저장한다.
Hands FiveCards::GetHands(Card card[]) const
{
	// 카드번호의 개수를 저장할 배열.
	int hand[14] = { 0 };

	// 카드번호를 배열에 적용한다.
	for (int i = 0; i < FIVE; i++)
		hand[pelem[i].getRank()]++;

	int size = 0;
	int pairs[2] = { -1, -1 };
	int pairs_count = 0;
	int triple = -1;
	int quad = -1;
	int straight_pos = -1;
	int suit_count = 0;

	// 무늬가 같은지 체크한다.
	for (int i = 0; i < FIVE; i++)
	{
		if (pelem[0].getSuit() == pelem[i].getSuit())
			suit_count++;
	}

	// 번호가 같은 카드로 페어 개수를 구한다.
	for (int i = 0; i < 13; i++)
	{
		int count = hand[i];

		if (count == 2)
			pairs[pairs_count++] = i;
		else if (count == 3)
			triple = i;
		else if (count == 4)
			quad = i;
		else if (count == 1) {
			if ((i < (13 - 5)) && (hand[i] == 1) &&
				(hand[i + 1] == 1) &&
				(hand[i + 2] == 1) &&
				(hand[i + 3] == 1) &&
				(hand[i + 4] == 1)) {
				straight_pos = i;
			}
		}
	}

	if (suit_count == 5 && straight_pos >= 0)
	{
		if (hand[1] = 1 && hand[2] == 0)
		{
			// < 로얄 스트레이트 플러쉬 >
			// 같은 로티플의 발생의 경우 숫자가 동일 하기 때문에 무늬가 기준이 됩니다.

			// 아무카드나 하나를 추가한다.
			card[0] = pelem[0];
			
			return RoyalFlush;
		}
		else
		{
			// 같은 스티플의 경우 족보의 숫자가 높을 족보가 승리를 하게 됩니다. 만약 두 사람의  
			// 족보 숫자가 동일 하다면, 무늬가 기준이 됩니다.
			
			// 모든 카드를 넣고 정렬한다.
			for (int i = 0; i < FIVE; i++)
				card[size++] = pelem[i];
			BubbleSort(card, size);

			return StraightFlush;
		}
	}
	else if (quad >= 0)
	{
		// < 포커 >
		// 숫자가 높은것이 승리합니다.

		// 포카드인 카드를 추가한다.
		for (int i = 0; i < FIVE; i++) {
			if (pelem[i].getRank() == quad)
				card[size++] = pelem[i];
		}

		return FourCard;
	}
	else if (pairs_count == 1 && triple >= 0)
	{
		// < 풀하우스 >
		// 트리플(같은 숫자 3개의 카드족보)의 숫자가 높은 족보가 승리를 합니다.
		
		// 트리플인 카드를 추가한다.
		for (int i = 0; i < FIVE; i++) {
			if (pelem[i].getRank() == triple)
				card[size++] = pelem[i];
		}

		return FullHouse;
	}
	else if (suit_count == 5)
	{
		// < 플러쉬 >
		// 숫자를 기준으로 승부를 결정한다.즉 가장 높은 숫자부터 순서대로 숫자를 비교하여 순위를 결정하
		// 며, 만약 다섯 장의 카드 숫자가 모두 동일할 경우는 가장 높은 숫자의 카드의 무늬를 비교하여 순위
		// 를 결정합니다.

		// 모든 카드를 넣고 정렬한다.
		for (int i = 0; i < FIVE; i++)
			card[size++] = pelem[i];
		BubbleSort(card, size);

		return Flush;
	}
	else if (straight_pos >= 0)
	{
		// < 스트레이트 >
		// 첫번째 기준인 숫자가 동일하기 때문에 가장 큰 숫자의 무늬를 비교합니다. 

		// 모든 카드를 넣고 정렬한다.
		for (int i = 0; i < FIVE; i++)
			card[size++] = pelem[i];
		BubbleSort(card, size);

		return Straight;
	}
	else if (triple >= 0)
	{
		// < 트리플 >
		// 숫자를 기준으로 결정한다.

		// 트리플인 카드를 추가한다.
		for (int i = 0; i < FIVE; i++) {
			if (pelem[i].getRank() == triple)
				card[size++] = pelem[i];
		}
		return Triple;
	}
	else if (pairs_count == 2) 
	{
		// < 투페어 >
		// 투페어의 순위는 투페어 중 높은 페어의 숫자가 먼저 기준이 되며, 이 숫자가 같을 경우 두번째 페어의 숫자를 기준으로 하게 된다.
		// 첫 번째와 두 번째의 페어가 같은 경우가 발생하는데 이 경우에는 투페어에 사용된 카드를 제외하고 나머지 카드 중 가장 높은 숫자의 카드를 가진 사람이 승리를 하게 된다.

		// 페어카드를 제외한 모든 카드를 넣고 정렬한다.
		Card pairCard1;
		Card pairCard2;
		for (int i = 0; i < FIVE; i++) {
			if (pelem[i].getRank() == pairs[0])
				pairCard1 = pelem[i];
			else if (pelem[i].getRank() == pairs[1])
				pairCard2 = pelem[i];
			else
				card[2] = pelem[i];
		}

		// 두개의 페어카드중 우선순위가 높은것을 앞쪽에 오도록 추가한다.
		if (pairCard1 > pairCard2)
		{
			card[0] = pairCard1;
			card[1] = pairCard2;
		}
		else
		{
			card[0] = pairCard2;
			card[1] = pairCard1;
		}
		
		return TwoPair;
	}
	else if (pairs_count == 1) 
	{
		// < 원페어 >
		// 원페어를 제외한 나머지 카드의 숫자의 순위에 따라 승리를 결정 짓는다.이 경우에도
		// 오픈 카드의 순위 결정과 같이 남아 있는 카드를 순서대로 비교하여 순위 결정을 하게 된다.

		// 페어카드를 제외한 모든 카드를 넣고 정렬한다.
		Card pairCard;
		size = 1;
		for (int i = 0; i < FIVE; i++) {
			if (pelem[i].getRank() == pairs[0])
				pairCard = pelem[i];
			else
				card[size++] = pelem[i];
		}
		// 뒤쪽 4개만 정렬한다.
		BubbleSort(card + 1, size);

		//  페어 카드를 가장 앞쪽에 추가한다.
		card[0] = pairCard;
		return OnePair;
	}
	else
	{
		// < 노페어 >
		// 각각 가장 높은 숫자의 카드부터 비교를 하여 승부를 가르게 됩니다.

		// 모든 카드를 넣고 정렬한다.
		for (int i = 0; i < FIVE; i++)
			card[size++] = pelem[i];
		BubbleSort(card, size);

		return NoPair;
	}
}


void FiveCards::Poker()
{
	Card temp[5];
	Hands h = GetHands(temp);

	switch (h)
	{
	case NoPair: cout << "No-pair \n"; break;
	case OnePair: cout << "One-pair \n"; break;
	case TwoPair: cout << "Two-pair \n"; break;
	case Triple: cout << "Triple \n"; break;
	case Straight: cout << "Straight \n"; break;
	case Flush: cout << "Flush \n"; break;
	case FullHouse: cout << "Full-House \n"; break;
	case FourCard: cout << "Four-Card \n"; break;
	case StraightFlush: cout << "Straight-Flush \n"; break;
	case RoyalFlush: cout << "Royal-Flush \n"; break;
	}

	/*
	int card1=0;
	int card2=0;
	for(int i=0; i<FIVE-1; i++)
	{
		for(int j=i+1; j<FIVE; j++)
		{
			if(pelem[i].getRank()==pelem[j].getRank())
				card1++;
		}
	}
	if(card1==1)
		cout<<"One-pair \n";
	else if(card1==2)
		cout<<"Two-pair \n";
	else if(card1==3)
		cout<<"Triple \n";
	else if(card1==4)
		cout<<"Full-House \n";
	else if(card1==6)
		cout<<"Four-Card \n";

	if(pelem[0].getSuit()==pelem[1].getSuit() && pelem[1].getSuit()==pelem[2].getSuit() && pelem[2].getSuit()==pelem[3].getSuit() && pelem[3].getSuit()==pelem[4].getSuit())
	{
		for(int k=0; k<FIVE; k++)
		{
			if(pelem[k].getRank()==pelem[0].getRank()+k)//straight
				card2++;
			if(card2==5)
				cout<<"Straight ";
		}
		cout<<"Flush \n";
	}

	for(int m=0; m<FIVE; m++)
	{
		if(pelem[m].getRank()==pelem[0].getRank()+m)//straight
			card2++;
		if(card2==5)
			cout<<"Straight \n";
	}
	if(card1==0 && card2!=5)
		cout<<"No-pair \n";
	*/
}

// 카드 배열을 높은것부터 낮은순으로 정렬.
void BubbleSort(Card card[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (card[j - 1] < card[j])
			{
				Card t = card[j - 1];
				card[j - 1] = card[j];
				card[j] = t;
			}
		}
	}
}