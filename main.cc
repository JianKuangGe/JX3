#include <ctime>
#include <iostream>
#include <Windows.h>
using std::tm;
using std::time_t;
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
    time_t basic_timestamp = time(NULL);
    tm* tm_target_time = localtime(&basic_timestamp);
    cin >> tm_target_time -> tm_hour >> tm_target_time -> tm_min >> tm_target_time -> tm_sec;
    system("cls");
    printf("目标时间：%02d:%02d:%02d\n", tm_target_time->tm_hour, tm_target_time->tm_min, tm_target_time->tm_sec);
    time_t target_time_timestamp = mktime(tm_target_time);
    // 循环体中持续判断当前时间戳与目标时间戳
    int n = 0;
    while (true) {
        time_t now_timestamp = time(NULL);
        tm *tm_now_time = gmtime(&now_timestamp);
        // 将时间转换成北京时间的时间戳
        tm_now_time -> tm_hour += 8;
        time_t now_timestamp_beijing = mktime(tm_now_time);
        cout << "\033[2;1H\r"; // 使光标挪到第二行行首
        printf("服务器当前时间：%02d:%02d:%02d\n", tm_now_time ->tm_hour, tm_now_time->tm_min, tm_now_time->tm_sec);
        if (target_time_timestamp == now_timestamp_beijing) {
            cout << "触发成功" << endl;
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);
            break;
        }
    } 
    // 等待控制台关闭
    char i;
    cin >> i;
}
