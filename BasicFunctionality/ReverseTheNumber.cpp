//reverse number

#include<iostream>
using namespace std;
int rem=0,res=0;
int main()
{

    int num;
    cout<<"enter the num";
    cin>>num;
    
    while(num!=0)
    {
        rem=num%10;
        res=res*10+rem;
        num=num/10;
    }
    cout<<"reverse number is "<<res;
    return 0;
}