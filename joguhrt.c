#define _GNU_SOURCE

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct rgb{
	short r;
	short g;
	short b;
};


void printline( int starty, int startx, int color,  char *string)
{	
	attron(COLOR_PAIR(color));
	//color_set(2, 0);
	mvwprintw(stdscr, starty, startx, "%s", string);
	refresh();
	attroff(COLOR_PAIR(1));
	(void) color;
	
}

void update_color(struct rgb* color, int i){
	
	color->r = (i)%1000;
	color->g = (i)%1000;
	color->b = (i)%1000;
	init_color(i, color->r, color->g, color->b);
	init_pair(i, i, COLOR_BLACK);

}

int getlength(char* input){
	int length = 0;
	while(input[length] != 0){
		length++;
	}
	return length;
}

void start(){
	initscr();                      /* Start curses mode              */
	cbreak();                          /* Line buffering disabled      */
        keypad(stdscr, TRUE);           /* We get F1, F2 etc..          */
        echo();                       /* Don't echo() while we do getch */
 
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
	mvaddstr(5, 5, "Hallo");	
	
}

int main(int argc, char *argv[]){
	if(argc <1)
		return -1;
	size_t size = 0;
	for(size = 0; argv[size] != '\0'; size++)
		;
	start();
	char joguhrt[size];
	//joguhrt = (char*)malloc(size);
	strcpy(joguhrt, argv[1]);
	
		
	//getnstr(joguhrt,COLS);
	//int length = getlength(joguhrt);
	
	noecho();
	clear();
	refresh();
	//struct rgb col={1,1,1};
	//update_color(&col, 7);
	/*for(int i =0; i< (COLS * LINES); i+=length){
		printline((int)(i/COLS) , i ,(int)(i/length) +7,  joguhrt);
		update_color(&col, ((int)i/length) +7);
		usleep(1000);

	}*/	
	
	int color = 0;
	while(1){
		color++;
		for(int j = 0; j < COLS ; j+=(size+1)){
			for(int i = 0; i < LINES; i++){
				printline(i, j, (i+j+color) % 7, joguhrt);
				usleep(1000);
			}
		}
		//clear();
		if(color > 200000){
			color = 0;
		} 
	}	
	
        getch();                        /* Wait for user input */
        endwin();                       /* End curses mode                */
	
		

	return 0;
}


