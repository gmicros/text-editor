all:
	g++ -o text-editor text-editor-main.cpp debug_window.cpp -lncurses

clean: 
	rm text-editor
