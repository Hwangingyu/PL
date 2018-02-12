/*
 * selSortR.h
 *
 *  Created on: 2017. 5. 15.
 *      Author: hik35
 */

#ifndef SELSORTR_H_
#define SELSORTR_H_
#include "String.h"
#include "List.h"
#include "ListSort.h"

class selSortR : public ListSort {
public:
	selSortR(){};
	void sort(List& L);
	String removeMin(List& L);
	void swapNode (List& L, Iterator it1, Iterator it2);
	Iterator nPos(List& L, int n);
	Iterator getMin (const List& L, Iterator pos);
	Iterator getMin (const List& L);
};

 /* namespace std */

#endif /* SELSORTR_H_ */
