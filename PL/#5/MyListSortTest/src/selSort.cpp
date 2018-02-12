/*
 * selSort.cpp
 *
 *  Created on: 2017. 5. 15.
 *      Author: hik35
 */

#include "selSort.h"
#include "List.h"
using namespace std;

void selSort::swapNode (List& L, Iterator it1, Iterator it2){
	if (it1 == L.end() || it2 == L.end())
		return;
	if (it1 == it2)
		return;
	String val1 = *it1;
	String val2 = *it2;
	*it1 = val2;
	*it2 = val1;

}

Iterator selSort::nPos(List& L, int n){
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

Iterator selSort::getMin (const List& L, Iterator pos) {
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

Iterator selSort::getMin (const List& L) {
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

void selSort::sort (List& L) {
	int lsize = L.size();
	for (int i=0; i<lsize; ++i){
		for (int j=i; j<lsize; ++j){
			Iterator rest = nPos(L, j);//j번째 List node
			Iterator minit = getMin(L, rest);//rest부터 가장 작은 List node
			swapNode(L, rest, minit);//rest와 minit 자리를 서로 swap
		}
	}
}

 /* namespace std */

