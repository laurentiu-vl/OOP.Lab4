#include <iostream>
#include "Controller.h"
#include "UI.h"
#include "Repository.h"

using namespace std;
int main()
{
	Repository repos;
	Controller ctrl(repos);
	UI ui;
	ui.menu();
}
