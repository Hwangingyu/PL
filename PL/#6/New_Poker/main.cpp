// SelSort.cpp
//

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "List.h"
#include "String.h"
#include "Card.h"
#include "FiveCards.h"

const int LINE_MAX = 13;
const int SUFFLECOUNT = 30;

int irandom(int low, int high) {
	float r = (float)rand();
	float rmax = RAND_MAX;
	return (int)((r / rmax) * (high - low + 1) + low);
}

template<typename T>
void printList(const List<T>& L) {
	int i = 0;
	for (Iterator<T> cp = L.begin(); cp != L.end(); cp++) {
		cout << *cp << " ";
		i++;
		if (i % LINE_MAX == 0)
			cout << endl;
	}
	cout << endl;
}
template<typename T>
void quickSort(List<T>* L) {
	int n = L->size();
	if (n < 2)
		return;

	List<T>* L1 = new List<T>();
	List<T>* L2 = new List<T>();
	List<T>* Le = new List<T>();

	Iterator<T> last = L->end();
	last.previous();
	T pivot = last.get();

	Iterator<T> li = L->begin();
	while (!L->empty()) {
		if (li.get() < pivot) {
			L1->push_back(li.get());
		}
		else if (li.get() == pivot) {
			Le->push_back(li.get());
		}
		else {
			L2->push_back(li.get());
		}
		li = L->erase(li);
	}
	quickSort(L1);
	quickSort(L2);

	li = L1->begin();
	while (!L1->empty()) {
		L->push_back(li.get());
		li = L1->erase(li);
	}
	li = Le->begin();
	while (!Le->empty()) {
		L->push_back(li.get());
		li = Le->erase(li);
	}
	li = L2->begin();
	while (!L2->empty()) {
		L->push_back(li.get());
		li = L2->erase(li);
	}

}
template<typename T>
Iterator<T> getMin(const List<T>& L, Iterator<T> pos) {
	Iterator<T> minIter;
	T lowValue = T::getHighValue();
	for (Iterator<T> cp = pos; cp != L.end(); cp++) {
		if (lowValue > *cp) {
			minIter = cp;
			lowValue = *cp;
		}
	}
	return minIter;
}
template<typename T>
Iterator<T> getMin(const List<T>& L) {
	Iterator<T> minIter;
	T lowValue = T::getHighValue();
	for (Iterator<T> cp = L.begin(); cp != L.end(); cp++) {
		if (lowValue > *cp) {
			minIter = cp;
			lowValue = *cp;
		}
	}
	return minIter;
}
template<typename T>
void swapNode(List<T>& L, Iterator<T> it1, Iterator<T> it2) {
	if (it1 == L.end() || it2 == L.end())
		return;
	if (it1 == it2)
		return;
	T val1 = *it1;
	T val2 = *it2;
	*it1 = val2;
	*it2 = val1;

	//cout << "  v1=" << val1 << " " << "  v2=" << val2 << endl;
	//cout << "*it1=" << *it1 << " " << "*it2=" << *it2 << endl;
}
template<typename T>
Iterator<T> nPos(List<T>& L, int n) {
	Iterator<T> cp;
	int count = 0;
	for (cp = L.begin(); cp != L.end(); cp++) {
		if (count == n) {
			break;
		}
		count++;
	}
	return cp;
}
template<typename T>
T removeMin(List<T>& L) {
	Iterator<T> minit = getMin(L);
	T res = *minit;
	L.erase(minit);
	return res;
}
template<typename T>
void selSort(List<T>& L) {
	int lsize = L.size();
	for (int i = 0; i < lsize; ++i) {
		for (int j = i; j < lsize; ++j) {
			Iterator<T> rest = nPos(L, j);
			Iterator<T> minit = getMin(L, rest);
			swapNode(L, rest, minit);
		}
	}
}
template<typename T>
void selSortR(List<T>& L) {
	if (L.size() <= 1)
		return;
	T minVal = removeMin(L);
	selSortR(L);
	L.push_front(minVal);
}
void sortTestString() {
	cout << "Sort Test String \n";
	List<String> deck;

	// Make a Card Deck
	for (int s = CLUB; s <= SPADE; s++)
		for (int r = ACE; r <= KING; r++) {
			deck.push_back(Card(s, r).toString());
		}
	// Display the Deck
	printList(deck);
	cout << endl;
	// List Test
	List<String> deck2 = deck;
	//printList(deck2);
	//deck = deck2;

	//selSort(deck);
	//printList(deck);
	//cout << endl;
	quickSort(&deck2);
	//selSortR(deck2);
	printList(deck2);
	cout << endl;

}
void sortTestCard() {
	cout << "Sort Test Card \n";
	List<Card> deck;

	// Make a Card Deck
	for (int s = CLUB; s <= SPADE; s++)
		for (int r = ACE; r <= KING; r++) {
			//cout << "card =" << Card(s,r).tostring() << endl;
			deck.push_back(Card(s, r));
		}
	// Display the Deck
	printList(deck);
	cout << endl;
	// List Test
	List<Card> deck2 = deck;
	//printList(deck2);
	//deck = deck2;

	//selSort(deck);
	//printList(deck);
	//cout << endl;

	//selSortR(deck2);
	quickSort(&deck2);
	printList(deck2);
	cout << endl;

}
template<typename T>
void suffle(List<T>& L) {

	srand((int)time(0));
	int oneOrzero = 0;
	int lsize = L.size();
	Iterator<T> iter = L.begin();
	for (int i = 1; i <= SUFFLECOUNT * lsize; i++) {
		oneOrzero = irandom(0, 1);
		if (oneOrzero == 0) {
			// move to back
			L.push_back(iter.get());
			iter = L.erase(iter);
		}
		else {
			iter.next();
			if (iter == L.end())
				iter = L.begin();
		}
	}
}

