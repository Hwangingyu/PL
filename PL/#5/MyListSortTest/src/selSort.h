/*
 * selSort.h
 *
 *  Created on: 2017. 5. 15.
 *      Author: hik35
 */

#ifndef SELSORT_H_
#define SELSORT_H_
#include "List.h"
#include "ListSort.h"

class selSort : public ListSort {
public:
	selSort(){};
	void sort(List& L);
	void swapNode (List& L, Iterator it1, Iterator it2);
	Iterator nPos(List& L, int n);
	Iterator getMin (const List& L, Iterator pos);
	Iterator getMin (const List& L);
};

 /* namespace std */

#endif /* SELSORT_H_ */
