/*
 * SelectionSort.cpp
 *
 *  Created on: 2017. 5. 3.
 *      Author: hik35
 */

#include "SelectionSort.h"
#include "ListSort.h"
#include "String.h"
#include "List.h"


Iterator getMin (const List& L, Iterator pos) {
	Iterator minIter;
	String lowValue = "zzz";
	for (Iterator cp = pos; cp!=L.end(); cp++) {
		if (lowValue > *cp){
			minIter = cp;
			lowValue = *cp;
		}
	}
	return minIter;
}

Iterator getMin (const List& L) {
	Iterator minIter;
	String lowValue = "zzz";
	for (Iterator cp = L.begin(); cp!=L.end(); cp++) {
		if (lowValue > *cp){
			minIter = cp;
			lowValue = *cp;
		}
	}
	return minIter;
}

void swapNode (List& L, Iterator it1, Iterator it2){
	if (it1 == L.end() || it2 == L.end())
		return;
	if (it1 == it2)
		return;
	String val1 = *it1;
	String val2 = *it2;
	*it1 = val2;
	*it2 = val1;

}

Iterator nPos(List& L, int n){
	Iterator cp;
	int count = 0;
	for (cp = L.begin(); cp!=L.end(); cp++) {
		if (count == n){
			break;
		}
		count ++;
	}
	return cp;
}

String removeMin(List& L){
	Iterator minit = getMin(L);
	String res = *minit;
	L.erase(minit);
	return res;
}

void SelectionSort::sort (List& L) {
	int lsize = L.size();
	for (int i=0; i<lsize; ++i){
		for (int j=i; j<lsize; ++j){
			Iterator rest = nPos(L, j);
			Iterator minit = getMin(L, rest);
			swapNode(L, rest, minit);
		}
	}
}

