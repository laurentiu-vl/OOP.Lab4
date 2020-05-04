#pragma once
#include "Repository.h"
class Controller: public Repository
{
private:
	Repository repos;

public:
	Controller(Repository repos);

	Controller();

	~Controller();

	//adds medicine
	void add();

	//deletes medicine
	void deletes();

	//updates name, concentration, price, quantity
	void update();

	//search meds by name
	void search_by_name2();

	//search by quantity
	void search_by_quantity2();

	//print meds grouped by price
	void group_by_price2();
};