#include "MedikamentDomain.h"
#include <iostream>
#include <string>

using namespace std;

/*
MedikamentDomain::MedikamentDomain()
{

}
*/

MedikamentDomain::MedikamentDomain(string nname, double nkonzentration, double nmenge, double npreis)
{
	this->name = nname;
	this->menge = nmenge;
	this->konzentration = nkonzentration;
	this->preis = npreis;
}

string MedikamentDomain::getName()
{
	return this->name;
}

double MedikamentDomain::getKonzentration()
{
	return this->konzentration;
}

double MedikamentDomain::getMenge()
{
	return this->menge;
}

double MedikamentDomain::getPreis()
{
	return this->preis;
}

void MedikamentDomain::setName(string xname)
{
	this->name = xname;
}

void MedikamentDomain::setKonzentration(double xkonzentration)
{
	this->konzentration = xkonzentration;
}

void MedikamentDomain::setMenge(double xmenge)
{
	this->menge = xmenge;
}

void MedikamentDomain::setPreis(double xpreis)
{
	this->preis = xpreis;
}