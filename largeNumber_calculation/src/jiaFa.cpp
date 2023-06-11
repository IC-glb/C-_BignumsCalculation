#include "largeNumber_calculation.h"

//加法
string calculation::addition(string s1,string s2)
{
    vector<int>a(501),b(501),c(501);

    //返回值
    string ans = "";

    //两个数都为负数，添加负号调用加法即可
    if (s1[0] == '-' && s2[0] == '-')
    {
        s1 = turnabs(s1);
        s2 = turnabs(s2);
        ans += '-';
        ans += addition(s1,s2);
        return ans;
    }

    //其中一个数为负数的情况,调用减法
    if (s1[0] != '-' && s2[0] == '-')
    {
        s2 = turnabs(s2);
        ans += subtraction(s1,s2);
        return ans;
    }
    if (s1[0] == '-' && s2[0] != '-')
    {
        s1 = turnabs(s1);
        ans += subtraction(s2,s1);
        return ans;
    }


    int len1 = s1.size();//输入的字符的长度
    int len2 = s2.size();
    int len = max(len1,len2);

    //处理两个字符，将字符进行倒置
    overturn(a,s1);
    overturn(b,s2);


    //循环计算每一位的相加
    for(int i = 0;i < len;i++)
    {
        c[i] += (a[i] + b[i]);
        //如果该位大于10，则进位
        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }


    if (c[len] > 0)//判断是否发生了进位
    {
        len++;
    }


    //逆转转存为string类型返回
    for(int i = len - 1;i >= 0;i--)
    {
        ans += c[i] + '0';
    }
    return ans;
}

