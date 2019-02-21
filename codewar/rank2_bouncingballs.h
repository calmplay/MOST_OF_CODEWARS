#pragma once
#include<iostream>

//you can choose to test the best function insteed of you own function by annotate the following define 
//#define MY_FUNCTION

#ifndef MY_FUNCTION
#define BEST_FUNCTION
#endif

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//KATA:Bouncing Balls
/*-------------------------------------------------------------
A child is playing with a ball on the nth floor of a tall building. The height of this floor, h, is known.

He drops the ball out of the window. The ball bounces (for example), to two-thirds of its height (a bounce of 0.66).

His mother looks out of a window 1.5 meters from the ground.

How many times will the mother see the ball pass in front of her window (including when it's falling and bouncing?

Three conditions must be met for a valid experiment:

Float parameter "h" in meters must be greater than 0
Float parameter "bounce" must be greater than 0 and less than 1
Float parameter "window" must be less than h.
If all three conditions above are fulfilled, return a positive integer, otherwise return -1.

Note: The ball can only be seen if the height of the rebounding ball is stricty greater than the window parameter.

Example:

h = 3, bounce = 0.66, window = 1.5, result is 3

h = 3, bounce = 1, window = 1.5, result is -1 (Condition 2) not fulfilled).
*/


#ifdef MY_FUNCTION

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window);
};

int Bouncingball::bouncingBall(double h, double bounce, double window)
{
    if (bounce >= 1 || bounce <= 0 || h <= window || window <= 0)
        return -1;

    double h_reducing = h;
    int n = 1 ;
    for (; h_reducing*bounce >= window; h_reducing *= bounce)
    {
        if (h_reducing*bounce>window)
            n += 2;
        else
            n++;
    }

    return n;
}

#endif



#ifdef BEST_FUNCTION
class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window)
    {
        if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h) 
            return -1;
        return (int)floor(log(window / h) / log(bounce)) * 2 + 1;//换底公式  logn(a)/logn(b) = logb(a)  这里应用:ln(window/h)/ln(bounce) = log bounce(window/h)
    }
};
#endif




//■■■■■■■■■MAIN_TEST
void main_test()
{
    double h =30;
    double bounce = 0.66;
    double window = 1.5;
    std::cout << h << " " << bounce << " "<<window<<std::endl;
    std::cout<<Bouncingball::bouncingBall(h,bounce,window)<<std::endl;
    system("PAUSE");//等待功能
}
