/*
 * main.cpp
 *
 *  Created on: Mar 30, 2012
 *      Author: cskim
 */

#include <iostream>
#include "String.h"

using namespace std;

#include "PhoneContactMyList.h"

String nameData[] = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH",
				  "Bae JM", "Lee DI", "Lee BH", "Jang WH", "Chun WY"};
int numberData[] = {5023, 5002, 5008, 5067, 5038, 5381, 5125, 5165, 5684, 5752};
String emailData[] = {
		"parksh@email.com", "kangjh@email.com", "kimks@email.com", "leeyh@email.com", "kangsh@email.com",
		"baejm@email.com", "leedi@email.com", "leebh@email.com", "jangwh@email.com", "chunwy@email.com"
		};

PhoneContactMyList pb1;

void phoneBookTest(){
	// Create PhoneBook made of vector and array

	int incount = 9;

	for (int i=0; i <incount; i++){
		pb1.insert(nameData[i], numberData[i], emailData[i]);
	}

	cout << "***List List PhoneBook" << endl;
	pb1.listAll();

	cout << "NodeCount=" << Node::get_Count() << endl;

	pb1.insert(nameData[9], numberData[9], emailData[9]);
	pb1.remove("Kim KS");
	pb1["Kim CS"] = 5555;
	pb1["Kang JH"] = 5999;
	cout << "Find Kim CS	" << pb1["Kim CS"].phoneNumber
		 << " " << pb1["Kim CS"].emailAddress	<< endl;

	cout << "***List All Updated Entry" << endl;
	pb1.listAll();

	PhoneContactMyList pb2;
	pb2.insert("Cheng", 8888, "cheng@email.com");
	pb2.insert("Choi W", 8080, "choiw@email.com");
	pb2["Gang Dw"] = 8285;
	pb2["Kim SH"] = 8164;
	pb2["Kim CC"] = ValueInfo(8111, "cckim@email.com");

//test case
	cout<<"**insert testcase**"<<endl;
	pb2.insert("Oheng", 7777, "ocheng@email.com");
	pb2.insert("Ohoi S", 7070, "ohois@email.com");

	cout<<"**[] testcase**"<<endl;
	pb2["Kim UB"] = 8285;
	cout<<"testcase - JangDW : ";
	pb2["Jang DW"] = 8164;
	cout<<"testcase - Kimhs : ";
	pb2["Kim hs"] = ValueInfo(8111, "hskim@email.com");

	cout<<"**find(int phoneNumber) testcase**"<<endl;
	cout<<pb2.find(7777)<< endl; //FOUND
	cout<<pb1.find(7777)<< endl; //NOT_FOUND

	cout << "List New PhoneBook" << endl;
	pb2.listAll();

	PhoneContactMyList pb3 = pb1;
	PhoneContactMyList pb4;
	pb4 = pb2;
	pb3+=pb4;
	cout << "List Appended PhoneBook" << endl;
	pb3.listAll();
	cout << "NodeCount=" << Node::get_Count() << endl;

}
int main ()
{

	phoneBookTest();
	cout << "NodeCount=" << Node::get_Count() << endl;

	return 0;
}



