#include "Controller.h"
#include <iostream>
#include <string>

using namespace std;

Controller::Controller(Repository repos)
{
	this->repos = repos;
}


Controller::~Controller()
{

}
void Controller::add()
{
	cout << "~Add med~\n";

	string n;
	double c;
	double p;
	int q;

	cout << "Name: ";
	cin >> n;

	cout << "Concentration: ";
	cin >> c;

	cout << "Quantity(int): ";
	cin >> q;

	cout << "Price(double): ";
	cin >> p;

	add_med(n, c, p, q);

	int option = -1;
	cout << "\n1.UNDO\n";
	cout << "2.REDO\n";
	cout << "3.PASS\n";

	while (option != 3)
	{
		cout << "Option: ";
		cin >> option;

		if (option == 1)
		{
			delete_med(n, c);
		}
		else if (option == 2)
			add();
		else if (option == 3)
		{
			break;
		}
	}
}

void Controller::deletes()
{
	cout << "~Delete med~\n";

	string n;
	double c;

	cout << "Name: ";
	cin >> n;

	cout << "Concentration: ";
	cin >> c;

	Medicine temp = get_element(n, c);
	delete_med(n, c);

	int option = -1;
	cout << "\n1.UNDO\n";
	cout << "2.REDO\n";
	cout << "3.PASS\n";

	while (option != 3)
	{
		cout << "Option: ";
		cin >> option;

		if (option == 1)
			add_med(temp.get_name(), temp.get_concentration(), temp.get_price(), temp.get_quantity());
		else if (option == 2)
			deletes();
		else if (option == 3)
		{
			break;
		}
		else
			cout << "Invalid option\n";
	}
}

void Controller::update()
{
	cout << "~Update med~\n";

	string n;
	double c;
	double p;

	cout << "Name: ";
	cin >> n;

	cout << "Concentration: ";
	cin >> c;

	cout << "New price: ";
	cin >> p;

	Medicine temp = get_element(n, c);
	update_med(n, c, p);

	int option = -1;
	cout << "\n1.UNDO\n";
	cout << "2.REDO\n";
	cout << "3.PASS\n";


	while (option != 3)
	{
		cout << "Option: ";
		cin >> option;
		if (option == 1)
		{
			update_med(n, c, temp.get_price());
		}
		else if (option == 2)
			update();
		else if (option == 3)
		{
			break;
		}
		else
			cout << "\nInvalid option\n";
	}
}

void Controller::search_by_name2()
{
	cout << "~Search meds by full name or a part of the name~\n";

	string refrence;

	cout << "Enter name:";
	cin >> refrence;

	//search_by_name(refrence);
}

void Controller::search_by_quantity2()
{
	cout << "~Search meds with a quantity lower than one given~\n";

	int qtt;

	cout << "Enter <Quantity: ";
	cin >> qtt;

	//search_by_quantity(qtt);
}
/*
void Controller::group_by_price()
{
	Repository::group_meds_by_price();
}
*/