all:
	g++ -o text-editor text-editor-main.c debug_window.cpp -lncurses

clean: 
	rm text-editor
