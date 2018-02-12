/*
 * CPhoneContact.cpp
 *
 *  Created on: 2016. 3. 28.
 *      Author: cskim
 */
#include <iostream>
#include <string>
using namespace std;

#include "Entry.h"
#include "List.h"
#include "PhoneContactList.h"

ValueInfo viNull;

PhoneContactList::PhoneContactList() { }

ValueInfo PhoneContactList::find(string name) const {
	CIter iter = findLocConst(name);
	if (iter==contactTable.end())
		return viNull;
	return iter->valueInfo;
}
bool PhoneContactList::insert(string name, int number, string email){
	Iter iter = findLoc(name);
	if (iter != contactTable.end())
		return false;
	contactTable.push_back(Entry(name, number, email));
	return true;
}

bool PhoneContactList::remove(string name){
	Iter iter = findLoc(name);
	if (iter == contactTable.end())
		return false;
	contactTable.erase(iter);
	return true;
}

bool PhoneContactList::update(string name, int number, string email){
	if (!remove(name))
		return false;
	return insert(name, number, email);
}
bool PhoneContactList::update(string name, int number){
	Iter iter = findLoc(name);
		if(iter->phoneName==name){
			iter->valueInfo.phoneNumber=number;
			return true;
		}
	return false;
}

void PhoneContactList::listAll() const{
	cout << "Name" << "		" << "Number" << "	"<< "Email " << endl;
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		cout << iter->phoneName << "		"
				<<	iter->valueInfo.phoneNumber << "	"
				<< iter->valueInfo.emailAddress << endl;
	}
}
Iter PhoneContactList::findLoc(string name){
	Iter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}
CIter PhoneContactList::findLocConst (string name) const {
	CIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}


string PhoneContactList::findName(string email) const {
	CIter iter;
	string key="***Error -- Name not found";
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->valueInfo.emailAddress == email)
			return iter->phoneName;
	}
	return key; // not found, iter==end()
}

string PhoneContactList::findName(int number) const {
	CIter iter;
	string key="***Error -- Name not found";
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->valueInfo.phoneNumber == number)
			return iter->phoneName;
	}
	return key; // not found, iter==end()
}


