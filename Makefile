all:
	gcc -o text-editor text-editor-main.c -lncurses

clean: 
	rm text-editor
