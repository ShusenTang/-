/*
��Ŀ(2)������ʽ

��һ�����ǵ�Сѧѧϰ���ĳ˷�������̣����磺

   273
x   15
------
  1365
  273
------
  4095
  
����۲����µĳ˷���ʽ

    ***
x   ***
--------
    ***
   ***
  ***
--------
  *****
  
�ǺŴ���ĳλ���֣�ע����Щ�Ǻ��У�
0~9�е�ÿ�����ֶ�ǡ������2�Ρ�
��д�����ʽ�����ռ���Ľ���������Ǹ�5λ���Ƕ���?
ע�⣺ֻ��Ҫ��дһ����������Ҫ��д�κζ�������ݡ�����˵�����֡�
*/
#include <stdio.h>

int belower_0(int a[10])//�ж�����a��Ԫ���Ƿ����С��0����� 
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



int n5(int num)//ȡ��λ��
{
    int tmp;
    tmp = num%100000;
    return(tmp/10000);
}

int n4(int num)//ȡǧλ��
{
    int tmp;
    tmp = num%10000;
    return(tmp/1000);
}

int n3(int num)//ȡ��λ��
{
    int tmp;
    tmp = num%1000;
    return(tmp/100);
}

int n2(int num)//ȡʮλ��
{
    int tmp;
    tmp = num%100;
    return(tmp/10);
}
int n1(int num)//ȡ��λ��
{
    return (num%10);
}

void test(int num,int a[10])//��num=122����a[1]��һ��a[2]���� 
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
            multi_tmp[0] = a*n1(b);//a��b�ĸ�λ�����
            multi_tmp[1] = a*n2(b);//a��b��ʮλ�����
            multi_tmp[2] = a*n3(b);//a��b�İ�λ�����
            for (i=0;i<3;i++) test(multi_tmp[i], tmp);
            test(a*b, tmp);
            if (!belower_0(tmp)) printf("%d",a*b);//�ж�tmp��������Ƿ�ȫ0 
        }
    }
    return 0;
}

