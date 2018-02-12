/*
 * phonebookmylist.h
 *
 *  Created on: 2013. 5. 8.
 *      Author: cskim
 */

#ifndef PHONECONTACTMYLIST_H_
#define PHONECONTACTMYLIST_H_

#include "List.h"
#include "Entry.h"
#include "String.h"
#include "PhoneContact.h"
//typedef Iterator Iter;

class PhoneContactMyList : public PhoneContact {
public:

	PhoneContactMyList();
	~PhoneContactMyList();
	PhoneContactMyList(const PhoneContactMyList& right);
	PhoneContactMyList& operator=(const PhoneContactMyList& right);
	ValueInfo operator[](String name)const;
	ValueInfo& operator[](String name);
	PhoneContactMyList& operator+=(const PhoneContactMyList& right);
	bool insert(String name, int phoneNumber, String email);
	bool update(String name, int phoneNumber, String email);
	bool remove(String name);
	ValueInfo find(String name) const;
	String find(int phonenumber) const;
	void listAll() const;

private:
	Iterator findLoc(String name);
	Iterator findLocConst (String name) const;
	List* pListPhoneContact;

};
#endif /* PHONECONTACTMYLIST_H_ */
