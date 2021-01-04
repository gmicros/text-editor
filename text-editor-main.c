// make a text editor that supports a movable cursor and selecting
// inserting and deleting text.
//

#include <ncurses.h>

WINDOW *debug_win;

void print_debug(char* msg){
	werase(debug_win);
	wprintw(debug_win, "%s", msg);
	wrefresh(debug_win);
	
}

int main() {
	int ch;
	initscr();		// Start curses mode
	raw();			// line buffering disabled
	keypad(stdscr, TRUE);	// get arrows and F-keys
	noecho();		// dont echo while we getch
	
	// debug output window
	int startx, starty, height, width;
	height = 3;
	width = 10;
	starty = LINES-height;
	startx = COLS - width;
	debug_win = newwin(height, width, starty, startx);
	box(debug_win, 0, 0);
	wrefresh(debug_win);
	
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
				print_debug("BACKSPACE");
				// TODO(gmicros): handle deleting a line
				break;
			}
			// ENTER
			case 10:
				printw("\n");
				print_debug("ENTER");
				break;
			// REGULAR CHARACTER
			default:
				printw("%c", ch);
				char str[30];
				sprintf(str, "input: %c\n", ch);
				print_debug(str);
	
		}

		// update display and get next char
		refresh();
	}
	
	endwin();
	
	return 0;
}
