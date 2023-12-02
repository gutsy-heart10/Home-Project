#include<iostream>
#include<string.h>
using namespace std;
class Person
{
private:
	char* fullname;
	int numbResident;
	int numbHouse;
public:
	Person() :fullname{ nullptr }, numbResident{ 0 }, numbHouse{ 0 } {}
	Person(const char* name, int numResident, int numHouse) : fullname{ new char[strlen(name) + 1] }, numbResident{ numResident }, numbHouse{ numHouse }
	{
		strcpy_s(fullname, strlen(name) + 1, name);
	}
	Person(const Person& copyName) :fullname{ new char[strlen(copyName.fullname) + 1] }, numbResident{ copyName.numbResident }, numbHouse{ copyName.numbHouse }
	{
		strcpy_s(fullname, strlen(copyName.fullname) + 1, copyName.fullname);
	}

	~Person() {
		delete[] fullname;
	}
	void show(int index) {
		cout << "Apartment " << index + 1 << endl;
		cout << "Name: " << fullname << endl;
		cout << "Resident: " << numbResident << endl;
		cout << "House: " << numbHouse << endl;
		cout << "------------------------------" << endl;
	}

	char* getName() {
		return fullname;
	}
	void setName(const char* name) {
		delete[] fullname;
		fullname = new char[strlen(name) + 1];
		strcpy_s(fullname, strlen(name) + 1, name);
	}
};

class Apartment {
private:
	Person** resident;
	int number;
	int numbResident;
public:
	Apartment() : resident{ nullptr }, number{ 0 }, numbResident{ 0 } {}
	Apartment(int numResident) : resident{ nullptr }, number{ 0 }, numbResident{ numResident } {}
	Apartment(const Apartment& other) : resident{ new Person * [other.numbResident] }, number{ 0 }, numbResident{ other.numbResident }
	{
		for (int i = 0; i < numbResident; i++)
		{
			resident[i] = new Person(*other.resident[i]);
		}
	}
	~Apartment()
	{
		for (int i = 0; i < numbResident; i++)
		{
			delete resident[i];
		}
		delete[] resident;
	}
	void addResidents(const Person& person) {
		Person** newResidents = new Person * [numbResident + 1];
		for (int i = 0; i < numbResident; i++)
		{
			newResidents[i] = resident[i];
		}
		newResidents[numbResident] = new Person(person);
		delete[] resident;
		resident = newResidents;
		numbResident++;
	}
	void showApartment() {
		for (int i = 0; i < numbResident; i++)
		{

			resident[i]->show(i);
		}
	}
};


class House {
private:
	Apartment** apartments;
	int numbApartments;
public:
	House() : numbApartments{ 0 }, apartments{ nullptr } {}
	House(const House& other) : apartments{ new Apartment * [other.numbApartments] }, numbApartments{ other.numbApartments }
	{
		for (int i = 0; i < numbApartments; i++)
		{
			apartments[i] = new Apartment(*other.apartments[i]);
		}
	}
	~House()
	{
		for (int i = 0; i < numbApartments; i++)
		{
			delete apartments[i];
		}
		delete[] apartments;
	}
	void addApartment(const Apartment& apartment) {
		Apartment** newApartments = new Apartment * [numbApartments + 1];
		for (int i = 0; i < numbApartments; i++) {
			newApartments[i] = apartments[i];
		}
		newApartments[numbApartments] = new Apartment(apartment);
		delete[] apartments;
		apartments = newApartments;
		numbApartments++;
	}
	void showHouse() {
		for (int i = 0; i < numbApartments; i++)
		{
			apartments[i]->showApartment();
		}
	}
};
