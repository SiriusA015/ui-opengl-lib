#include ".\BitmapFontFactory.h" 
#include ".\BitmapFont.h" 

namespace demo
{
	ui::Font * BitmapFontFactory::createFont(const std::string &font, std::size_t size)
	{
		// we ignore all request and just return our default font (bitmap, fixed size)..
		return bitmapFont;
	}

	BitmapFontFactory::BitmapFontFactory()
	{
		bitmapFont = new BitmapFont();
	}

	BitmapFontFactory::~BitmapFontFactory()
	{
		delete bitmapFont;
	}
}