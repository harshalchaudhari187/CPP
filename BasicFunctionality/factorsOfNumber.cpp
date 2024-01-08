//factors of a given number

#include<iostream>
using namespace std;
int main()
{int num;
    cout<<"enter the num : ";
    cin>>num;
    cout<<"factors are ";
    for(int i=1;i<=num;i++)
    {
        if(num%i==0)
        cout<<i<<",";
    }
    cout<<"\n";
    
    
    
    return 0;
}