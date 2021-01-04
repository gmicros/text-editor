// make a text editor that supports a movable cursor and selecting
// inserting and deleting text.
//

#include <ncurses.h>

int main() {
	int ch;
	initscr();		// Start curses mode
	raw();			// line buffering disabled
	keypad(stdscr, TRUE);	// get arrows and F-keys
	noecho();		// dont echo while we getch

	printw("Text editor:\n");
		
	while (ch = getch()) {
		if (ch == 27) {
			break;
		}
		printw("%c", ch); 

		refresh();
	}
	
	endwin();
	
	return 0;
	
}
