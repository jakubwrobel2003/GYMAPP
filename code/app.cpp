#include "../headers/app.h"
#include <fstream>
#include <vector>
#include <sstream>
void appstatus::setStatus() {
	this->status = !this->status;
}
bool appstatus::getStatus() {
	return this->status;
};
void appstatus::method0() {
	int ster;
	cout << "0-Add user\n";
	cout << "1-Delete user\n";
	cout << "2-Edit user\n";
	cout << "3-Show one user\n";
	cout << "4-Show user all\n";
    cout << "5-To back\n";
	cin >> ster;
    this->callUserMethod(ster);

}

void appstatus::method1() {
    int ster;
	cout << "0-Add new exercise\n";
	cout << "1-Delete new exercise\n";
	cout << "2-Show information exercise\n";
    cout << "3-Show information all exercises\n";
    cout << "4-To back\n";

    cin >> ster;
    callExerciseMethod(ster);
}

void appstatus::method2() {
    cout << "Goodbay\n";
    this->setStatus();
}

void appstatus::callExerciseMethod(int index) {
    if (index >= 0 && index < 7) {
        (this->*exerciseMethodTable[index])();
    }
    else {
        cout << "Invalid index\n";
    }
};



void appstatus::callUserMethod(int index) {
    if (index >= 0 && index < 3) {
        (this->*userMethodTable[index])();
    }
    else {
        cout << "Invalid index\n";
    }
};

void appstatus::callMethod(int index) {
	if (index >= 0 && index < 3) {
		(this->*methodTable[index])(); 
	}
	else {
		cout << "Invalid index\n";
	}
}
vector<user> appstatus::wczytajDaneZTXT(const char* nazwaPliku) {

    vector<user> users;

    ifstream file(nazwaPliku);

    if (!file.is_open()) {
        std::cerr << "Unable to open TXT file!" << std::endl;
        return users;
    }

    char line[100];

    while (file.getline(line, sizeof(line))) {
        std::istringstream iss(line);
        char imie[50], nazwisko[50];
        int wiek, wzrost;
        double waga;

        
        if (iss >> imie >> nazwisko >> wiek >> wzrost >> waga) {
            user u( imie, nazwisko, wiek, wzrost, waga);
            users.push_back(u);
        }

        
       
    }


    file.close();
    return users;
}

vector<exercise>appstatus::wczytajDaneCwiczeniaZTXT(const char* nazwaPliku) {
    vector<exercise> exercises;

    ifstream file(nazwaPliku);
    if (!file.is_open()) {
        cerr << "Unable to open TXT file!" << endl;
        return exercises;
    }

    char line[100];

    while (file.getline(line, sizeof(line))) {
        istringstream iss(line);

        int id;
        char name[50];
        int serie;
        double max;
        double kgInSerie;
        double oneRepMax;

        iss >> id >> name >> serie >> max >> kgInSerie >> oneRepMax;

        if (!iss.fail()) {
         
            exercise e(id, name, serie, max, kgInSerie, oneRepMax);
            exercises.push_back(e);
           
        }
    }

    file.close();
    return exercises;

};

