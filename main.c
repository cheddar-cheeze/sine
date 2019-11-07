//copyright 2019 cheddar-cheeze <cheddar@jiyu.moe> all rights reserved
#include <ncurses.h>

#include "io.h"

int main(void)
{
	WINDOW * root =initscr();
	noecho();
	io_loop(root);
	endwin();
	return 0;
}
