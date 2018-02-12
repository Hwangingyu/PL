/*
 * PhoneContactMap.h
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */

#ifndef PHONECONTACTMAP_H_
#define PHONECONTACTMAP_H_

#include <map>
#include "Entry.h"
#include <string>

typedef map<string, ValueInfo>::const_iterator CMIter;
typedef map<string, ValueInfo>::iterator MIter;
#include "PhoneContact.h"

class PhoneContactMap: public PhoneContact {
public:
	PhoneContactMap();
	ValueInfo find(string name) const;
	bool insert(string name, int number, string email);
	bool remove(string name);
	bool update(string name, int number, string email);
	bool update(string name, int number);
	void listAll() const;
	string findName(string email) const;
	string findName(int number) const;
private:
	map<string, ValueInfo> contactTable;
};

#endif /* PHONECONTACTMAP_H_ */
