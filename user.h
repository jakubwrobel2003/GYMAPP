#pragma once
class user
{private:
	char name[24];
	char surname[24];
	int height;
	double weight;
	

public:
	char getName();
	void setName(char name[24]);
	char getSurname();
	void setSurname(char name[24]);
	int getHeight();
	void setHeight(int height);
	double getWeight();
	double workOfWeek();

};

