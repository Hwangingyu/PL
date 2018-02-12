/*
 * Entry.h
 *
 *  Created on: 2016. 3. 21.
 *      Author: cskim
 */

#ifndef ENTRY_H_
#define ENTRY_H_

//#include <string>
#include "String.h"
using namespace std;

class ValueInfo {
public:
	int phoneNumber;
	String emailAddress;
	ValueInfo(){
		phoneNumber = -99;
	}
	ValueInfo(int n, String em){
		phoneNumber = n;
		emailAddress = em;
	}
	ValueInfo& operator=(int n){
		phoneNumber = n;
		return *this;
	}
};
class Entry {
public:
	String phoneName;
	ValueInfo valueInfo;
	Entry(){
		phoneName = "";
		valueInfo.phoneNumber = -1;
		valueInfo.emailAddress = "";
	}
	Entry(String s, int n, String em) {
		phoneName = s;
		valueInfo.phoneNumber = n;
		valueInfo.emailAddress = em;
	}
};

#endif /* ENTRY_H_ */
