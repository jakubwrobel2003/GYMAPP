
#include "exercise.h"
#include "user.h"
#include "status.h"
#include "app.h"
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_CTYPE, "Polish");

    appstatus obj;
    const char* nazwaPliku = "user.txt";

   
    vector<user> users;
    users= obj.wczytajDaneZTXT(nazwaPliku);
    users[0].print();
    cout << "Witaj w GymNote\n";
    while (obj.getStatus())
    {
        cout << "0-Uzytkownicy\n";
        cout << "1-Cwiczenia\n";
        cout << "2-Exit\n";

        int nr;
        cin >> nr;
        obj.callMethod(nr);

    }

   


}