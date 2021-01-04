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
	
	ch = getch();	
	// quit the TE with the Esc key	
	while (ch != 27) {
		// just print alphanumeric
		if (ch >= ' ' && ch <= '~') {
			printw("%c", ch); 
		}

		// update display and get next char
		refresh();
		ch = getch();
	}
	
	endwin();
	
	return 0;
	
}
