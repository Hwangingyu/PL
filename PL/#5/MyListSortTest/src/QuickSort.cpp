/*
 * QuickSort.cpp
 *
 *  Created on: 2017. 5. 1.
 *      Author: cskim
 */

#include "QuickSort.h"

void QuickSort::sort (List& L)
{
	int n = L.size();
	if (n < 2)
		return;

	List L1;
	List L2;
	List Le;

	Iterator last = L.end();
	last.previous();
	String pivot = last.get();

	Iterator li = L.begin();
	while (!L.empty()) {
		if (li.get() < pivot) {
			L1.push_back(li.get());
		}
		else if (li.get() == pivot) {
			Le.push_back(li.get());
		}
		else {
			L2.push_back(li.get());
		}
		li = L.erase(li);
	}
	sort(L1);
	sort(L2);

	li = L1.begin();
	while (!L1.empty()) {
		L.push_back(li.get());
		li = L1.erase(li);
	}
	li = Le.begin();
	while (!Le.empty()) {
		L.push_back(li.get());
		li = Le.erase(li);
	}
	li = L2.begin();
	while (!L2.empty()) {
		L.push_back(li.get());
		li = L2.erase(li);

	}

}

