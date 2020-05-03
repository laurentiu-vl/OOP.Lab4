#include "Repository.h"
#include "MedicineDomain.h"
#include <iostream>
#include <string>

using namespace std;

Medicine::Medicine(string name, double concentration, double quantity, double price)
{
	this->name = name;
	this->concentration = concentration;
	this->price = price;
	this->quantity = quantity;
}

Medicine::Medicine()
{

};

Medicine::~Medicine()
{

};

string Medicine::get_name()
{ 
	return name; 
}

double Medicine::get_concentration()
{
	return concentration;
}

double Medicine::get_quantity()
{
	return quantity;
}

double Medicine::get_price()
{
	return price;
}


void Medicine::set_name(string n)
{
	name = n;
}

void Medicine::set_concentration(double c)
{
	concentration = c;
}

void Medicine::set_quantity(double q)
{
	quantity = q;
}

void Medicine::set_price(double p)
{
	price = p;
}

void Medicine::add_quantity(double q)
{
	quantity += q;
}

bool Medicine::operator< (Medicine temp) const
{
	return (this->name < temp.get_name());
}

bool Medicine::operator==(Medicine temp) const
{
	return ((this->name == temp.get_name()) && (this->concentration == temp.get_concentration()));
}