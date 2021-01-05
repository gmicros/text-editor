// make a text editor that supports a movable cursor and selecting
// inserting and deleting text.
//

#include "debug_window.h"

int main() {
	// state of the editor
	int num_lines = 0;
	int line_length[100] = {};
		
	// setup ncurses
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
	DebugWindow debug_win(height, width, starty, startx);

	debug_win.Debug("WELCOME");	

	int ch;
	// quit the TE with the Esc key	
	while ((ch = getch()) != 27) {
		int y, x;
		getyx(stdscr, y, x);
		switch(ch)
		{
			case KEY_LEFT:
				move(y, x-1);
				break;
			case KEY_UP:
				move(y-1,x);
				break;
			case KEY_RIGHT:
				move(y,x+1);
				break;
			case KEY_DOWN:
				move(y+1,x);
				break;
			// BACKSPACE
			case 127: {
				mvdelch(y,x-1);
				line_length[y]--;
				if (x == 0) {
					move(y-1,line_length[y-1]);
				}
				debug_win.Debug("BACKSPACE");
				// TODO(gmicros): handle deleting a line
				break;
			}
			// ENTER
			case 10:
				printw("\n");
				debug_win.Debug("ENTER");
				num_lines++;
				break;
			// REGULAR CHARACTER
			default:
				printw("%c", ch);
				char str[30];
				sprintf(str, "input: %c\n", ch);
				debug_win.Debug(str);
				line_length[y]++;
				
	
		}

		// update display and get next char
		refresh();
	}
	debug_win.Debug("EXITING");	
	endwin();
	
	return 0;
}
