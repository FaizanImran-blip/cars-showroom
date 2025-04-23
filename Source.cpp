#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class Cars {
public:
	int size;
	string name;
	string model;
	Cars(int s, string n, string m) :size(s), name(n), model(m)
	{
		fstream file;
		file.open("cars.collection", ios::out | ios::app);

		file << size << "*" << name << "*" << model << "*" << endl;

		file.close();

	}
	void show();
	void dis();
	void add(vector<Cars>& car);
	void rem(vector<Cars>& car);

};
void Cars::dis()
{
	int h=15;
	for(int i=0;i<h;i++)
	{
		cout<<"||";
		cout<<"\t\t\t\t\t\t\t||"<<endl;
	}
}
void Cars::show() {
	fstream file;
	int a;
	string nam;
	string mod;
	file.open("cars.collection", ios::in);
	cout << "Available cars in showroom:" << endl;

	while (file >> a)
	{
		file.ignore();
		getline(file, nam, '*');
		getline(file, mod, '*');
		cout << "Car Name: " << nam << " | Size: " << a << " | Model: " << mod << endl;
	}

	file.close();
}
void Cars::add(vector<Cars>& car)
{
	string na;
	string mode;
	int si;
	cout << "enter the name of the car you want to add:" << endl;
	getline(cin, na);
	cout << "enter the model of this car:" << endl;
	getline(cin, mode);
	cout << "enter the size of the car" << endl;
	cin >> si;
	car.push_back(Cars(si, na, mode));
}
void Cars::rem(vector<Cars>& car)
{
	string nam;
	cout << "enter the car you want to remove:" << endl;
	cin.ignore();
	getline(cin, nam);
	for (auto i = car.begin();i != car.end();++i)
	{
		if (i->name == nam)
		{
			car.erase(i);
			cout << "removed successfully:" << nam << endl;
		}
		else {  
			cout << "car not found:" << endl;
		}
	}
}
int main()
{
	cout << "we can add the cars first and then you can select your car:" << endl;
	cout << "press enter to add the cars in the showroom" << endl;
	cin.ignore();
	vector<Cars>car;
	car[0].dis();
	car.push_back(Cars(4, "ferrari", "2014"));
	car.push_back(Cars(5, "mehran", "2023"));
	car.push_back(Cars(9, "alto", "2013"));
	int c;
	string ch = "yes";
	cout << "Now your choice to book your car from the showroom of cars:" << endl;
	cout << "1)--book order:" << endl;
	cout << "2)--add the car: " << endl;
	cout << "3)--remove the car:" << endl;
	cout << "4)--exit showroom:" << endl;
	while (ch == "yes" || ch == "Yes" || ch == "YES") {
		cin >> c;
		switch (c)
		{
		case 1:
			car[0].show();
			break;
		case 2:
			car[0].add(car);
			break;
		case 3:
			car[0].rem(car);
			break;
			case 4:
			cout<<"exiting showroom!"<<endl;
			default:
			cout<<"invalid correction:::"<<endl;

		}
		cout << "do you want to do more : yes :: no" << endl;
		cin >> ch;
	}


}