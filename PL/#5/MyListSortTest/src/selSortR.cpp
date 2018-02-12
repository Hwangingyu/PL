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
	//it1�� it2�� ������ return
	String val1 = *it1;
	String val2 = *it2;
	*it1 = val2;
	*it2 = val1;
	//it1�� it2�� �ڸ��� �ٲ�
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
}//n ��ġ�� List node �� ��ȯ�մϴ�.

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
}//lowValue ���� ���ؼ� *cp���� �����ϸ� minIter, lowValue�� *cp������ �ʱ�ȭ
//List�� ���� ���� ���� ã���ϴ�.

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
//parameter passing�� �ٸ��� getMin�Լ��� ����
//List pos���� ���� ���� Iterator�� ã��

String selSortR::removeMin(List& L){
	Iterator minit = getMin(L);
	String res = *minit;
	L.erase(minit);
	return res;
}
//getMin���� ������
//��ȯ ���� �����ϱ����� �̸� ������ ��

void selSortR::sort (List& L) {
	if (L.size() <= 1)
		return;
	String minVal = removeMin(L); //���� ���� ���� ���� node�� minVal�� ����
	sort(L); //��������� sort�� ȣ��
	L.push_front(minVal); //List node�� �Ǿ����� minVal���� ����
}


/* namespace std */
