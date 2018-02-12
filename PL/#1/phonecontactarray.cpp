/*
 * phonecontactarray.cpp
 *
 *  Created on: 2016. 3. 13.
 *      Author: cskim
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> nameData(10);
vector<int> numberData(10);
vector<string> emailData(10);
class ValueInfo {
public:
	int phoneNumber;
	string emailAddress;
	ValueInfo(){
		phoneNumber = -99;
		emailAddress="***Error -- emailAddress not found";
	}
	ValueInfo(int n, string em){
		phoneNumber = n;
		emailAddress = em;
	}
};
ValueInfo viNull;
class Entry {
public:
	string phoneName;
	ValueInfo valueInfo;
	Entry(){
		phoneName = "";
		valueInfo.phoneNumber = -1;
		valueInfo.emailAddress = "";
	}

	Entry(string s, int n){
			phoneName = s;
			valueInfo.phoneNumber = n;
		}

	Entry(string s, string em){
			phoneName = s;
			valueInfo.emailAddress = em;
		}
	Entry(string s, int n, string em) {
		phoneName = s;
		valueInfo.phoneNumber = n;
		valueInfo.emailAddress = em;
	}
};

vector<Entry> vectorPhoneBook;
void insert(string name, int number, string email);
void remove(string name);
void update(string name, int number, string email);
int findPhoneNumber(string name);
string findEmailAddress(string name);
string findName(int number);
string findName(string email);
int findLoc(string name){
	for (int i=0; i<vectorPhoneBook.size(); ++i){
		if (vectorPhoneBook[i].phoneName == name)
			return i;
	}
	return -1; // not found
}
ValueInfo find(string name){
	int loc = findLoc(name);
	if (loc == -1)
		return viNull; // not found

	return vectorPhoneBook[loc].valueInfo;
}

string findName(string email){

	int key;
	for(int i=0; i<vectorPhoneBook.size(); ++i){
		if(vectorPhoneBook[i].valueInfo.emailAddress==email){
			key = i;
			break;
		}
		else
			key =-1;
	}

	if (key == -1)	{
			string key="***Error -- Name not found";
			return key;
		}
	return vectorPhoneBook[key].phoneName;
}


string findName(int number){

	int key;
	for(int i=0; i<vectorPhoneBook.size(); ++i){
		if(vectorPhoneBook[i].valueInfo.phoneNumber==number){
			key = i;
			break;
	}
		else	key =-1;

	}

	if (key == -1)	{
		string key="***Error -- Name not found";
		return key;
	}

	return vectorPhoneBook[key].phoneName;
}


int findPhoneNumber(string name){
	int loc = findLoc(name);
	if (loc == -1)
		return -1; // not found
	return vectorPhoneBook[loc].valueInfo.phoneNumber;
}
string findEmailAddress(string name){
	int loc = findLoc(name);
	if (loc == -1)
		return ""; // not found
	return vectorPhoneBook[loc].valueInfo.emailAddress;
}

void insert(string name, int number, string email){
	int loc = findLoc(name);
		if(loc == -1){
		vectorPhoneBook.push_back(Entry(name, number, email));
		}
		else{
		cout<< "***Error -- Duplicated Name" << endl;
	}
}
void remove(string name){
	int loc = findLoc(name);
	if (loc != -1){ // there exist name
		// remove array entry at loc
		for (int i=loc+1; i<vectorPhoneBook.size(); ++i){
			vectorPhoneBook[i-1] = vectorPhoneBook[i];
		}
		vectorPhoneBook.pop_back();
	}
	else {
		cout << "***Error -- Name not found" << endl;
	}
}

void update(string name, int number, string email){
	int loc = findLoc(name); // i
	vectorPhoneBook[loc].valueInfo.emailAddress=email;
	vectorPhoneBook[loc].valueInfo.phoneNumber=number;
}

