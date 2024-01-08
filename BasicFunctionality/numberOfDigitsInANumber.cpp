//number of digits in a number

#include<iostream>
using namespace std;
int main()
{
    int num,count=0;
    cout<<"enter the num";
    cin>>num;
    while(num!=0)
    {
        num=num/10;
        count++;
    }
    cout<<"number of digits in a number are "<<count;
    return 0;
}