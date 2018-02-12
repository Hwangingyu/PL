/*
 * SelectionSort.h
 *
 *  Created on: 2017. 5. 3.
 *      Author: hik35
 */

#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_
#include "ListSort.h"
class SelectionSort : public ListSort {
public:
	SelectionSort() {};
	void sort (List& L);

};

#endif /* SELECTIONSORT_H_ */
