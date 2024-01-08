//product of digits of given number
#include<iostream>
int main()
{
    int num,rem,res=1;
    std::cout<<"Enter the number";
    std::cin>>num;
    while(num!=0)
    {
      rem=num%10;
      num=num/10;
      res=res*rem;
    }
    std::cout<<"product is "<<res;
    return 0;
}