#include "Repository.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Repository::Repository() {}

Repository::~Repository() {}

void Repository::add_med(string name, double concentration, double quantity, double price)
{
	int i;
	for (i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name and meds[i].get_concentration() == concentration)
		{
			break;
		}

	if (i < meds.size())
	{
		meds[i].add_quantity(quantity);
	}
	else
	{
		Medicine temp(name, concentration, quantity, price);
		meds.push_back(temp);
	}

}

void Repository::delete_med(string name, double concentration)
{
	int i;
	for (i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name and meds[i].get_concentration() == concentration)
			break;

	meds.erase(meds.begin() + i);
}

void Repository::update_med(string name, double concentration, double price)
{
	for (int i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name and meds[i].get_concentration() == concentration)
		{
			meds[i].set_price(price);
			break;
		}
}

Medicine Repository::get_element(string name, double concentration)
{
	Medicine m;
	for (int i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name and meds[i].get_concentration() == concentration)
			return meds[i];

	return m;
}

//----------------------------------------------------------------
/*


*/