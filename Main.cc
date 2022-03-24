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
    int ballNums;
    double ballsX = 10;
    double ballsY = 10;
    double ballsDX = 1;
    double ballsDY = 1;
    double ballsColor = 2;

    int width;
    int height;
    int maxSteps = 500;
    int count = 0;

    vector<Ball> BallList;
    Ball newBall;
    Ball currBall;

    cout << "How many balls do you want to create?";
    cin >> ballNums;
    cout << ballNums << endl;

    do {

        cout << "What is the initial X and Y position of ball"<< count + 1 << "? ";
        cin >> ballsX >> ballsY;
        cout << "What is the initial dX and and dY velocity of the ball" << count + 1 << "? ";
        cin >> ballsDX >> ballsDY;
        cout << "What is the color level of the ball" << count + 1 << "? ";
        cin >> ballsColor;

        newBall.SetBallInfo(ballsX, ballsY, ballsColor, ballsDX, ballsDY);
        BallList.push_back(newBall);

        ++count;

    } while (count != ballNums);
    
    for (int a = 0; a < ballNums; a++) { 

        currBall = BallList.at(a);
        ballsX = currBall.GetX();
        ballsY = currBall.GetY();
        ballsColor = currBall.GetColorLvl();
      
        
        //clears the display for the ASCII art
        currBall.SetupDisplay(width, height);
      
        currBall.DrawBall(-1, -1, ballsX, ballsY, ballsColor);
        getchar();
    }
      for(int step = 0; step<maxSteps; step++) {
        for (int b = 0; b < ballNums; b++) { 

            currBall = BallList.at(b);
            ballsX = currBall.GetX();
            ballsY = currBall.GetY();
            ballsDX = currBall.GetDX();
            ballsDY = currBall.GetDY();
            ballsColor = currBall.GetColorLvl();
            
            MillisecondsDelay(50);

            
            double oldX = ballsX;
            double oldY = ballsY;

            StepBall(ballsX, ballsY, ballsDX, ballsDY, ballsColor, width, height);
            currBall.DrawBall(oldX, oldY, ballsX, ballsY, ballsColor);
        }
    }
  
    currBall.ShutdownDisplay();

    cout << "...Program Ended." << endl;
    cout << "Display Dim: " << width << " " << height << endl;

    return 0;
}
