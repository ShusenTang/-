/*
(5)���⣺ �������

���д���ĵȶϢ������ǣ�
ÿ�»��̶��Ľ���Լ�������������û��꣨���һ���¿��ܻ���΢С����ͷ���룩��

����˵С�������д���1��Ԫ�������껯����Ϊ5%����������Ϊ24���¡�
�����л���ÿ���½��н��㣺
���㷽���ǣ����㱾���ڱ��²�������Ϣ�� ���� x (������/12)
���±������Ϊ������ + ��Ϣ - ÿ�¹̶������
���������������뵽���֡���

�����㣬��������£��̶������ӦΪ��438.71

��������һ�½���ʱ�ı�������ǣ�
9602.96
�ڶ����½��㣺
9204.26
�������½��㣺
8803.9
....
���һ��������԰��̶������������0.11Ԫ�ı�����
����������̶������Ϊ438.72, �����һ���»�໹������0.14Ԫ��
���л�ѡ����󱾽�������ֵ��С��������趨 ÿ�µĹ̶������ȡ�
��������������󱾽����ֵ��ͬ����ѡ�񻹿���ٵ��Ǹ�������

�������������֪�껯���ʣ�������������ÿ�µĹ̶������ȡ�

����С������Ϊ1��Ԫ��������ʼ����=1��Ԫ��
�껯���ʵĵ�λ�ǰٷ�֮���١�
�����ĵ�λΪ���ٸ��¡�

����Ϊ2�У�
��һ��Ϊһ��С��r����ʾ�����ǰٷ�֮����(0<r<30)
�ڶ���Ϊһ������n����ʾ�������ޡ� (6<=n<=120)

Ҫ�����Ϊһ����������ʾÿ�»�����λ�ǣ��֣�

���磺
���룺
4.01
24

����Ӧ�������
43429

�ٱ��磺
���룺
6.85
36

����Ӧ�������
30809

��ԴԼ����
��ֵ�ڴ����ģ���������� < 256M
CPU����  < 1000ms
*/


#include <stdio.h>
#define INITIAL_MONEY 1000000 //���� 

//��������ȡ������
 int cut_number(float num)
 {
 	return (num+0.5); 
 } 

//ÿ��ʣ�౾����㺯��
int remain_money(int money,float rate,int average_money) 
{
	float tmp;
	tmp = money+(money*rate/12)-average_money;
	return cut_number(tmp);//������������������ 
}

//���һ��ʣ�౾�����
int last_remain(int money,float rate,int average_money,int months) 
{
	int i=0;
	for(i;i < months;i++)
	{
		money = remain_money(money,rate,average_money);
	}
	return money;
}


//���ַ������average_money  
int find_average_money(int average_money_low,int average_money_high, float rate, int months)
{
	int last_remain1,last_remain2;
	if (average_money_low==average_money_high-1)//��ʱ�����ٶ��� 
		{
			last_remain1 = last_remain(INITIAL_MONEY,rate,average_money_low,months);
	        last_remain2 = last_remain(INITIAL_MONEY,rate,average_money_high,months);
			if ((last_remain1+last_remain2)>0) return average_money_high;//ȡlast_remain����ֵ��С 
			else  return average_money_low; 	
		}
	
	//���� 
	int tmp;
	int tmp_money;	
	
	tmp = (average_money_low+average_money_high)/2; 	
	tmp_money = last_remain(INITIAL_MONEY,rate,tmp,months);
	
	if (tmp_money>0)//last_remain������0��˵�� average_money_low<tmp<���<average_money_high 
	{
		average_money_low = tmp;
		return find_average_money(average_money_low,average_money_high, rate, months);
	}
	else if (tmp_money<0)//last_remain��С��0��˵�� average_money_low<���<tmp<average_money_high 
	{
		average_money_high = tmp;
		return find_average_money(average_money_low,average_money_high, rate, months);
	} 
	else return tmp;// last_remain=0,�պã��ҵ�������� 
		
}
 
int main()
{
	float rate;//���� 
	scanf("%f",&rate);
	rate = rate/100;
	
	int months;//�������� 
	scanf("%d",&months);
	
	int average_money;//����ƽ��ÿ���¹̶������� 
	
	int average_money_low; 
	int average_money_high;
	average_money_low = INITIAL_MONEY/months;//��ʱ����������в��� 
	average_money_high = 2*average_money_low;//��ʱ��������̫���ˣ��û����� 
	
	//���ַ������ 
	average_money = find_average_money(average_money_low,average_money_high, rate, months);
	printf("%d",average_money);
	return 0; 
} 
