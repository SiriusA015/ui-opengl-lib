#ifndef UIDEMO_H
#define UIDEMO_H

#include <memory>

namespace demo
{
	class GuiContext;

	class UIDemo
	{
	public:
		UIDemo();
		~UIDemo();
		void run() const;
	private:
		GuiContext *guiContext;
	};
}

#endif