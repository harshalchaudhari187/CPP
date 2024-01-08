//number is palindrome or not
#include<iostream>
int main()
{
int num,rev=0,n,digit;
std::cout<<"enter the number";
std::cin>>num;
n=num;
while(num!=0)
{
    digit=num%10;
    rev=rev*10+digit;
    num=num/10;
}
if(rev==n)
std::cout<<"number is a palindrome";
else
std::cout<<"number is not a palindrome";
return 0;

}