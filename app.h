#pragma once
#include <iostream>;
#include <vector>
#include "user.h"


using namespace std;
class appstatus
{
private:
	bool status = true;
public:
	vector<user> users;
	bool getStatus();
	void setStatus();
	void method0();
	void method1();
	void method2();

	using appstatusPointer = void (appstatus::*)();

	appstatusPointer methodTable[3] = { &appstatus::method0, &appstatus::method1, &appstatus::method2 };
	void callMethod(int index);

	vector<user> wczytajDaneZTXT(const char* nazwaPliku);
	

	void userMetod0();
	void userMetod1();
	void userMetod2();
	void userMetod3();
	void userMetod4();
	void userMetod5();



	using usersPointer = void (appstatus::*)();
	usersPointer userMethodTable[6] = { &appstatus::userMetod0, &appstatus::userMetod1, &appstatus::userMetod2,&appstatus::userMetod3 ,&appstatus::userMetod4 ,&appstatus::userMetod5 };
	void callUserMethod(int index);
};

