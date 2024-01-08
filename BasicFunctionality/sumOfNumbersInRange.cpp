//Range sum

#include<iostream>
using namespace std;
int main()
{
    int num1,num2,sum=0;
    cout<<"enter the num1 and num2 ";
    cin>>num1>>num2;
    for(int i=num1;i<=num2;i++)
    {
        sum=sum+i;

    }
    cout<<"sum is "<<sum;

    return 0;
}