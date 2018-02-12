/*
 * QuickSort.h
 *
 *  Created on: 2017. 5. 1.
 *      Author: cskim
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_
#include "ListSort.h"

class QuickSort: public ListSort {
public:
	QuickSort(){};
	void sort(List& L);
};

#endif /* QUICKSORT_H_ */
