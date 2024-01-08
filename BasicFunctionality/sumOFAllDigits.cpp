//sum of all digits

#include<iostream>
using namespace std;
int sum=0,rem=0;
int main()
{
    int num;
    cout<<"enter the num";
    cin>>num;
    while(num!=0)
    {
        rem=num%10;
        sum=sum+rem;
        num=num/10;
    }
    cout<<"sum of digits is "<<sum;
    return 0;
}