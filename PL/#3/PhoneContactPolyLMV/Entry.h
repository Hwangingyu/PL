/*
 * Entry.h
 *
 *  Created on: 2016. 3. 21.
 *      Author: cskim
 */

#ifndef ENTRY_H_
#define ENTRY_H_

#include <string>
using namespace std;

class ValueInfo {
public:
	int phoneNumber;
	string emailAddress;
	ValueInfo(){
		phoneNumber = -99;
	}
	ValueInfo(int n, string em){
		phoneNumber = n;
		emailAddress = em;
	}
};
class Entry {
public:
	string phoneName;
	ValueInfo valueInfo;
	Entry(){
		phoneName = "";
		valueInfo.phoneNumber = -1;
		valueInfo.emailAddress = "";
	}
	Entry(string s, int n, string em) {
		phoneName = s;
		valueInfo.phoneNumber = n;
		valueInfo.emailAddress = em;
	}
};

#endif /* ENTRY_H_ */
