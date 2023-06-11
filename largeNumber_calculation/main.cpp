#include "largeNumber_calculation.h"
#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#pragma comment(lib,"Psapi.lib");

using namespace std;


int main()
{   calculation c;
    string a,b;
    while(cin >> a >> b)
    {
        auto start = chrono::high_resolution_clock::now();

        cout << "a+b= "<<c.addition(a,b) << '\n';
        cout << "a-b= "<<c.subtraction(a,b) << '\n';
        cout << "a*b= "<<c.Cheng(a,b) << '\n';
        c.chu(a,b);

        //计算时间
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "time=" << duration.count() << "ms" << std::endl;

        //计算内存占用
        HANDLE handle = GetCurrentProcess();
        PROCESS_MEMORY_COUNTERS pmc;
        GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
        printf("Occupy: %d kb\r\n",pmc.WorkingSetSize/1000);  //结果保存单位是B，可以除以1000保存为kb格式



    }
    return 0;
}
