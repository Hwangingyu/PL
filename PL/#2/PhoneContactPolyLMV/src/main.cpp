/*
 * main.cpp
 *
 *  Created on: Mar 30, 2012
 *      Author: cskim
 */

#include <iostream>
#include <string>

using namespace std;

#include "PhoneContactList.h"
#include "PhoneContactMap.h"
#include "PhoneContactVector.h"
string nameData[] = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH",
				  "Bae JM", "Lee DI", "Lee BH", "Jang WH", "Chun WY", //기존 데이터
				  "Hwan IG", "Kim YD","Hong YH","Mun TJ","Song CH" }; //5개의 데이터
int numberData[] = {5023, 5002, 5008, 5067, 5038, 5381, 5125, 5165, 5684, 5752, //기존데이터
					5123, 5234, 5345, 5456, 5567}; //5개의 데이터
string emailData[] = {
		"parksh@email.com", "kangjh@email.com", "kimks@email.com", "leeyh@email.com", "kangsh@email.com",
		"baejm@email.com", "leedi@email.com", "leebh@email.com", "jangwh@email.com", "chunwy@email.com", //기존데이터
		"hwangig@email.com", "kimyd@email.com", "hongyh@email.com", "muntj@email.com", "songch@email.com"}; //5개의 데이터

PhoneContactList pbList;
PhoneContactMap pbMap;
PhoneContactVector pbVector;

int incount = 15;
void testPhoneBook(PhoneContact* pb, string pbType){
	cout << "***Test "+pbType+"PhoneBook***" << endl;

	// Create PhoneBook made of vector and array
	for (int i=0; i < incount; ++i){
		if (!pb->insert(nameData[i]+"-"+pbType[0], numberData[i], emailData[i])){
			cout << "***Error in Insert***" + nameData[i]+"-"+pbType[0]<< endl;
		};
	}
	cout << "***List All "+pbType+" PhoneBook" << endl;
	pb->listAll();

	if (!pb->insert(nameData[9]+"-"+pbType[0], numberData[9], emailData[9])){
		cout << "***Error in Insert --" + nameData[9]+"-"+pbType[0] + " ***"<< endl;
	};
	if (!pb->remove(string("Kim KS-")+pbType[0])){
		cout << "***Error in Remove --" + string("Kim KS-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->insert(string("Kim CS-")+pbType[0], 5555, "kimcs@email.com")){
		cout << "***Error in Insert --" + string("Kim CS-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->update(string("Kang JH-")+pbType[0], 5991)){
		cout << "***Error in Update --" + string("Kang JH-")+pbType[0] + " ***"<< endl;
	};
	cout << "Find Phone Number By Name -- Kim CS	" << pb->find(string("Kim CS-")+pbType[0]).phoneNumber << endl;
	cout << "Find Email Address By Name -- Kim CS	" << pb->find(string("Kim CS-")+pbType[0]).emailAddress << endl;
	cout << "Find Name By Email Address -- Kim CS	" << pb->findName("kimcs@email.com")<< endl;
	cout << "Find Name By Phone Number-- Kim CS	" << pb->findName(5555)<< endl;

	//findname test
	//cout << "Find Name By emailaddress -- Kim CS	" << pb->findName(5023)<< endl;

	/////////////TESTCASE1//////////////
	cout << "Find Phone Number By Name -- Hwan IG	" << pb->find(string("Hwan IG-")+pbType[0]).phoneNumber << endl;
	cout << "Find Name By Phone Number -- 5123	" << pb->findName(5123) << endl;
	cout << "Find Email Address By Name -- Hwan IG	" << pb->find(string("Hwan IG-")+pbType[0]).emailAddress << endl;
	cout << "Find Name By Email Address -- hwangig@email.com	" << pb->findName("hwangig@email.com") << endl;

	cout<<endl;
	////////////TESTCASE2//////////////
	cout << "Find Phone Number By Name -- Kim YD	" << pb->find(string("Kim YD-")+pbType[0]).phoneNumber << endl;
	cout << "Find Name By Phone Number -- 5234	" << pb->findName(5234) << endl;
	cout << "Find Email Address By Name -- Kim YD	" << pb->find(string("Kim YD-")+pbType[0]).emailAddress << endl;
	cout << "Find Name By Email Address -- kimyd@email.com	" << pb->findName("kimyd@email.com") << endl;

	cout<<endl;
	////////////TESTCASE3//////////////
	cout << "Find Phone Number By Name -- Hong YH	" << pb->find(string("Hong YH-")+pbType[0]).phoneNumber << endl;
	cout << "Find Name By Phone Number -- 5345	" << pb->findName(5345) << endl;
	cout << "Find Email Address By Name -- Hong YH	" << pb->find(string("Hong YH-")+pbType[0]).emailAddress << endl;
	cout << "Find Name By Email Address -- hongyh@email.com	" << pb->findName("hongyh@email.com") << endl;

	cout<<endl;
	////////////TESTCASE4//////////////
	cout << "Find Phone Number By Name -- Mun TJ	" << pb->find(string("Mun TJ-")+pbType[0]).phoneNumber << endl;
	cout << "Find Name By Phone Number -- 5456	" << pb->findName(5456) << endl;
	cout << "Find Email Address By Name -- Mun TJ	" << pb->find(string("Mun TJ-")+pbType[0]).emailAddress << endl;
	cout << "Find Name By Email Address -- Muntj@email.com	" << pb->findName("muntj@email.com") << endl;
	cout<<endl;

	cout << "***List All Updated Entry" << endl;
	pb->listAll();

}

int main ()
{

	//PhoneContact* pBooks[] = { &pbList , &pbMap };
	PhoneContact* pBooks[] = { &pbList , &pbMap, &pbVector };
	//string pbTypes[] = { "List", "Map" };
	string pbTypes[] = { "List", "Map", "Vector" };

	for (int i=0; i<3; ++i){ // i<3
		testPhoneBook(pBooks[i], pbTypes[i]);
	}
	return 0;
}



