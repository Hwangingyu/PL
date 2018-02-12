/*
 * PhoneContact.h
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */

#ifndef PHONECONTACT_H_
#define PHONECONTACT_H_

#include <string>
using namespace std;

class PhoneContact {
public:
	PhoneContact(){}
	virtual bool insert(string name, int number, string email)=0;
	virtual bool update(string name, int number, string email)=0;
	virtual bool remove(string name)=0;
	virtual ValueInfo find(string name) const=0;
	virtual bool update(string name, int number)=0;
	//virtual string find(int num)=0 const;

	virtual void listAll()const=0;
	virtual string findName(string email) const=0;
	virtual string findName(int number) const=0;


};

#endif /* PHONECONTACT_H_ */
