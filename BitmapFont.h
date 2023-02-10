#ifndef BITMAPFONT_H
#define BITMAPFONT_H

#include "Font.h"
#include "SDL_Image.h"
#include "includes.h" 

namespace demo
{
	class BitmapFont : public ui::Font
	{
	public:
		BitmapFont();
		~BitmapFont();
		const std::string getFontName() const;
		std::size_t getSize() const;
		ui::util::Dimension getStringBoundingBox(const std::string &text) const;
		void drawString(int x, int y, const std::string &text);
	private:
		static const int textureWidth = 256;
		static const int textureHeight = 256;
		//GLubyte texture[textureWidth][textureHeight][4];
		GLuint textureId;
		GLuint base;
	};
}

#endif