List<FiveCards>* generate5CardList(int gencount) {

	// Generate List<FiveCards>
	List<FiveCards>* p5CardsList = new List<FiveCards>();
	List<Card> deckCard;

	// Make a Card Deck
	for (int s = CLUB; s <= SPADE; s++)
		for (int r = ACE; r <= KING; r++) {
			//cout << "card =" << Card(s,r).tostring() << endl;
			deckCard.push_back(Card(s, r));
		}

	for (int i = 1; i <= gencount; i++) {

		suffle(deckCard);

		// Make a Card Deck
		Iterator<Card> iter = deckCard.begin();

		FiveCards fc;
		int ipos = 0;
		while (iter != deckCard.end()) {
			fc[ipos] = *iter;
			iter++;
			ipos++;
			if (ipos == 5) {
				p5CardsList->push_back(fc);
				ipos = 0;
			}
		}
	}
	return p5CardsList;
}


void printFiveCardsList(List<FiveCards> L) {
	int ccount = 0;
	for (Iterator<FiveCards> cp = L.begin(); cp != L.end(); cp.next()) {
		cout << ++ccount << "	" << cp.get();
	}
}
void sortTest5Cards() {
	cout << "Sort Test 5 Cards \n";
	List<FiveCards>* plist5card = generate5CardList(10);
	List<FiveCards>& list5card = *plist5card;
	// Display the Deck
	printFiveCardsList(list5card);
	cout << endl;
	// List Test
	List<FiveCards> list5card2 = list5card;
	//printList(deck2);
	//list5card = list5card2;

	//selSort(list5card);
	//printFiveCardsList(list5card);
	//cout << endl;

	//selSortR(list5card2);
	quickSort(&list5card2);
	printFiveCardsList(list5card2);
	cout << endl;
}
int main() {
	sortTestString();
	cout << "Cur Node Count=" << Node<String>::getCurCount() << endl;
	cout << "Max Node Count=" << Node<String>::getMaxCount() << endl;
	///*
	sortTestCard();
	cout << "Cur Node Count=" << Node<Card>::getCurCount() << endl;
	cout << "Max Node Count=" << Node<Card>::getMaxCount() << endl;
	sortTest5Cards();
	cout << "Cur Node Count=" << Node<Card>::getCurCount() << endl;
	cout << "Max Node Count=" << Node<Card>::getMaxCount() << endl;
	cout << "Cur Node Count=" << Node<FiveCards>::getCurCount() << endl;
	cout << "Max Node Count=" << Node<FiveCards>::getMaxCount() << endl;
	//*/
	return 0;
}

