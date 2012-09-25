#include ".\GuiContext.h"
#include ".\includes.h"

namespace demo
{
	GuiContext::GuiContext()
		:	guiInstance(new ui::Gui()),
			mainGui(0),
			fontFactory(0)
	{
		// SDL specific stuff
		SDL_EnableUNICODE(1);
		SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
		SDL_PumpEvents();

		// and finally add it to the Gui instance
		guiInstance->addFrame(mainGui);	
	}

	GuiContext::~GuiContext()
	{
	}

	bool GuiContext::isRunning()
	{
		if(gatherInput())
		{
			update();
			paint();

			return true;
		}
		else
		{
			return false;
		}
	}

}