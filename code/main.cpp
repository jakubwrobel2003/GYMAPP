
#include "../headers/exercise.h"
#include "../headers/user.h"
#include "../headers/status.h"
#include "../headers/app.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;
vector<user> users;




int main()
{
    setlocale(LC_CTYPE, "Polish");

    appstatus obj;
    const char* nazwaPliku = "source/user.txt";

   
    obj.users= obj.wczytajDaneZTXT(nazwaPliku);
    for (int i = 0; i < obj.users.size(); i++) {
        std::ostringstream oss;

       
        oss << "source/exercise_" << i+1 << ".txt";

  
       string fileNameStr = oss.str();
        const char* fileName = fileNameStr.c_str();
        obj.users[i].favExercise = obj.wczytajDaneCwiczeniaZTXT(fileName);
    }
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