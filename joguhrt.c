#define _GNU_SOURCE

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>




void printline( int starty, int startx,int color, char *string)
{	
	attron(COLOR_PAIR(color));
	mvwprintw(stdscr, starty, startx, "%s", string);
	refresh();
	attroff(COLOR_PAIR(color));
}

int main(){
	initscr();                      /* Start curses mode              */
	raw();                          /* Line buffering disabled      */
        keypad(stdscr, TRUE);           /* We get F1, F2 etc..          */
        noecho();                       /* Don't echo() while we do getch */
	if(has_colors() == FALSE)
        {       endwin();
                printf("Your terminal does not support color\n");
                exit(1);
        }
        start_color();                  /* Start color                  */
	
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	
	char* joguhrt = "Joguhrtbecher!!";

	for(int i =0; i< (COLS * LINES); i+=15){
		printline((int)(i/COLS) , i % COLS, i % 7, joguhrt);
		usleep(1000);

	}	

	/*for(int j = 0; j < COLS ; j+=15){
		for(int i = 0; i < LINES; i++){
			printline(i, j, (i+j) % 7, joguhrt);
			usleep(1000);
		}
	}	
	*/
        getch();                        /* Wait for user input */
        endwin();                       /* End curses mode                */
	
		

	return 0;
}


