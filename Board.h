#ifndef BOARD_H_
#define BOARD_H_

class Ball {
    protected:    
    double x = 10;
    double y = 10;
    double dx = 1;
    double dy = 1;
    int colorlevel = 2;
    public:
    void SetBallInfo(double newx, double newy, int newcolorlevel, double newDX, double newDY);
    double GetX() const;
    double GetY() const;
    double GetDX() const;
    double GetDY() const;
    double GetColorLvl() const;
    void SetupDisplay(int &width, int &height, int colorlevel);
    void ClearDisplay();
    void ShutdownDisplay();
    void DrawBall(double oldX, double oldY, double newX, double newY, int ballsColor);

};

#endif
