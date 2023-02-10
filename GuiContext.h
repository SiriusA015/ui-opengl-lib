#ifndef GUICONTEXT_H
#define GUICONTEXT_H

#include ".\includes.h"
#include ".\MainGui.h"
#include ".\BitmapFontFactory.h"
#include "Gui.h"

namespace demo
{
	class GuiContext
	{
	public:
		GuiContext();
		bool isRunning();
		~GuiContext();
	private:
		void paint() const;
		bool gatherInput() const;
		void update();

		float deltaTime;
		unsigned int lastFrameIndex;
		unsigned int thisFrameIndex;
		std::auto_ptr<ui::Gui> guiInstance;
		MainGui *mainGui;
		BitmapFontFactory *fontFactory;

	};
}

#endif