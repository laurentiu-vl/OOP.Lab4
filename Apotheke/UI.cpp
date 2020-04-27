#include "UI.h";
#include <iostream>
#include "MedikamentDomain.h"

using namespace std;

UI::UI()
{
}

UI::UI()
{
}

void UI::menu()
{
	cout << "~MENU~\n";

	int option = -1;

	cout << "1.Add medicine\n"
		<< "2.Delete medicine\n"
		<< "3.Update medicine\n"
		<< "4.List all medicines\n"
		<< "5.List all medicines that contain a string\n"
		<< "6.List all medicines with lower quantity than a given number\n"
		<< "7.List all medicines based on price (small to big)\n"
		<< "8.Quit\n";

	while (opt != 8)
	{
		cin >> opt;

		if (opt == 1)
			Controller::add_med();

		else if (opt == 2)
			Controller::delete_med();

		else if (opt == 3)
			Controller::update_med();

		else if (opt == 4)
			Controller::list_meds();

		else if (opt == 5)
			Controller::search_med_name();

		else if (opt == 6)
			Controller::search_med_quantity();

		else if (opt == 7)
			Controller::group_by_price();

		else if (opt == 8)
			break;

		else
			cout << "\nInvalid option!";
	}
}