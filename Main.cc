#include<iostream>
#include<vector>
#include<Board.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

//For functions that violate the ANSI standard
//we use windows.h but the rest uses unistd.h
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void StepBall(double &ballsX, double &ballsY, double &ballDX,
                double &ballDY, int ballsColor, int width, int height) {
    double newX = ballsX + ballDX; //moves the ball forward/backwards by dx
    double newY = ballsY + ballDY; //moves the ball up/down by dy

    if (newX < 1) {
        newX = 1; //put it at the wall
        ballDX *= -1.0; //bounces ball
    }

    if (newX > width) {
        newX = width; //put it at the wall
        ballDX *=-1.0; //bounces ball
    }

    if (newY < 1) {
        newY = 1; //put it at the wall
        ballDY *= -1.0; //bounces ball
    }
    if (newY > height) {
        newY = height; //put it at the wall
        ballDY *= -1.0;
    }

    ballsX = newX;
    ballsY = newY;
 }

void MillisecondsDelay(int millisec) {
    #ifdef _Win32
        Sleep(millisec); //Takes milliseconds
    #else
        usleep(millisec*1000); //Takes nanoseconds
    #endif
}

int main() {
  //variable for the numbers of balls
    int ballNums;
  
    double ballsX = 10;
    double ballsY = 10;
    double ballsDX = 1;
    double ballsDY = 1;
    double ballsColor = 2;

    int width;
    int height;
    //int maxSteps = 5; //practice code
    int maxSteps = 500;
    int count = 0;

  //vector class for the balls  
  vector<Ball> BallList;
  
  //classes for new balls and the current ball
    Ball newBall;
    Ball currBall;

    cout << "How many balls do you want to create?";
    cin >> ballNums; //grabs the amount of balls the user wants

    do { //ask the user about information in a do while loop

        cout << "What is the initial X and Y position of ball"<< count + 1 << "? ";
        cin >> ballsX >> ballsY;
        cout << "What is the initial dX and and dY velocity of the ball" << count + 1 << "? ";
        cin >> ballsDX >> ballsDY;
        cout << "What is the color level of the ball" << count + 1 << "? ";
        cin >> ballsColor;

        newBall.SetBallInfo(ballsX, ballsY, ballsColor, ballsDX, ballsDY);
        BallList.push_back(newBall); //added the new ball to the list

        ++count;//makes the count go up one

    } while (count != ballNums); //loop continues until the count equals the amount of balls
  
  
    //clears the display for the ASCII art
  currBall.SetupDisplay(width, height);
  
  for (int a = 0; a < ballNums; a++) { 

    //makes the currball class equal the information from the current ball
    currBall = BallList[a];
    
    //grabs the informations from the currBall
    ballsX = currBall.GetX();
    ballsY = currBall.GetY();
    ballsColor = currBall.GetColorLvl();
    ballsDX = currBall.GetDX();
    ballsDY = currBall.GetDY();
      
    //cout << "Ball "<< a <<" creadted" << endl;
      
   //Draws the ball
    currBall.DrawBall(-1, -1, ballsX, ballsY, ballsColor);
   getchar();
  }
  
  //loops for maxSteps, moving the ball each time step
  for (int step = 0; step<maxSteps; step++) {
    
    //changes the current ball
    for(int b = 0; b < ballNums; b++){           
      
      //gives the information to the current ball class
      currBall = BallList[b];
    
      //grabs the current ball information
      ballsX = currBall.GetX();
      ballsY = currBall.GetY();
      ballsColor = currBall.GetColorLvl();
      ballsDX = currBall.GetDX();
      ballsDY = currBall.GetDY();
     
      //Slows down the sim
     MillisecondsDelay(50);
        
      //cout << "Moving Ball" << b;
      
      //Remember the old location of the ball
      double oldX = ballsX;
      double oldY = ballsY;
      
      //double newX = ballsX + 1;
      //double newY = ballsY + 1;
      
      //ballsX = newX;
      //ballsY = newY;
      
      //Moves the ball one time step
     StepBall(ballsX, ballsY, ballsDX, ballsDY, ballsColor, width, height);
      
      //Draw the new position of the ball, erase the old
      currBall.DrawBall(oldX, oldY, ballsX, ballsY, ballsColor);
      
      //saves the new information in current ball class
      currBall.SetBallInfo(ballsX, ballsY, ballsColor, ballsDX, ballsDY);
      
      //updated the ball's information in the vector
      BallList.at(b) = currBall;
      
      
    //cout <<" Ball's Position: " << ballsX << " " << ballsY << endl;
    }     
  }
 
  currBall.ShutdownDisplay();
  cout << "...Program Ended." << endl;
  cout << "Display Dim: " << width << " " << height << endl;

  return 0;
}
