/*
 * MergeSort.cpp
 *
 *  Created on: 2017. 5. 1.
 *      Author: cskim
 */

#include "MergeSort.h"

 const String HIGH_VALUE = "~~~";

void merge (List& L1, List& L2, List& L)
{
	Iterator iter1 = L1.begin();
	Iterator iter2 = L2.begin();
	L1.push_back(HIGH_VALUE);
	L2.push_back(HIGH_VALUE);
	//while (!(iter1.get()==HIGH_VALUE && iter2.get()==HIGH_VALUE)) {
	while (iter1.get()!=HIGH_VALUE || iter2.get()!=HIGH_VALUE) {
		if (iter1.get() < iter2.get()) {
			L.push_back(iter1.get());
			iter1 = L1.erase(iter1);
		}
		else {
			L.push_back(iter2.get());
			iter2 = L2.erase(iter2);
		}
	}
}

void MergeSort::sort(List& L) {
	int n = L.size();
	if (n < 2)
		return;

	List L1;
	List L2;

	int i = 0;
	Iterator li = L.begin();
	while (i < n/2) {
		L1.push_back (li.get());
		li = L.erase(li);
		i++;
	}
	while (li != L.end()) {
		L2.push_back(li.get());
		li = L.erase(li);
	}

	sort(L1);
	sort(L2);

	merge(L1, L2, L);


}