void appstatus::userMetod0() {
    char name[50];
    char surname[50];
    int age;
    int height;
    double weight;

   
    cout << "Enter first name: \n";
    cin.getline(name, 50);

    cout << "Enter last name: \n";
    cin.getline(surname, 50);


    cout << "Enter age: \n";
    cin >>age;


    cout << "Enter height in cm: \n";
    cin >> height;


    cout << "Enter weight in kg: \n";
    cin >> weight;

    user u= user( name,  surname,  age, height,  weight);
    this->users.push_back(u);
};
void appstatus::userMetod1() {
    int i;
    cout << "Enter the user ID to delete:\n";
    cin >> i;
   
    this->users.erase(this->users.begin() + i - 1);
};
void appstatus::userMetod2() {

    int i;
    char name[50];
    char surname[50];
    int age;
    int height;
    double weight;

    cout << "Enter the user ID to edit\n";
    cin >> i;
    cout << "Enter first name: \n";
    cin.getline(name, 50);
    cout << "Enter last name: \n";
    cin.getline(surname, 50);
    cout << "Enter age: \n";
    cin >> age;
    cout << "Enter height in cm: \n";
    cin >> height;
    cout << "Enter weight in kg: \n";
    cin >> weight;

    this->users[i].setFirstName(name);
    this->users[i].setLastName(surname);
    this->users[i].setAge(age);
    this->users[i].setHeight(height);
    this->users[i].setWeight(weight);


};
void appstatus::userMetod3() {
    int ID;
    
    cout << "Enter the user ID to display:\n";
    cin >> ID;
    
    for (int i = 1; i < this->users.size(); i++) {
        if(this->users[i].getID() == ID) {
            this->users[i].print();
            return;
        }
    }
    cout << "There is no such user.\n";
};
void appstatus::userMetod4() {
    
    int i = 1;
    for (int i = 0; i < this->users.size(); i++) {
        this->users[i].print();
    }
};
void appstatus::userMetod5() {
//back
};

void appstatus::exerciseMetod0() {
    int ID;
    char name[50];
    int serie;
    double max;
    double kgInSerie;
    double oneRepMax;

    cout << "Enter the user ID: \n";
    cin >> ID;
    cout << "Enter the name of exercise: \n";
    cin.ignore(); 
    cin.getline(name, 50);
    cout << "Enter the series: \n";
    cin >> serie;
    cout << "Enter the max: \n";
    cin >> max;
    cout << "Enter kg in series \n";
    cin >> kgInSerie;
    cout << "Enter one-rep max: \n";
    cin >> oneRepMax;

    bool find = false;
    for (int i = 1; i <= this->users.size(); i++) {

        if (this->users[i].getID() == ID) {
            exercise e(int(this->users[i].favExercise.size()), name, serie, max, kgInSerie, oneRepMax);
            this->users[i].favExercise.push_back(e);
            find = !find;
        }
    }
    if (find) {
        cout << "No such user exists.\n";
    }

}; void appstatus::exerciseMetod1() {
    int IDuser;
    int IDexercise;

    do {
        cout << "Enter user ID: \n";
        cin >> IDuser;

    } while (!(this->users.size() + 1 <= IDuser));
    do {
        cout << "Enter exercise ID: \n";
        cin >> IDexercise;
    } while (!(this->users[IDuser].favExercise.size() + 1 <= IDexercise));
    bool find = false;

   
    for (int i = 0; i < this->users.size(); i++) {
        if (this->users[i].getID() == IDuser) {
         
            if (IDexercise > 0 && IDexercise <= this->users[i].favExercise.size()) {
                this->users[i].favExercise.erase(this->users[i].favExercise.begin() + IDexercise - 1);
                find = true;
            }
        }
    }
    if (!find) {
        cout << "No such user exists.\n";
    }
};

void appstatus::exerciseMetod2() {
    int IDuser;
    int IDexercise;
    do {
        cout << "Enter user ID: \n";
        cin >> IDuser;
    } while (!(this->users.size() + 1 <= IDuser));
    do {
        cout << "Enter exercise ID: \n";
        cin >> IDexercise;
    }while (!(this->users[IDuser].favExercise.size() + 1 <= IDexercise));
        
    this->users[IDuser - 1].favExercise[IDexercise - 1].print();
};
void appstatus::exerciseMetod3() {
    int IDuser;
    
    do {
        cout << "Enter user ID: \n";
        cin >> IDuser;
     
    } while (!(IDuser >= 1 && IDuser <= this->users.size()));
   
   

    for (int i = 0; i < this->users[IDuser - 1].favExercise.size(); i++) {
        this->users[IDuser - 1].favExercise[i].print();

    }
    
};
void appstatus::exerciseMetod4() {
//back
}


