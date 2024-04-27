
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
	vector<exercise> wczytajDaneCwiczeniaZTXT(const char* nazwaPliku);

	void userMetod0();
	void userMetod1();
	void userMetod2();
	void userMetod3();
	void userMetod4();
	void userMetod5();



	using usersPointer = void (appstatus::*)();
	usersPointer userMethodTable[6] = { &appstatus::userMetod0, &appstatus::userMetod1, &appstatus::userMetod2,&appstatus::userMetod3 ,&appstatus::userMetod4 ,&appstatus::userMetod5 };
	void callUserMethod(int index);


	void exerciseMetod0();
	void exerciseMetod1();
	void exerciseMetod2();
	void exerciseMetod3();
	void exerciseMetod4();


	using usersPointer = void (appstatus::*)();
	usersPointer exerciseMethodTable[5] = { &appstatus::exerciseMetod0, &appstatus::exerciseMetod1, &appstatus::exerciseMetod2,&appstatus::exerciseMetod3,&appstatus::exerciseMetod4 };
	
	
	void callExerciseMethod(int index);
};

