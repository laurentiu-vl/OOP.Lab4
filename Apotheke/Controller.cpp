#include "Controller.h"
#include <iostream>
#include <string>

using namespace std;

Controller::Controller(Repository repos)
{
	this->repos = repos;
}

Controller::Controller()
{

}

Controller::~Controller()
{

}
void Controller::add()
{
	cout << "\n~ADD MED~\n";

	string n;
	double c;
	double p;
	int q;

	cout << "Name: ";
	cin >> n;

	cout << "Concentration: ";
	cin >> c;

	cout << "Quantity: ";
	cin >> q;

	cout << "Price: ";
	cin >> p;

	bool cases = this->repos.add_med(n, c, q, p);

	int option = -1;

	while (option != 3)
	{
		cout << "\n~FOR LAST ACTION~\n";
		cout << "1.UNDO\n";
		cout << "2.REDO\n";
		cout << "3.PASS\n";
		cout << "Option: ";
		cin >> option;

		if (option == 1 && cases == true)
		{
			this->repos.delete_med(n, c);
			break;
		}
		else if (option == 1 && cases == false)
		{
			bool useless = this->repos.add_med(n, c, -q, p);
			break;
		}
		else if (option == 2)

			add();

		else if (option == 3)
		{
			break;
		}
		else
			cout << "\nINVALID OPTION!\n";
	}
}

void Controller::deletes()
{
	cout << "\n~DELETE MED~\n";

	string n;
	double c;

	cout << "Name: ";
	cin >> n;

	cout << "Concentration: ";
	cin >> c;

	Medicine temp = this->repos.get_element(n, c);

	this->repos.delete_med(n, c);

	int option = -1;

	while (option != 3)
	{
		cout << "\n1.UNDO\n";
		cout << "2.REDO\n";
		cout << "3.PASS\n";
		cout << "Option: ";
		cin >> option;

		if (option == 1)
		{
			this->repos.add_med(temp.get_name(), temp.get_concentration(), temp.get_price(), temp.get_quantity());
			break;
		}
		else if (option == 2)

			deletes();

		else if (option == 3)
		{
			break;
		}
		else
			cout << "\nInvalid option\n";
	}
}

void Controller::update()
{
	cout << "\n~UPDATE MED~\n";

	string n;
	double c;
	double p;

	cout << "Name: ";
	cin >> n;

	cout << "Concentration: ";
	cin >> c;

	cout << "New price: ";
	cin >> p;

	Medicine temp = this->repos.get_element(n, c);

	this->repos.update_med(n, c, p);

	int option = -1;

	while (option != 3)
	{
		cout << "\n1.UNDO\n";
		cout << "2.REDO\n";
		cout << "3.PASS\n";
		cout << "Option: ";
		cin >> option;
		if (option == 1)
		{
			this->repos.update_med(n, c, temp.get_price());
			break;
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
	cout << "\n~SEARCH MEDS BY FULL NAME OR A PART OF THEIR NAME~\n";

	string refrence;

	cout << "Enter name:";
	cin >> refrence;

	bool exeption = this->repos.search_by_name(refrence);
	if (exeption == false)
	{
		this->repos.list_all();
	}
}

void Controller::search_by_quantity2()
{
	cout << "\n~SEARCH MEDS WITH A QUANTITY LOWER THAN ONE GIVEN~\n";

	int qtt;

	cout << "Enter Quantity: ";
	cin >> qtt;

	bool useless = this->repos.search_by_quantity(qtt);
}
/*
void Controller::group_by_price2()
{
	cout << "\nMEDS LISTED BY PRICE(low to high)";
	Repository repos = this->repos.group_by_price();
	for (int i = 0; i < repos.meds.size(); i++)
	{
		repos.meds[i].return_string();
	}
}
*/