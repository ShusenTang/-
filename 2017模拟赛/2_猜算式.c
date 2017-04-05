/*
题目(2)：猜算式

你一定还记得小学学习过的乘法计算过程，比如：

   273
x   15
------
  1365
  273
------
  4095
  
请你观察如下的乘法算式

    ***
x   ***
--------
    ***
   ***
  ***
--------
  *****
  
星号代表某位数字，注意这些星号中，
0~9中的每个数字都恰好用了2次。
请写出这个式子最终计算的结果，就是那个5位数是多少?
注意：只需要填写一个整数，不要填写任何多余的内容。比如说明文字。
*/
#include <stdio.h>

int belower_0(int a[10])//判断数组a各元素是否存在小于0的情况 
{
    int tmp = 0;
    int i;
    for (i = 0;i<10;i++)
    {
        if(a[i]<0)
        {
            tmp = 1;
            break;
        }
    }
    return tmp;
}



int n5(int num)//取万位数
{
    int tmp;
    tmp = num%100000;
    return(tmp/10000);
}

int n4(int num)//取千位数
{
    int tmp;
    tmp = num%10000;
    return(tmp/1000);
}

int n3(int num)//取百位数
{
    int tmp;
    tmp = num%1000;
    return(tmp/100);
}

int n2(int num)//取十位数
{
    int tmp;
    tmp = num%100;
    return(tmp/10);
}
int n1(int num)//取各位数
{
    return (num%10);
}

void test(int num,int a[10])//若num=122，则a[1]减一，a[2]减二 
{
    a[n3(num)] = a[n3(num)]-1;
    a[n2(num)] = a[n2(num)]-1;
    a[n1(num)] = a[n1(num)]-1;
    if(num>9999){
        a[n5(num)] = a[n5(num)]-1;
        a[n4(num)] = a[n4(num)]-1;
    }
}

int main() {
    int multi_tmp[3];
    int a,b,i;
    int x = 0;
    for(a = 100;a<=999;a++)
    {
        x=0;
        for (b = 100;b<=999;b++)
        {
            int tmp[10]={2,2,2,2,2,2,2,2,2,2};
            test(a,tmp);
            test(b,tmp);
            if(belower_0(tmp)) continue;
            else if((a*n3(b)>999)||(a*n2(b)>999)||(a*n1(b)>999)||(a*b>99999)) continue;
            multi_tmp[0] = a*n1(b);//a与b的个位数相乘
            multi_tmp[1] = a*n2(b);//a与b的十位数相乘
            multi_tmp[2] = a*n3(b);//a与b的百位数相乘
            for (i=0;i<3;i++) test(multi_tmp[i], tmp);
            test(a*b, tmp);
            if (!belower_0(tmp)) printf("%d",a*b);//判断tmp数组最后是否全0 
        }
    }
    return 0;
}

