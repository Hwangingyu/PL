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

	// ������ �׿� ���� ī�带 ��´�.
	Hands ha = GetHands(leftCard);
	Hands hb = right.GetHands(rightCard);

	// ������ ������,
	if (ha == hb)
	{
		// ���õ� ī���� �켱������ ũ�⸦ �����Ѵ�.
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

// ī�� ������ ���ϰ�, �ش� ī�带 �����Ѵ�.
Hands FiveCards::GetHands(Card card[]) const
{
	// ī���ȣ�� ������ ������ �迭.
	int hand[14] = { 0 };

	// ī���ȣ�� �迭�� �����Ѵ�.
	for (int i = 0; i < FIVE; i++)
		hand[pelem[i].getRank()]++;

	int size = 0;
	int pairs[2] = { -1, -1 };
	int pairs_count = 0;
	int triple = -1;
	int quad = -1;
	int straight_pos = -1;
	int suit_count = 0;

	// ���̰� ������ üũ�Ѵ�.
	for (int i = 0; i < FIVE; i++)
	{
		if (pelem[0].getSuit() == pelem[i].getSuit())
			suit_count++;
	}

	// ��ȣ�� ���� ī��� ��� ������ ���Ѵ�.
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
			// < �ξ� ��Ʈ����Ʈ �÷��� >
			// ���� ��Ƽ���� �߻��� ��� ���ڰ� ���� �ϱ� ������ ���̰� ������ �˴ϴ�.

			// �ƹ�ī�峪 �ϳ��� �߰��Ѵ�.
			card[0] = pelem[0];
			
			return RoyalFlush;
		}
		else
		{
			// ���� ��Ƽ���� ��� ������ ���ڰ� ���� ������ �¸��� �ϰ� �˴ϴ�. ���� �� �����  
			// ���� ���ڰ� ���� �ϴٸ�, ���̰� ������ �˴ϴ�.
			
			// ��� ī�带 �ְ� �����Ѵ�.
			for (int i = 0; i < FIVE; i++)
				card[size++] = pelem[i];
			BubbleSort(card, size);

			return StraightFlush;
		}
	}
	else if (quad >= 0)
	{
		// < ��Ŀ >
		// ���ڰ� �������� �¸��մϴ�.

		// ��ī���� ī�带 �߰��Ѵ�.
		for (int i = 0; i < FIVE; i++) {
			if (pelem[i].getRank() == quad)
				card[size++] = pelem[i];
		}

		return FourCard;
	}
	else if (pairs_count == 1 && triple >= 0)
	{
		// < Ǯ�Ͽ콺 >
		// Ʈ����(���� ���� 3���� ī������)�� ���ڰ� ���� ������ �¸��� �մϴ�.
		
		// Ʈ������ ī�带 �߰��Ѵ�.
		for (int i = 0; i < FIVE; i++) {
			if (pelem[i].getRank() == triple)
				card[size++] = pelem[i];
		}

		return FullHouse;
	}
	else if (suit_count == 5)
	{
		// < �÷��� >
		// ���ڸ� �������� �ºθ� �����Ѵ�.�� ���� ���� ���ں��� ������� ���ڸ� ���Ͽ� ������ ������
		// ��, ���� �ټ� ���� ī�� ���ڰ� ��� ������ ���� ���� ���� ������ ī���� ���̸� ���Ͽ� ����
		// �� �����մϴ�.

		// ��� ī�带 �ְ� �����Ѵ�.
		for (int i = 0; i < FIVE; i++)
			card[size++] = pelem[i];
		BubbleSort(card, size);

		return Flush;
	}
	else if (straight_pos >= 0)
	{
		// < ��Ʈ����Ʈ >
		// ù��° ������ ���ڰ� �����ϱ� ������ ���� ū ������ ���̸� ���մϴ�. 

		// ��� ī�带 �ְ� �����Ѵ�.
		for (int i = 0; i < FIVE; i++)
			card[size++] = pelem[i];
		BubbleSort(card, size);

		return Straight;
	}
	else if (triple >= 0)
	{
		// < Ʈ���� >
		// ���ڸ� �������� �����Ѵ�.

		// Ʈ������ ī�带 �߰��Ѵ�.
		for (int i = 0; i < FIVE; i++) {
			if (pelem[i].getRank() == triple)
				card[size++] = pelem[i];
		}
		return Triple;
	}
	else if (pairs_count == 2) 
	{
		// < ����� >
		// ������� ������ ����� �� ���� ����� ���ڰ� ���� ������ �Ǹ�, �� ���ڰ� ���� ��� �ι�° ����� ���ڸ� �������� �ϰ� �ȴ�.
		// ù ��°�� �� ��°�� �� ���� ��찡 �߻��ϴµ� �� ��쿡�� ���� ���� ī�带 �����ϰ� ������ ī�� �� ���� ���� ������ ī�带 ���� ����� �¸��� �ϰ� �ȴ�.

		// ���ī�带 ������ ��� ī�带 �ְ� �����Ѵ�.
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

		// �ΰ��� ���ī���� �켱������ �������� ���ʿ� ������ �߰��Ѵ�.
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
		// < ����� >
		// ���� ������ ������ ī���� ������ ������ ���� �¸��� ���� ���´�.�� ��쿡��
		// ���� ī���� ���� ������ ���� ���� �ִ� ī�带 ������� ���Ͽ� ���� ������ �ϰ� �ȴ�.

		// ���ī�带 ������ ��� ī�带 �ְ� �����Ѵ�.
		Card pairCard;
		size = 1;
		for (int i = 0; i < FIVE; i++) {
			if (pelem[i].getRank() == pairs[0])
				pairCard = pelem[i];
			else
				card[size++] = pelem[i];
		}
		// ���� 4���� �����Ѵ�.
		BubbleSort(card + 1, size);

		//  ��� ī�带 ���� ���ʿ� �߰��Ѵ�.
		card[0] = pairCard;
		return OnePair;
	}
	else
	{
		// < ����� >
		// ���� ���� ���� ������ ī����� �񱳸� �Ͽ� �ºθ� ������ �˴ϴ�.

		// ��� ī�带 �ְ� �����Ѵ�.
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

// ī�� �迭�� �����ͺ��� ���������� ����.
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