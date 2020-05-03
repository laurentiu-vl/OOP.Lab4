#pragma once
#include "MedicineDomain.h"
#include <vector>

using namespace std;

class Repository
{
public:

	vector <Medicine> meds;

	Repository();

	~Repository();

	//adds a medicine to the repository
	void add_med(string name, double concentration, double quantity, double price);

	//deletes a medicine from the repository
	void delete_med(string name, double concentration);

	//update a medicine from the repository
	void update_med(string name, double concentration, double price);

	Medicine get_element(string name, double concentration);

/*
	bool search_by_name(string Z);

	bool search_by_quantity(int QQQQ);

	bool group_by_price();
	*/
};

