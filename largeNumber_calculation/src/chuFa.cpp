#include <cstring>
#include "largeNumber_calculation.h"
void calculation::chu(string s1,string s2)
{
    //除数为0
    if (s2 == "0")
    {
        cout << "error";
        return;
    }

    //被除数为0
    if (s1 == "0")
    {
        cout << "0";
        return;
    }

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

    //字符的长度，商的长度=被除数的长度-除数的长度 + 1
    int len1 = s1.size();
    int len2 = s2.size();
    int len = len1 - len2 + 1;

    //a存放被除数，b存放除数，c存放商
    //temb存放临时的b，比原b多了前导0进行模拟除法运算
    int a[len1+100],b[len2+100],c[len+100];
    int temb[len2+100];
    memset(c,0,sizeof(c));

    //为了方便，使用数组下标为0的元素记录数组的长度
    a[0] = len1;
    b[0] = len2;
    c[0] = len;

    //将字符转存到整型数组中
    for(int i = 1;i <= a[0];i++)
    {
        a[i] = s1[i-1] - '0';
    }
    for(int i = 1;i <= b[0];i++)
    {
        b[i] = s2[i-1] - '0';
    }

    //模拟除法过程
    for(int i = 1;i <= c[0];i++)
    {
        memset(temb,0,sizeof(temb));
        //将数组b转存到数组temb中，向右移动i-1位
        turnCopy(b,temb,i-1);

        //让被除数的有效位数等于除数的有效位数，进行循环减法求商
        a[0] = temb[0];
        while(compareArr(a,temb) >= 0)
        {
            //当前进行一次除法，对应位数上的商+1
            disCrease(a,temb);
            c[i]++;
        }
    }
    cout << "shang :";
    if (flag1 * flag2 == -1)
    {
        cout << '-';
    }
    chu_Output(c);
    cout << "Yu_shu :";
    chu_Output(a);
}
//除法的输出格式
void calculation::chu_Output(int p[])
{
    bool flag = 0;
    for(int i = 1;i <= p[0];i++)
    {
        if (!flag && p[i] == 0)//如果为前导0则不输出
        {
            continue;
        }
        flag = 1;
        cout << p[i];
    }
    //刚好整除，则没有余数
    if (!flag) cout << '0';
    cout << '\n';
}