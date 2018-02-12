/*
 * selSortR.cpp
 *
 *  Created on: 2017. 5. 15.
 *      Author: hik35
 */

#include "selSortR.h"
#include "List.h"
#include "String.h"
using namespace std;

void selSortR::swapNode (List& L, Iterator it1, Iterator it2){
	if (it1 == L.end() || it2 == L.end())
		return;
	if (it1 == it2)
		return;
	//it1과 it2가 같으면 return
	String val1 = *it1;
	String val2 = *it2;
	*it1 = val2;
	*it2 = val1;
	//it1과 it2의 자리를 바꿈
}

Iterator selSortR::nPos(List& L, int n){
	Iterator cp;
	int count = 0;
	for (cp = L.begin(); cp!=L.end(); cp++) {
		if (count == n){
			break;
		}
		count ++;
	}
	return cp;
}//n 위치의 List node 를 반환합니다.

Iterator selSortR::getMin (const List& L) {
	Iterator minIter;
	String lowValue = "zzz";
	for (Iterator cp = L.begin(); cp!=L.end(); cp++) {
		if (lowValue > *cp){
			minIter = cp;
			lowValue = *cp;
		}
	}
	return minIter;
}//lowValue 값을 정해서 *cp값이 갱신하면 minIter, lowValue를 *cp값으로 초기화
//List에 가장 작은 값을 찾습니다.

Iterator selSortR::getMin (const List& L, Iterator pos) {
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
//parameter passing만 다르고 getMin함수와 같음
//List pos부터 가장 작은 Iterator을 찾음

String selSortR::removeMin(List& L){
	Iterator minit = getMin(L);
	String res = *minit;
	L.erase(minit);
	return res;
}
//getMin값을 삭제함
//반환 값은 삭제하기전에 미리 저장한 값

void selSortR::sort (List& L) {
	if (L.size() <= 1)
		return;
	String minVal = removeMin(L); //가장 작은 값을 가진 node를 minVal에 저장
	sort(L); //재귀적으로 sort를 호출
	L.push_front(minVal); //List node의 맨앞으로 minVal값을 삽입
}


/* namespace std */
