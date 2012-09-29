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
	bool GuiContext::gatherInput() const
	{
		bool isRunning = true;

		SDL_Event event;

		int mx, my;
		SDL_GetMouseState(&mx,&my);

		guiInstance->importMouseMotion(mx,my);

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				{
					isRunning = false;
					break;
				}
				case SDL_MOUSEBUTTONUP:
				{
					guiInstance->importMouseReleased(1);
					break;
				}
				case SDL_MOUSEBUTTONDOWN:
				{
					guiInstance->importMousePressed(1);
					break;
				}
				case SDL_KEYDOWN:
				{
					guiInstance->importKeyPressed(event.key.keysym.unicode,event.key.keysym.mod);
					break;
				}
				case SDL_KEYUP:
				{
					guiInstance->importKeyReleased(event.key.keysym.sym,event.key.keysym.mod);
					break;
				}
			}
		}
		return isRunning;
	}
}