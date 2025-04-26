#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Car {
public:
	int size;
	string name;
	string model;

	Car(int s, string n, string m) : size(s), name(n), model(m) {
		fstream file;
		file.open("cars.collection", ios::out | ios::app);
		file << size << "*" << name << "*" << model << "*" << endl;
		file.close();
	}

	void show();
	void dis();
	void add(vector<Car>& ca);
	void rem(vector<Car>& ca);
};

void Car::dis() {
	int h = 15;
	for (int i = 0; i < h; i++) {
		cout << "||";
		cout << "\t\t\t\t\t\t\t||" << endl;
	}
}

void Car::show() {
	fstream file;
	int a;
	string nam;
	string mod;
	file.open("cars.collection", ios::in);
	cout << "Available cars in showroom:" << endl;

	while (file >> a) {
		file.ignore();
		getline(file, nam, '*');
		getline(file, mod, '*');
		cout << "Car Name: " << nam << " | Size: " << a << " | Model: " << mod << endl;
	}
	file.close();
}

void Car::add(vector<Car>& ca) {
	string na;
	string mode;
	int si;
	cin.ignore(); // Clear input buffer
	cout << "Enter the name of the car you want to add:" << endl;
	getline(cin, na);
	cout << "Enter the model of this car:" << endl;
	getline(cin, mode);
	cout << "Enter the size of the car:" << endl;
	cin >> si;
	ca.push_back(Car(si, na, mode));
}

void Car::rem(vector<Car>& ca) {
	string nam;
	cout << "Enter the car you want to remove:" << endl;
	cin.ignore();
	getline(cin, nam);

	bool found = false;
	for (auto i = ca.begin(); i != ca.end(); ++i) {
		if (i->name == nam) {
			ca.erase(i);
			cout << "Removed successfully: " << nam << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Car not found." << endl;
	}
}

int main() {
	cout << "We can add the cars first and then you can select your car:" << endl;
	cout << "Press enter to add the cars in the showroom" << endl;
	cin.ignore();

	vector<Car> ca;
	Car temp(0, "", "");
	temp.dis();

	ca.push_back(Car(4, "ferrari", "2014"));
	ca.push_back(Car(5, "mehran", "2023"));
	ca.push_back(Car(9, "alto", "2013"));

	int choice;
	string ch = "yes";

	while (ch == "yes" || ch == "Yes" || ch == "YES") {
		cout << "\nNow your choice to book your car from the showroom of cars:\n";
		cout << "1) Book order\n";
		cout << "2) Add the car\n";
		cout << "3) Remove the car\n";
		cout << "4) Exit showroom\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			ca[0].show();
			break;
		case 2:
			ca[0].add(ca);
			break;
		case 3:
			ca[0].rem(ca);
			break;
		case 4:
			cout << "Exiting showroom!" << endl;
			return 0;
		default:
			cout << "Invalid option. Try again." << endl;
		}

		cout << "\nDo you want to continue? (yes / no): ";
		cin >> ch;
	}

	return 0;
}
