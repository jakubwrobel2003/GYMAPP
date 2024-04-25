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
	bool getStatus();
	void setStatus();
	void method0();
	void method1();
	void method2();

	using appstatusPointer = void (appstatus::*)();

	appstatusPointer methodTable[3] = { &appstatus::method0, &appstatus::method1, &appstatus::method2 };
	void callMethod(int index);

	vector<user> wczytajDaneZTXT(const char* nazwaPliku);
	


};

