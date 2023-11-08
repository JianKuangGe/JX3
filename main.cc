// 持续刷新当前时间时间
// 设置定时时间
// 定期检查时间
// 到点出发鼠标左键两次

#include <ctime>
#include <iostream>
#include <sstream>
using std::tm;
using std::time_t;
using std::ctime;
using std::cout;
using std::endl;
using std::cin;



int main()
{
    // 设置目标时间，并将其转化为时间戳格式
    time_t p_time = time(NULL);
    tm* target_time = localtime(&p_time);
    cin >> target_time -> tm_hour >> target_time -> tm_min >> target_time -> tm_sec;
    printf("目标时间：%02d:%02d:%02d\n",target_time->tm_hour,target_time->tm_min,target_time->tm_sec);
    time_t target_time_timestamp = mktime(target_time);
    // 循环体中持续判断当前时间与目标时间戳
    int n = 0;
    while (true) {
        //n += 1;
        //cout << n << endl;
        time_t now_time = time(NULL);
        tm *p = localtime(&now_time);
        cout << "\033[1;1H\r";
        printf("目标时间：%02d:%02d:%02d\n",target_time->tm_hour,target_time->tm_min,target_time->tm_sec);
        printf("当前时间：%02d:%02d:%02d\n", p ->tm_hour,p->tm_min,p->tm_sec);
        if (target_time_timestamp == now_time) {
            cout << "触发成功" << endl;
            return 0;
        }
    }
}
