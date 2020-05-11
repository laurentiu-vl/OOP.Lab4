#include "Repository.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

Repository::Repository() {}

Repository::~Repository() {}

void Repository::add_inmeds(int x)
{
	//meds.push_back(x);
}

Medicine Repository::get_medicina(int i) // de verificat aici laur
{
	return meds[i];
}

bool Repository::add_med(string name, double concentration, double quantity, double price)
{
	int i;
	for (i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name && meds[i].get_concentration() == concentration)
		{
			break;
		}

	if (i < meds.size())
	{
		meds[i].add_quantity(quantity);
		return false;
	}
	else
	{
		Medicine temp(name, concentration, quantity, price);
		meds.push_back(temp);
		return true;
	}
}

void Repository::delete_med(string name, double concentration)
{
	int i;
	for (i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name && meds[i].get_concentration() == concentration)
			break;

	meds.erase(meds.begin() + i);
}

void Repository::update_med(string name, double concentration, double price)
{
	for (int i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name && meds[i].get_concentration() == concentration)
		{
			meds[i].set_price(price);
			break;
		}
}

Medicine Repository::get_element(string name, double concentration)
{
	Medicine m;
	for (int i = 0; i < meds.size(); i++)
		if (meds[i].get_name() == name && meds[i].get_concentration() == concentration)
			return meds[i];
	return m;
}

bool Repository::search_by_name(string find)
{
	bool state = false;
	for (int i = 0; i < meds.size(); i++)
	{
		if (strstr(meds[i].get_name().c_str(), find.c_str()) != NULL)
		{
			state = true;
			meds[i].return_string();
		}
	}
	return state;
}

bool Repository::search_by_quantity(double less_than)
{
	bool state = false;
	for (int i = 0; i < meds.size(); i++)
	{
		if (meds[i].get_quantity() < less_than)
		{
			state = true;
			meds[i].return_string();
		}
	}
	return state;
}

vector <Medicine> Repository::group_by_price()
{
	for (int i = 0; i < meds.size() - 1; i++)
		for (int j = i + 1; j < meds.size(); j++)
			if (meds[i].get_price() > meds[j].get_price())
			{
				Medicine aux = meds[i];
				meds[i] = meds[j];
				meds[j] = aux;
			}

	vector <Medicine> temp;
	for (int i = 0; i < meds.size(); i++)
	{
		Medicine aux2 = meds[i];
		temp.push_back(aux2);
	}
	return temp;
}

void Repository::list_all()
{
	for (int i = 0; i < meds.size(); i++)
		meds[i].return_string();
}