void listAll(){
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	for (int i=0; i<vectorPhoneBook.size(); ++i){
		cout << vectorPhoneBook[i].phoneName << "		"
			 <<	vectorPhoneBook[i].valueInfo.phoneNumber << "	"
			 << vectorPhoneBook[i].valueInfo.emailAddress << endl;
	}
}
int main ()
{

	nameData[0]= "Kim SJ";
	nameData[1]= "Kim YD";
	nameData[2]= "Mun TJ";
	nameData[3]= "Hong YH";
	nameData[4]= "Ko YC";
	nameData[5]= "Kim GG";
	nameData[6]= "Kim DM";
	nameData[7]= "Se YJ";
	nameData[8]= "Son JY";
	nameData[9]= "Song CB";

	numberData[0]=2023;
	numberData[1]=3102;
	numberData[2]=1701;
	numberData[3]=2037;
	numberData[4]=5236;
	numberData[5]=3281;
	numberData[6]=2121;
	numberData[7]=2160;
	numberData[8]=6614;
	numberData[9]=2732;

	emailData[0]="kimsj@gmail.com";
	emailData[1]="kimyd@gmail.com";
	emailData[2]="Muntj@gmail.com";
	emailData[3]="Hongyh@gmail.com";
	emailData[4]="Koyc@gmail.com";
	emailData[5]="kimgg@gmail.com";
	emailData[6]="kimdm@gmail.com";
	emailData[7]="seyj@gmail.com";
	emailData[8]="sonjy@gmail.com";
	emailData[9]="songcb@gmail.com";

	int incount = 10;
	for (int i=0; i < incount; ++i){
		insert(nameData[i], numberData[i], emailData[i]);
	}
	cout << "List All Inserted Entry" << endl;
	listAll();

	remove("Mun TJ");
	insert("Hwan IG",2993,"hwangin@gmail.com");
	update("Hong YH", 5012, "111111@gmail.com");
	/////////////TESTCASE1//////////////
	cout << "Find Phone Number By Name -- Hwan IG	" << find("Hwan IG").phoneNumber << endl;
	cout << "Find Name By Phone Number -- 2993	" << findName(2993) << endl;
	cout << "Find Email Address By Name -- Hwan IG	" << find("Hwan IG").emailAddress << endl;
	cout << "Find Name By Email Address -- hwangig@gmail.com	" << findName("hwangin@gmail.com") << endl;

	cout<<endl;
	////////////TESTCASE2//////////////
	cout << "Find Phone Number By Name -- Kim YD	" << find("Kim YD").phoneNumber << endl;
	cout << "Find Name By Phone Number -- 3102	" << findName(3102) << endl;
	cout << "Find Email Address By Name -- Kim YD	" << find("Kim YD").emailAddress << endl;
	cout << "Find Name By Email Address -- kimsj@gmail.com	" << findName("kimsj@gmail.com") << endl;

	cout<<endl;
	////////////TESTCASE3//////////////
	cout << "Find Phone Number By Name -- Hong YH	" << find("Hong YH").phoneNumber << endl;
	cout << "Find Name By Phone Number -- 5012	" << findName(5012) << endl;
	cout << "Find Email Address By Name -- Hong YH	" << find("Hong YH").emailAddress << endl;
	cout << "Find Name By Email Address -- 111111@gmail.com	" << findName("111111@gmail.com") << endl;

	cout<<endl;
	////////////TESTCASE4//////////////
	cout << "Find Phone Number By Name -- Mun TJ	" << find("Mun TJ").phoneNumber << endl;
	cout << "Find Name By Phone Number -- 1701	" << findName(1701) << endl;
	cout << "Find Email Address By Name -- Mun TJ	" << find("Mun TJ").emailAddress << endl;
	cout << "Find Name By Email Address -- Muntj@gmail.com	" << findName("Muntj@gmail.com") << endl;
	cout<<endl;

	cout << "List All Updated Entry" << endl;
	listAll();

	return 0;
}

