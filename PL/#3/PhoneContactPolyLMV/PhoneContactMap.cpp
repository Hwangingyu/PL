/*
 * PhoneContactMap.cpp
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

#include "Entry.h"
#include "PhoneContactMap.h"

//ValueInfo viNull;

PhoneContactMap::PhoneContactMap() { }

ValueInfo PhoneContactMap::find(string name) const {
	return contactTable.at(name);
}
bool PhoneContactMap::insert(string name, int number, string email){
	MIter iter; //= contactTable.find(name);
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
	if(iter->first == name)
		return false;
	}
	contactTable[name] = ValueInfo(number, email);
	return true;
}

bool PhoneContactMap::remove(string name){
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end())
		return false;
	contactTable.erase(iter);
	return true;
}

bool PhoneContactMap::update(string name, int number, string email){
	MIter iter;
	for(iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if(iter->first==name){
			contactTable[name] = ValueInfo(number, email);
			return true;

		}
	}
	return false;
}
bool PhoneContactMap::update(string name, int number){

	MIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if(iter->first==name){
			iter->second.phoneNumber=number;
			return true;
		}
	}
	return false;
}

void PhoneContactMap::listAll() const {
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	CMIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		cout << iter->first << "		"
				<<	iter->second.phoneNumber << "	"
				<< iter->second.emailAddress << endl;
	}
}
string PhoneContactMap::findName(string email) const{

	CMIter iter;
	string key="***Error -- Name not found";
		for (iter=contactTable.begin(); iter!=contactTable.end(); iter++)
			if(iter->second.emailAddress==email)
				return iter->first;
		return key;

}

string PhoneContactMap::findName(int number) const{

	CMIter iter;
	string key="***Error -- Name not found";
		for (iter=contactTable.begin(); iter!=contactTable.end(); iter++)
			if(iter->second.phoneNumber==number)
				return iter->first;
		return key;

}
