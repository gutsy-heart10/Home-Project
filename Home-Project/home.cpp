#include<iostream>
#include<string.h>
#include"classes.h"
using namespace std;


int main() {
	Apartment apa;
	Person per1{ "John", 5, 4 };
	apa.addResidents(per1);
	Person Murad{"Murad",5,6};
	apa.addResidents(Murad);
	int choice{};
	while (true) {
		system("cls");
		cout << "<<Choose the option>>" << endl;
		cout << "1.Add residents." << endl;
		cout << "2.Show all residents." << endl;
		cout << "3.Exit." << endl;
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			char name[30]; int numbResident{}, numbHouse{};
			cout << "Enter the name: ";
			cin >> name;
			cout << "Enter the number of residents: ";
			cin >> numbResident;
			cout << "Enter the number of resident House: ";
			cin >> numbHouse;
			Person addPerson{ name, numbResident, numbHouse };
			apa.addResidents(addPerson);
			cout << "Resident is added!" << endl;
		}
		else if (choice == 2) {
			apa.showApartment();
			system("pause");
		}
		else if (choice == 3) {
			cout << "Goodbye!" << endl;
			break;
		}
		else {
			cout << "Invalid option" << endl;
		}
	}
	return 0;
}
