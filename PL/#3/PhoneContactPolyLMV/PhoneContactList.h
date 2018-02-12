/*
 * CPhoneContact.h
 *
 *  Created on: 2016. 3. 28.
 *      Author: cskim
 */

#ifndef PHONECONTACTLIST_H_
#define PHONECONTACTLIST_H_

#include "List.h"
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
typedef Iterator Iter;
typedef Iterator CIter;

class PhoneContactList: public PhoneContact {
public:
	PhoneContactList();
	ValueInfo find(string name) const;
	bool insert(string name, int number, string email);
	bool remove(string name);
	bool update(string name, int number, string email);
	bool update(string name, int number);
	void listAll() const;
	string findName(string email) const;
	string findName(int number) const;
	//ValueInfo findName(int number) const;
private:
	List contactTable;
	Iter findLoc(string name);
	CIter findLocConst (string name) const;
};

#endif /* PHONECONTACTLIST_H_ */
