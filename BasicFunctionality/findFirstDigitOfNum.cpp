//first digit of a positive integer

#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"enter the num ";
    cin>>num;
    int rem=0;
    while(num!=0)
    {
        rem=num%10;
        num=num/10;
    }
    cout<<"first digit is "<<rem;
    return 0;
}