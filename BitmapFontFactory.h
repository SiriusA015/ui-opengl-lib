#ifndef BITMAPFONTFACTORY_H
#define BITMAPFONTFACTORY_H

#include "Font.h" 

namespace demo
{
	class BitmapFont;

	class BitmapFontFactory : public ui::AbstractFontFactory
	{
	public:
		ui::Font * createFont(const std::string &font, std::size_t size);
		BitmapFontFactory();
		~BitmapFontFactory();
	private:
		BitmapFont *bitmapFont;
	};
}

#endif