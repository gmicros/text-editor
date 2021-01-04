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
	refresh();
	
	// quit the TE with the Esc key	
	while ((ch = getch()) != 27) {
		switch(ch)
		{
			// BACKSPACE
			case 127: {
				int y, x;
				getyx(stdscr,y,x);
				mvdelch(y,x-1);

				// TODO(gmicros): handle deleting a line
				break;
			}
			// ENTER
			case 10:
				printw("\n");
				break;
			// REGULAR CHARACTER
			default:
				printw("%c", ch);
	
		}

		// update display and get next char
		refresh();
	}
	
	endwin();
	
	return 0;
}
