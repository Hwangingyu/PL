/*
 * PhoneContactVector.cpp
 *
 *  Created on: 2017. 3. 27.
 *      Author: cskim
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Entry.h"
#include "PhoneContactVector.h"

//ValueInfo viNull;

PhoneContactVector::PhoneContactVector() { }

ValueInfo PhoneContactVector::find(string name) const{
	VCIter iter = findLocConst(name);
	if (iter==contactTable.end())
		return ValueInfo(); // not found
	return iter->valueInfo;
}
bool PhoneContactVector::insert(string name, int number, string email){
VIter iter = findLoc(name);
	if (iter != contactTable.end())
		return false;
	contactTable.push_back(Entry(name, number, email));
	return true;
}

bool PhoneContactVector::remove(string name){
	VIter iter = findLoc(name);
	if (iter == contactTable.end())
		return false;
	contactTable.erase(iter);
	return true;
}

bool PhoneContactVector::update(string name, int number, string email){
	if (!remove(name))
		return false;
	return insert(name, number, email);
}
bool PhoneContactVector::update(string name, int number){
	VIter iter = findLoc(name);
		if(iter->phoneName==name){
			iter->valueInfo.phoneNumber=number;
			return true;
		}
	return false;

}

void PhoneContactVector::listAll() const{
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	VCIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		cout << iter->phoneName << "		"
				<<	iter->valueInfo.phoneNumber << "	"
				<< iter->valueInfo.emailAddress << endl;
	}
}
VIter PhoneContactVector::findLoc(string name){
	VIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}
VCIter PhoneContactVector::findLocConst (string name) const {
	VCIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}


string PhoneContactVector::findName(string email) const {
	VCIter iter;
	string key="***Error -- Name not found";
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->valueInfo.emailAddress == email)
			return iter->phoneName;
	}

	return key; // not found, iter==end()
}

string PhoneContactVector::findName(int number) const {
	VCIter iter;
	string key="***Error -- Name not found";
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->valueInfo.phoneNumber == number)
			return iter->phoneName;
	}

	return key; // not found, iter==end()
}

