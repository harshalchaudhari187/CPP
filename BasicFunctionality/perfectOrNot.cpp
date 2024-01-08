//given number is perfect number or not

#include<iostream>
using namespace std;
int main()
{
    int num,sum=0;
    cout<<"enter the num";
    cin>>num;
    for(int i=1;i<num;i++)
    {
        if(num%i==0)
        sum=sum+i;
    }
    if(sum==num)
    cout<<"perfect number";
    else
    cout<<"not a perfect number";
    return 0;
}