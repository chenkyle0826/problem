#include <iostream>
using namespace std;
#include <algorithm>
#include <chrono>
#include <iomanip>
int LCM(int x[],int y){
    int tem=x[0];
    for(int i=1;i<y;i++){
        tem=(tem*x[i])/ __gcd(tem,x[i]);
    }
    return tem;
}
bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}//計算是否為閏年？

int getDaysInMonth(int year, int month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29; 
    } else {
        return daysInMonth[month - 1]; 
    }
}//計算每月天數

void next(int y,int m, int d,int daysadd){
    while(daysadd!=0){
        int daysthismonth=getDaysInMonth(y,m);//這個月有幾天？
        int daysremain=daysthismonth-d+1;//這個月的剩餘天數
        if(daysadd<=daysremain){
            d+=daysadd;
            daysadd=0;
        }else{
            daysadd-=daysremain;
            m++;
            d=1;
            if(m>12){
                y++;
                m=1;
            }
        }
        
    }
    printf("%04d/%02d/%02d",y,m,d);
}
int main(){
    int n;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];//完成小孩個別回家時間陣列
    }
    int day=LCM(x,n);//計算幾天之後（最小公倍數）
    int yy,mm,dd;
    char a;
    cin>>yy>>a>>mm>>a>>dd;
    next(yy,mm,dd,day);
    return 0;
}