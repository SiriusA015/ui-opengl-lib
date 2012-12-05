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

	void GuiContext::paint() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		// go to ortho
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0,800,600,0);
		glMatrixMode(GL_MODELVIEW);

		
		// paint the Gui
		guiInstance->paint();

		// switch back
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	}

	void GuiContext::update()
	{
		lastFrameIndex = thisFrameIndex;
		thisFrameIndex = SDL_GetTicks();
		deltaTime = ((float)(thisFrameIndex-lastFrameIndex))/1000.0f;

		// print FPS counter...
		char s[8];
		sprintf(s,"%3.0ffps", 1/deltaTime);

		SDL_WM_SetCaption(s,0);

		guiInstance->importUpdate(deltaTime);
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