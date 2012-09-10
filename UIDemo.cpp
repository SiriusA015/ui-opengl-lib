#include ".\UIDemo.h"
#include ".\GuiContext.h"
#include ".\includes.h"

namespace demo
{
	UIDemo::UIDemo()
		:	guiContext(0)
	{
		int width	= 800;
		int height	= 600;
		bool fullscreen = false;
		int bpp = 32;
		int flags = 0;

		if(SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			fprintf(stderr, "Video initialization failed: %s\n", SDL_GetError( ));
		}

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		if(!fullscreen)
		{
			flags = SDL_OPENGL;
		}
		else
		{
			flags = SDL_OPENGL | SDL_FULLSCREEN;
		}
		
		if(SDL_SetVideoMode(width, height, bpp, flags) == 0)
		{
			fprintf( stderr, "Video mode set failed: %s\n", SDL_GetError());
		}
		SDL_WM_SetCaption("UIDemo v0.01 - by Bram Stein",0);

		guiContext = new GuiContext();
	}

	UIDemo::~UIDemo()
	{
		delete guiContext;
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	}

	void UIDemo::run() const
	{
		while(guiContext->isRunning())
		{
			SDL_GL_SwapBuffers();
			SDL_Delay(0);
		}
	}
}

int main(int argc, char* argv [])
{
	using namespace demo;

	std::auto_ptr<UIDemo> uiDemo(new UIDemo());

	uiDemo->run();

	return 0;
}