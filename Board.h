#ifndef BOARD_H_
#define BOARD_H_

        void addBall()
        void SetupDisplay(int &width, int &height);
        void ClearDisplay();
        void ShutdownDisplay();
        void DrawBall(double oldX, double oldY, double newX,
        double newY, int ballColorLevel);

#endif
