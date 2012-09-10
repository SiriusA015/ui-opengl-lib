#ifndef MAINGUI_H
#define MAINGUI_H

#include "component/Frame.h"
#include "component/MenuBar.h" 

namespace demo
{
	class MainGui : public ui::Frame
	{
	public:
		MainGui();
		~MainGui();
	private:
		ui::MenuBar *menuBar;

		ui::Menu *menu1;
		ui::Menu *menu2;
		ui::Menu *menu3;

		ui::MenuItem *menuItem1;
		ui::MenuItem *menuItem2;
		ui::MenuItem *menuItem3;
		ui::MenuItem *menuItem4;
		ui::MenuItem *menuItem5;
		ui::MenuItem *menuItem6;
	};
}

#endif