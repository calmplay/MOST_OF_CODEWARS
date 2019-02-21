#pragma once
#include<iostream>
#include <vector>
#include <algorithm>

//����������������������������������������������������������������
//KATA1:Speed Control
/*-------------------------------------------------------------
In John's car the GPS records every s seconds the distance travelled from an origin (distances are measured in an arbitrary but consistent unit[������������ġ�һ�µĵ�λ�������]). 

FOR EXAMPLE:
below is part of a record with s = 15:
x = [0.0, 0.19, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25]
The sections are:

0.0-0.19, 0.19-0.5, 0.5-0.75, 0.75-1.0, 1.0-1.25, 1.25-1.50, 1.5-1.75, 1.75-2.0, 2.0-2.25
We can calculate John's average hourly speed on every section and we get:

[45.6, 74.4, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0]
using V = std::vector<int>;

Given s and x the task is to return as an integer the *floor* of the maximum average speed per hour obtained on the sections of x. If x length is less than or equal to 1 return 0 since the car didn't move.

[��������ƽ���ٶȣ�����ȡ���������ĳ�ε��ٶ�<=1����öξ���ȡ0]


Example:

with the above data your function gps(s, x)should return 74
(s:ÿ��s�����һ�ξ���     x:��0��ʼ���г�[��λ������ν])

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

    static int gps(int s, std::vector<double> &x);//�����static���κ������߳�Ա��ʾ�����ط����� ǰͷ����Ҫ�Ӷ�����Ҳ�ܷ��ʡ�

};

int GpsSpeed::gps(int s, std::vector<double> &x)  //��Ϊ��static���� ����ĵط�Ҳ����Ҫ������? �о����Ǽ�һ�±ȽϺá�dogedoge
{
    //std::vector<int> x_hourly ;//��ʼ��sizeΪ0��vector
    //std::vector<int> abc(10);    //��ʼ����10��Ĭ��ֵΪ0��Ԫ��
    //std::vector<int> cde(10��1);    //��ʼ����10��ֵΪ1��Ԫ��
   
    //x_hourly.size = x.size;//������ERROR!! vector.sizeΪ�����޸ĵ���ֵ

    std::vector<int> x_hourly(x.size()-1); //���ڴ洢ÿ���г̵�ʱ�٣���λ���� / h��
       

    for (int n = 1 ;n<x.size();n++)//�ӵڶ�����ʼ��ÿ�ε������ֵ����
    {        
        x_hourly.at(n-1) = ((x[n] - x[n-1]) * 3600 / s)> 0 ? (x[n] - x[n-1]) * 3600 / s : 0;
    }
    std::sort(x_hourly.begin(), x_hourly.end());//��������
    //std::reverse(x_hourly.begin(), x_hourly.end());//�����ǽ������򣬽���������������һ��

    return x_hourly[x_hourly.size()-1];
    //���  v.at(n)��v[n]��ʾ����һ����ֵ��������ǰ�߻����Ƿ�Խ�磨��˻��ѵ�ʱ���Զࣩ�����߲��ᣨ����Խ��ᵼ��δ������Ϊ��
}



//������������������MAIN_TEST
void main_test()
{
    std::vector<double> x = {0.0, 0.19, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25};

    //x = { 0.0, 0.11, 0.22, 0.33, 0.44, 0.65, 1.08, 1.26, 1.68, 1.89, 2.1, 2.31, 2.52, 3.25 };//���ǲ���1

    //x = { 0.0, 0.23, 0.46, 0.69, 0.92, 1.15, 1.38, 1.61 };//���ǲ���2

    int s = 15 ;
    
    std::cout << "s = "<<s<<std::endl;
    std::cout << "x = { ";
    for (const double &i : x)
        std::cout << i<<" ";
    std::cout << "}"<<std::endl;

    GpsSpeed g();//��Ϊg.gps(int,v<double>)��static����,���������Ҳ�ɵ��ã���Ϊ��������Բ������������������͵ĳ�Ա�±�ֱ����������:: ���þ����ˣ�


    std::cout << "max avrg speed(?/h) = " << GpsSpeed::gps(s, x)<<std::endl;//

    system("PAUSE");//�ȴ�����

}
