#include "MedicineDomain.h"
#include "UI.h";
#include <iostream>


using namespace std;

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

	while (option != 8)
	{
		cin >> option;

		if (option == 1)
			add();

		else if (option == 2)
			deletes();

		else if (option == 3)
			update();
/*
		else if (option == 4)
			//list_meds();
*/
		else if (option == 5)
			search_by_name2();

		else if (option == 6)
			search_by_quantity2();
/*
		else if (option == 7)
			group_by_price();
*/
		else if (option == 8)
			break;

		else
			cout << "\nInvalid option!";
	}
}