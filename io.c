//copyright 2019 cheddar-cheeze <cheddar@jiyu.moe> all rights reserved
#include <ncurses.h>
#include <menu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "data.h"

static int create_menu(WINDOW *win, const char *const_str)
{
	char *str = malloc(strlen(const_str) + 1);
	strlcpy(str, const_str, (strlen(const_str) + 1));

	char *choice;
	int key;
	ITEM **menu_items = NULL;
	MENU *menu;
	int r;

	for(int x=0;(choice = strtok_r(str, ";", &str)) != NULL; x++)
	{
		menu_items = reallocarray(menu_items, x + 1, (sizeof(ITEM *)));
		menu_items[x] = new_item(choice, "");
	}

	wclear(win);
	wmove(win, 0, 0);
	keypad(win, TRUE);
	menu = new_menu(menu_items);
	set_menu_win(menu, win);
	post_menu(menu);
	wrefresh(win);

	while((key = getch()))
	{
		switch(key)
		{
			case KEY_DOWN:
				menu_driver(menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(menu, REQ_UP_ITEM);
				break;
			case 10:
			{
				ITEM *cur = current_item(menu);
				r = (item_index(cur) + 1);
				unpost_menu(menu);
				free_menu(menu);
				
				for(int x=0; menu_items[x] != NULL; x++)
					free_item(menu_items[x]);
				
				free(menu_items);
				free(str);
				return r;
			}
				
		}
	}
	return 0;
}


void io_loop(WINDOW *win)
{
	const char **cur_section = sections[0];
	int cur_line = 0;
	while(cur_section != NULL)
	{
		while(cur_section[cur_line] != NULL)
		{
				switch(cur_section[cur_line][0])
				{
					case 'v':
						wclear(win);
						mvwprintw(win, 0, 0, "%s", &cur_section[cur_line][2]);
						wrefresh(win);
						wgetch(win);
						cur_line++;
						break;
					case 'q':
						cur_line = (create_menu(win, &cur_section[cur_line][2]) + cur_line);
						break;
					case 'g':
						cur_section = sections[atoi(&cur_section[cur_line][2])];
						cur_line=0;
						break;
					case 'i':
						break;
				}
		}
	}
}
