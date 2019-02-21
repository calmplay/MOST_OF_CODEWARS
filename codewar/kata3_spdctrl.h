#pragma once
#include<iostream>
#include <vector>
#include <algorithm>

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//KATA1:Speed Control
/*-------------------------------------------------------------
In John's car the GPS records every s seconds the distance travelled from an origin (distances are measured in an arbitrary but consistent unit[距离是以任意的、一致的单位来计算的]). 

FOR EXAMPLE:
below is part of a record with s = 15:
x = [0.0, 0.19, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25]
The sections are:

0.0-0.19, 0.19-0.5, 0.5-0.75, 0.75-1.0, 1.0-1.25, 1.25-1.50, 1.5-1.75, 1.75-2.0, 2.0-2.25
We can calculate John's average hourly speed on every section and we get:

[45.6, 74.4, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0]
using V = std::vector<int>;

Given s and x the task is to return as an integer the *floor* of the maximum average speed per hour obtained on the sections of x. If x length is less than or equal to 1 return 0 since the car didn't move.

[返回最大的平均速度（向下取整），如果某段的速度<=1，则该段均速取0]


Example:

with the above data your function gps(s, x)should return 74
(s:每隔s秒计算一次距离     x:以0开始的行程[单位：无所谓])

Note

With floats it can happen that results depends on the operations order. To calculate hourly speed you can use:

(3600 * delta_distance) / s.


*/


//my function
class GpsSpeed
{
private:
    int second_per;
    std::vector<double> vct_dist;

public:
   /* GpsSpeed(int s, std::vector<double> &x)
    {
        second_per = s;
        vct_dist = x;
    }*/

    static int gps(int s, std::vector<double> &x);//★★★★static修饰函数或者成员表示其他地方访问 前头不需要加对象名也能访问。

};

int GpsSpeed::gps(int s, std::vector<double> &x)  //因为是static函数 定义的地方也不需要加类名? 感觉还是加一下比较好【dogedoge
{
    //std::vector<int> x_hourly ;//初始化size为0的vector
    //std::vector<int> abc(10);    //初始化了10个默认值为0的元素
    //std::vector<int> cde(10，1);    //初始化了10个值为1的元素
   
    //x_hourly.size = x.size;//▲▲▲ERROR!! vector.size为不可修改的左值

    std::vector<int> x_hourly(x.size()-1); //用于存储每段行程的时速（单位：？ / h）
       

    for (int n = 1 ;n<x.size();n++)//从第二个开始，每段的由相减值计算
    {        
        x_hourly.at(n-1) = ((x[n] - x[n-1]) * 3600 / s)> 0 ? (x[n] - x[n-1]) * 3600 / s : 0;
    }
    std::sort(x_hourly.begin(), x_hourly.end());//升序排序
    //std::reverse(x_hourly.begin(), x_hourly.end());//▲不是降序排序，仅仅是逆序排列了一下

    return x_hourly[x_hourly.size()-1];
    //★★  v.at(n)和v[n]表示的是一样的值，区别是前者会检查是否越界（因此花费的时间稍多），后者不会（后者越界会导致未定义行为）
}



//■■■■■■■■■MAIN_TEST
void main_test()
{
    std::vector<double> x = {0.0, 0.19, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25};

    //x = { 0.0, 0.11, 0.22, 0.33, 0.44, 0.65, 1.08, 1.26, 1.68, 1.89, 2.1, 2.31, 2.52, 3.25 };//覆盖测试1

    //x = { 0.0, 0.23, 0.46, 0.69, 0.92, 1.15, 1.38, 1.61 };//覆盖测试2

    int s = 15 ;
    
    std::cout << "s = "<<s<<std::endl;
    std::cout << "x = { ";
    for (const double &i : x)
        std::cout << i<<" ";
    std::cout << "}"<<std::endl;

    GpsSpeed g();//因为g.gps(int,v<double>)是static函数,对象外的人也可调用，因为对象本身可以不包含这两个参数类型的成员下边直接用类名加:: 调用就行了；


    std::cout << "max avrg speed(?/h) = " << GpsSpeed::gps(s, x)<<std::endl;//

    system("PAUSE");//等待功能

}
