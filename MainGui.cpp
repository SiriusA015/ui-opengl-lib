#include ".\MainGui.h"

namespace demo
{
	MainGui::MainGui()
		:	ui::Frame(0,0,800,600)
	{
		menuBar = new ui::MenuBar();

		menu1 = new ui::Menu("Menu 1");
		menu2 = new ui::Menu("Menu 2");
		menu3 = new ui::Menu("Menu 3");

		menuItem1 = new ui::MenuItem("MenuItem 1");
		menuItem2 = new ui::MenuItem("MenuItem 2");
		menuItem3 = new ui::MenuItem("MenuItem 3");
		menuItem4 = new ui::MenuItem("MenuItem 4");
		menuItem5 = new ui::MenuItem("MenuItem 5");
		menuItem6 = new ui::MenuItem("MenuItem 6");

		menu1->add(menuItem1);
		menu1->add(menuItem2);
		menu1->add(menuItem3);

		menu2->add(menuItem4);
		menu2->add(menuItem5);

		menu3->add(menuItem6);

		menuBar->add(menu1);
		menuBar->add(menu2);
		menuBar->add(menu3);

		setMenuBar(menuBar);
	}

	MainGui::~MainGui()
	{
		delete menuItem1;
		delete menuItem2;
		delete menuItem3;
		delete menuItem4;
		delete menuItem5;
		delete menuItem6;

		delete menu1;
		delete menu2;
		delete menu3;

		delete menuBar;
	}
}