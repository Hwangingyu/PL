/*
 * phonebook.h
 *
 *  Created on: Apr 3, 2013
 *      Author: cskim
 */

#ifndef PHONECONTACT_H_
#define PHONECONTACT_H_

//#include <string>
#include "String.h"
#include "Entry.h"

using namespace std;

class PhoneContact {
public:
	PhoneContact(){}
	virtual ~PhoneContact(){}
	virtual bool insert(String name, int PhoneNumber, String email)=0;
	virtual bool update(String name, int PhoneNumber, String email)=0;
	virtual bool remove(String name)=0;
	virtual ValueInfo find(String name) const=0;
	//virtual bool update(String name, int number)=0;
	virtual String find(int PhoneNumber) const=0;
	virtual void listAll()const=0;
	//virtual String find(int phoneNumber) const=0;


};

#endif /* PLPHONEBOOK_H_ */
