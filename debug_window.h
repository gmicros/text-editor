#include <string>

#include <ncurses.h>

class DebugWindow 
{
		WINDOW *win;
	public:
		DebugWindow(int h, int w, int y, int x);
		void Debug(std::string msg);
};
