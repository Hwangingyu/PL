/*
 * PhoneContactVector.h
 *
 *  Created on: 2017. 4. 1.
 *      Author: hik35
 */

#ifndef PHONECONTACTVECTOR_H_
#define PHONECONTACTVECTOR_H_

#include <vector>
#include "Entry.h"
typedef vector<Entry>::iterator VIter;
typedef vector<Entry>::const_iterator VCIter;

#include "PhoneContact.h"
/*
 *
 */

class PhoneContactVector : public PhoneContact {
public:
	PhoneContactVector();
	ValueInfo find(string name) const;
	bool insert(string name, int number, string email);
	bool remove(string name);
	bool update(string name, int number, string email);
	bool update(string name, int number);
	void listAll() const;
	string findName(string email) const;
	string findName(int number) const;
private:
	vector<Entry> contactTable;
	VIter findLoc(string name);
	VCIter findLocConst (string name) const;
};

#endif /* PHONECONTACTVECTOR_H_ */
