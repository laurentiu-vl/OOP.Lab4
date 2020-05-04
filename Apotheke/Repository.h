#pragma once
#include "MedicineDomain.h"
#include <string.h>
#include <vector>

using namespace std;

class Repository
{
private:

	vector <Medicine> meds;

public:

	//vector <Medicine> meds;

	Repository();

	~Repository();

	//adds a medicine to the repository
	bool add_med(string name, double concentration, double quantity, double price);

	//deletes a medicine from the repository
	void delete_med(string name, double concentration);

	//update the price of a medicine from the repository
	void update_med(string name, double concentration, double price);

	//return element from repository based on name and concentration
	Medicine get_element(string name, double concentration);

	//SEARCH ALL MEDS BY FULL NAME OR A PART OF THEIR NAME
	bool search_by_name(string find);

	//SEARCH ALL MEDS WITH A QUANTITY LOWER THAN ONE GIVEN
	bool search_by_quantity(double less_than);

	//LIST ALL MEDS BY PRICE(low to high)
	Repository group_by_price();

	//LIST ALL MEDS
	void list_all();
};

