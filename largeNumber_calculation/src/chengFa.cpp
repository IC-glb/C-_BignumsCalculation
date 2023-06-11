#include "largeNumber_calculation.h"
//乘法
string calculation::Cheng(string s1,string s2)
{
    //两个字符的长度
    int len1 = s1.size();
    int len2 = s2.size();
    vector<int>a(len1+len2+100),b(len1+len2+100),c(len1 + len2 + 100);
    string ans = "";
    //判断是否为结果是否为负数
    int flag1 = 1,flag2 = 1;
    if (is_negative(s1))
    {
        flag1 = -1;
        s1 = turnabs(s1);
    }
    if (is_negative(s2))
    {
        flag2 = -1;
        s2 = turnabs(s2);
    }
    if (flag1 * flag2 == -1)
    {
        ans += '-';
    }

    //倒置处理两个字符
    overturn(a,s1);
    overturn(b,s2);


    int k;
    for(int i = 0;i < len1;i++)
    {
        for(int j = 0;j < len2;j++)
        {
            k = i + j;
            c[k] += a[i] * b[j];
            //判断进位
            if (c[k] >= 10)
            {
                c[k+1] += c[k] / 10;
                c[k] %= 10;
            }
        }
    }
    //判断相乘得数是否比原来较大数的位数还大（进位情况）
    int len = len1+len2+1;
    while(c[len] > 0)
    {
        if (c[len] >= 10)
        {
            c[len+1] = c[len] / 10;
            c[len] %= 10;
        }
        len++;
    }


    //删除多余的前导0
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

