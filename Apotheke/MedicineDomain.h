#pragma once
#include <string>
#include <vector>
using namespace std;

class Medicine
{
private:

	string name;
	double concentration;
	double quantity;
	double price;

public:

	Medicine();

	~Medicine();

	Medicine(string name, double concentration, double quantity, double price);
	
	//getters
	string get_name();

	double get_concentration();

	double get_quantity();

	double get_price();

	//setters
	void set_name(string n);

	void set_concentration(double c);

	void set_quantity(double q);

	void set_price(double p);

	//increse quantity
	void add_quantity(double q);

	void minus_quantity(double q1);

	//operators for sorting
	bool operator< (Medicine temp) const;

	bool operator==(Medicine temp) const;

	//write a medicine on screen
	void return_string();
};