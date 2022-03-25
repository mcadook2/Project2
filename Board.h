#ifndef BOARD_H_
#define BOARD_H_

class Ball {
    protected:    
    double x;
    double y;
    double dx;
    double dy;
    int colorlevel;
    public:
    void SetBallInfo(double newx, double newy, int newcolorlevel, double newDX, double newDY);
    double GetX() const;
    double GetY() const;
    double GetDX() const;
    double GetDY() const;
    double GetColorLvl() const;
    void SetupDisplay(int &width, int &height);
    void ClearDisplay();
    void ShutdownDisplay();
    void DrawBall(double oldX, double oldY, double newX, double newY, int ballsColor);

};

#endif
