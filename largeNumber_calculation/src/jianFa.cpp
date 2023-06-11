#include "largeNumber_calculation.h"
//判断是否存在负号
bool calculation::is_negative(string s)
{
    if (s[0] == '-')
    {
        return true;
    }
    return false;
}

void calculation::overturn(vector<int>&x,string s)  //倒置字符存储到动态数组中
{
    int len = s.size();
    for(int i = 0;i < len;i++)
    {
        x[len - 1 - i] = s[i] - '0';
    }
    //-'0'是将字符转化为整型
}

//减法
string calculation::subtraction(string s1,string s2)
{
    //返回值
    string ans = "";

    int len1 = s1.size();//两个字符的长度
    int len2 = s2.size();
    int lnn = len1 + len2;
    vector <int> a(lnn),b(lnn),c(lnn);

    //如果为负数减正数则直接调用加法
    if (s1[0] == '-' && s2[0] != '-')
    {
        ans += '-';
        s1 = turnabs(s1);
        ans += addition(s1,s2);
        return ans;
    }

    //如果两个数都为负数,转化为s2-s1
    if (s1[0] == '-' && s2[0] == '-')
    {
        s1 = turnabs(s1);
        s2 = turnabs(s2);
        return subtraction(s2,s1);
    }

    //如果是正数减负数则直接调用加法
    if (s1[0] != '-' && s2[0] == '-')
    {
        s2 = turnabs(s2);
        ans += addition(s1,s2);
        return ans;
    }


    //判断结果是否为负数，如果是负数则添加一个负号
    if (len1 < len2 || (len1 == len2 && s1 < s2))
    {
        //判断大小，若s1 < s2,交换运算位置
        swap(s1,s2);
        swap(len1,len2);
        ans += "-";
    }


    //倒置处理两个字符
    overturn(a,s1);
    overturn(b,s2);


    //逐位进行减法运算，并处理借位
    int len = max(len1,len2);
    for(int i = 0;i < len;i++)
    {
        //判断是否借位
        if (a[i] < b[i])
        {
            a[i+1]--;
            a[i] += 10;
        }
        c[i] = a[i] - b[i];
    }
    //删去前导0
    while(c[len - 1] == 0 && len > 1)
    {
        len--;
    }

    //倒置输出
    for(int i = len - 1;i >= 0;i--)
    {
        ans += c[i] + '0';
    }
    return ans;
}


//删除输入字符的负号
string calculation::turnabs(string s)
{
    string ans = "";
    for(int i = 1;i < s.size();i++)
    {
        ans += s[i];
    }
    return ans;
}

//将数组x转存到数组arr中，向右移动aim位
void calculation::turnCopy(int x[],int arr[],int aim)
{
    for(int i = 1;i <= x[0];i++)
    {
        arr[i+aim] = x[i];
    }
    arr[0] = x[0] +aim;
}

//比较两个数组的大小(这里是应用于被除数和临时除数的两个数组)
int calculation::compareArr(int arr1[],int arr2[])
{
    //arr1 > arr2 返回1；arr1 < arr2 返回-1
    //相等返回0
    for(int i = 1;i <= arr1[0];i++)
    {
        if (arr1[i] > arr2[i]) return 1;
        if (arr1[i] < arr2[i]) return -1;
    }
    return 0;
}

//模拟除法中的减法，实现两个数组做差
void calculation::disCrease(int arr1[],int arr2[])
{
    //与大数减法逻辑一致 但此处arr1大于arr2 因此不需要比较，只需要依次运算，不足借位就可以
    for(int i = arr1[0];i >= 1;i--)
    {
        //判断是否需要借位
        if (arr1[i] < arr2[i])
        {
            arr1[i] += 10;
            arr1[i-1] -= 1;
        }
        arr1[i] -= arr2[i];
    }
}



