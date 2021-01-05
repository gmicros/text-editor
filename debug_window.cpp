#include "debug_window.h"

DebugWindow::DebugWindow(int h, int w, int y, int x) {
	win = newwin(h, w, y, x); 
	box(win, 0, 0);
	wrefresh(win);
	refresh();
}

void DebugWindow::Debug(std::string msg) {
	werase(win);
	wprintw(win, "%s", msg.c_str());
	wrefresh(win);	
}
