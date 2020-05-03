#pragma once
#include <iostream>
#include <string>

using namespace std;

class MedikamentDomain
{
	private:
		string name;

		double konzentration;
		
		double menge;
		
		double preis;

	public: /// Information about Drugs
		MedikamentDomain();

		/// Constructor
		MedikamentDomain(string, double, double, double);

		/// return the name as string
		string getName();

		/// set a new name as string
		void setName(string);

		/// return the concentration as double
		double getKonzentration();

		/// set a new concentration as double
		void setKonzentration(double);

		/// return the quantity as double
		double getMenge();

		/// set a new quantity as double
		void setMenge(double);

		/// return the price as double
		double getPreis();

		/// set a new price as double
		void setPreis(double);
};