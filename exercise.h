#pragma once

class exercise
{
private:
	int ID;
	char name[24];
	int serie;
	double max;
	double kgInSerie;
	double oneRepMax;
public:
int	getID();
void setID();
char getName();
void setName(char name[50]);
int getSerie();
void setSerie(int serie);
double getMax();
void setMax( double max);
double getKgInSerie();
void setKgInSerie( double kg);
double getOneRepMax();
void setOneRepMax(double kg, double serie, double& person);
};

