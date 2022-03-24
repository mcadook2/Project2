#include<Board.h>
#include<curses.h>

#define MAXCHARS 10
#define BALL_CHARACTER 'O'

const int COLOR_LEVELS[MAXCHARS] = {COLOR_WHITE, COLOR_WHITE, COLOR_YELLOW,
                                     COLOR_GREEN, COLOR_GREEN, COLOR_CYAN,
                                     COLOR_BLUE, COLOR_BLUE, COLOR_MAGENTA,
                                     COLOR_RED};


//Sets the x and y position, dx and dy velocity, and colorlevel
void Ball::SetBallInfo(double newx, double newy, int newcolorlevel, double newDX, double newDY) {
        x = newx; 
        y = newy;
        dx = newDX;
        dy = newDY;
        colorlevel = newcolorlevel;
    }

double Ball::GetX() const { 
  return x; //returns the x postion
  }

double Ball::GetY() const { 
  return y; //returns the y position
  }

double Ball::GetColorLvl() const { 
  return colorlevel; //returns the color level position
  }

double Ball::GetDX() const {
  return dx; //returns the dx velocity
}

double Ball::GetDY() const {
  return dy; //returns the dy velocity
}

void Ball::SetupDisplay(int &width, int &height, int colorlevel) {
    initscr(); //ncurses: Determines the type of terminal, setup ncurses
    cbreak(); //ncurses: Disable line buffering
    noecho(); //ncurses: Don't echo input back to the screen

    //Set the width and heigth of the field
    height = LINES - 1;
    width = COLS - 1;

    //Clear the display
    clear();

    //Setup the colors
    start_color();
    
        init_pair(colorlevel+1, COLOR_LEVELS[colorlevel], COLOR_BLACK);

    refresh(); //ncurses: refresh the screen
}

void Ball::ClearDisplay() {
    clear();
}

void Ball::ShutdownDisplay(){
    endwin();
}

void Ball::DrawBall(double oldX, double oldY, double newX, double newY, int ballColorLevel) {
  // If the old ball position is positive, erase it
  if ( (oldX > 0) && (oldY > 0) ) {
    //attron(COLOR_PAIR(0));  // Set color to Black
    //mvaddch((int)oldY, (int)oldX, ' ');  // ncurses:  draw a blank space
    attron(COLOR_PAIR(MAXCHARS-1));      // Set color to Red
    mvaddch((int)oldY, (int)oldX, '.');  // ncurses:  draw a tracer as a '.'
  }

  // If the new ball position is positive, draw it
  if ( (newX > 0) && (newY > 0) ) {
    attron(COLOR_PAIR(ballColorLevel));  // Set color to whatever we're given
    mvaddch((int)newY, (int)newX, BALL_CHARACTER);  // ncurses:  draw character
  }

  refresh();  // ncurses: refresh the screen
}
