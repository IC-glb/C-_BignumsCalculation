#include "iostream"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


class calculation{
public:
    //加法

    string addition(string s1,string s2);

    //减法

    string subtraction(string s1,string s2);

    void overturn(vector<int>&x,string s);

    bool is_negative(string s);

    string turnabs(string s);

    void turnCopy(int x[],int arr[],int aim);

    int compareArr(int arr1[],int arr2[]);

    void disCrease(int arr1[],int arr2[]);



    //multiplication 乘法

    string Cheng(string s1,string s2);

    //division  除法

    void chu(string s1,string s2);



    void chu_Output(int p[]);




};






