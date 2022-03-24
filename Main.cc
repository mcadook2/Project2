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
#else <unistd.h>
#endif

void StepBall(double &ballsY, double &ballsY, double &ballDX,
                double &ballDY, int ballColor, int width, int height) {
    double ballsX = ballsX + ballDX; //moves the ball forward/backwards by dx
    double ballsY = ballsY + ballDY; //moves the ball up/down by dy

    if (ballsX < 1) {
        ballsX = 1; //put it at the wall
        ballDX *= -1.0; //bounces ball
    }

    if (ballsX > width) {
        ballsX = width; //put it at the wall
        ballDX *=-1.0; //bounces ball
    }

    if (ballsY < 1) {
        ballsY = 1; //put it at the wall
        ballDY *= -1.0; //bounces ball
    }
    if (ballsY > height) {
        ballsY = height; //put it at the wall
        ballDY *= -1.0;
    }

    ballX = ballsX;
    ballY = ballsY;
 }

void MillisecondsDelay(int millisec) {
    #ifdef _Win32
        Sleep(millisec) //Takes milliseconds
    #else
        usleep(millisec*1000) //Takes nanoseconds
    #endif
}

int main() {

    int ballNum;
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

    } while (count != ballNums):
    
    for (int ball = 0; ball < ballNums; ball++) { 

        currBall = BallList.at(ball);
        ballsX = currBall.GetX();
        ballsY = currBall.GetY();
        ballColor = currBall.GetColorLvl();
      
        
        //clears the display for the ASCII art
        myBall.SetupDisplay(width, height, ballsColor);
      
        myBall.DrawBall(-1, -1, ballsX, ballsY, ballColor);
        getchar();
    }

    for(int step = 0; step<maxSteps; step++) {
        for (int ball = 0; ball < ballNums; ball++) { 

            currBall = BallList.at(ball));
            ballsX = currBall.GetX();
            ballsY = currBall.GetY();
            ballsDX = currBall.GetDX();
            ballsDY = currBall.GetDY();
            ballColor = currBall.GetColorLvl();
            
            MillisecondsDelay(50);

            
            double oldX = ballsX;
            double oldY = ballsY;

            StepBall(ballsX, ballsY, ballsDX, ballsDY, ballsColor,
            width, height);
            myBall.DrawBall(oldX, oldY, ballsX, ballsY, ballsColor);
        }
    }

    myBall.ShutdownDisplay();

    cout << "...Program Ended." << endl;
    cout << "Display Dim: " << width << " " << height << endl;

    return 0;
}
