#include <ctime>
#include <iostream>
#include <sstream>
#include <Windows.h>
using std::tm;
using std::time_t;
using std::ctime;
using std::cout;
using std::endl;
using std::cin;



int main()
{
    system("chcp 65001");
    system("cls");
    cout << "------------------------HELP---------------------------" << endl;
    cout << "使用说明：输入目标时间后回车，输入格式为hh mm ss\n"
        << "如目标时间为13点10分10秒，则输入13 10 10后回车" << endl;
    cout << "程序会在服务器时间到达目标时间时，自动点击鼠标左键两次" << endl;
    cout << "-------------------------------------------------------" << endl;
    // 设置目标时间，并将其转化为时间戳格式
    time_t p_time = time(NULL);
    tm* target_time = localtime(&p_time);
    cin >> target_time -> tm_hour >> target_time -> tm_min >> target_time -> tm_sec;
    system("cls");
    printf("目标时间：%02d:%02d:%02d\n",target_time->tm_hour,target_time->tm_min,target_time->tm_sec);
    time_t target_time_timestamp = mktime(target_time);
    // 循环体中持续判断当前时间与目标时间戳
    int n = 0;
    while (true) {
        //n += 1;
        //cout << n << endl;
        time_t now_time = time(NULL);
        tm *p = gmtime(&now_time);
        p -> tm_hour += 8;
        time_t beijing_time = mktime(p);
        cout << "\033[2;1H\r";
        printf("服务器当前时间：%02d:%02d:%02d\n", p ->tm_hour,p->tm_min,p->tm_sec);
        if (target_time_timestamp == beijing_time) {
            cout << "触发成功" << endl;
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);
            break;
        }
    } 
    char i;
    cin >> i;
}
