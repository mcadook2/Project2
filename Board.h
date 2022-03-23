#ifndef BOARD_H_
#define BOARD_H_

class Ball {
    protected:    
    int x = 10;
    int y = 10;
    int colorlevel = 2;
    double ballDX = 1;
    double ballDY = 1;
    public:
        void addBall()
        void SetupDisplay(int &width, int &height);
        void ClearDisplay();
        void ShutdownDisplay();
        void DrawBall(double oldX, double oldY, double newX,
        double newY, int ballColorLevel);

}

#endif