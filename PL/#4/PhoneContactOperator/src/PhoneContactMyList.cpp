/*
 * phonebookmylist.cpp
 *
 *  Created on: 2013. 5. 8.
 *      Author: cskim
 */

#include "PhoneContactMyList.h"
#include <iostream>
#include "List.h"
#include "String.h"
using namespace std;
#include "Entry.h"

ValueInfo viNull;

ValueInfo PhoneContactMyList::find(String name) const {
	Iterator iter = findLocConst(name);
	if (iter==pListPhoneContact->end())
		return viNull;
	return iter->valueInfo;
}

String PhoneContactMyList::find(int phoneNumber) const{
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
		if(iter->valueInfo.phoneNumber==phoneNumber)
			return iter->phoneName;
	}
	return "";
}

bool PhoneContactMyList::insert(String name, int number, String email)
{
	Iterator iter = findLoc(name);
	if (iter != pListPhoneContact->end())
		return false;
	pListPhoneContact->push_back(Entry(name, number, email));
	return true;
}
bool PhoneContactMyList::remove(String name)
{
	Iterator iter = findLoc(name);
	if (iter == pListPhoneContact->end())
		return false;
	pListPhoneContact->erase(iter);
	return true;
}
bool PhoneContactMyList::update(String name, int number, String email)
{
	Iterator iter = findLoc(name);
	if (iter == pListPhoneContact->end())
		return false;
	iter->valueInfo.phoneNumber = number;
	iter->valueInfo.emailAddress = email;
	return true;
}
ValueInfo PhoneContactMyList::operator[](String name) const
{
	return find(name);
}
ValueInfo& PhoneContactMyList::operator[](String name)
{
	Iterator iter = findLoc(name);
	if (iter == pListPhoneContact->end()){
		pListPhoneContact->insert(iter, Entry(name, -1, ""));
		iter = findLoc(name);
	}
	return iter->valueInfo;
}
void PhoneContactMyList::listAll() const
{
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
		cout << iter->phoneName << "		"
				<<	iter->valueInfo.phoneNumber << "	"
				<< iter->valueInfo.emailAddress << endl;
	}
}
Iterator PhoneContactMyList::findLoc(String name)
{
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
		if (iter->phoneName == name) return iter;
	}
	return iter;
}
Iterator PhoneContactMyList::findLocConst(String name) const
{
	Iterator iter;
	for (iter=pListPhoneContact->begin(); iter!=pListPhoneContact->end(); iter++){
		if (iter->phoneName == name) return iter;
	}
	return iter;
}

PhoneContactMyList::PhoneContactMyList(){
	pListPhoneContact = new List;
}
PhoneContactMyList::~PhoneContactMyList(){
	delete pListPhoneContact;
}
PhoneContactMyList::PhoneContactMyList(const PhoneContactMyList& right){
	pListPhoneContact = new List;
	Iterator iter;
	for (iter=right.pListPhoneContact->begin(); iter!=right.pListPhoneContact->end(); iter++){
		pListPhoneContact->push_back(Entry(iter->phoneName, iter->valueInfo.phoneNumber, iter->valueInfo.emailAddress));
	}
}
PhoneContactMyList& PhoneContactMyList::operator=(const PhoneContactMyList& right){
	if (this != &right){
		delete pListPhoneContact;
		pListPhoneContact = new List;
		Iterator iter;
		for (iter=right.pListPhoneContact->begin(); iter!=right.pListPhoneContact->end(); iter++){
			pListPhoneContact->push_back(Entry(iter->phoneName, iter->valueInfo.phoneNumber, iter->valueInfo.emailAddress));
		}
	}
	return *this;
}
PhoneContactMyList& PhoneContactMyList::operator+=(const PhoneContactMyList& right)
{
	Iterator ir;
	for (ir=right.pListPhoneContact->begin(); ir!=right.pListPhoneContact->end(); ir++){
		insert(ir->phoneName, ir->valueInfo.phoneNumber,ir->valueInfo.emailAddress);
	}
   return *this;
}
