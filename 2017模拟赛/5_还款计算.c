/*
(5)标题： 还款计算

银行贷款的等额本息还款方法是：
每月还固定的金额，在约定的期数内正好还完（最后一个月可能会有微小的零头出入）。

比如说小明在银行贷款1万元。贷款年化利率为5%，贷款期限为24个月。
则银行会在每个月进行结算：
结算方法是：计算本金在本月产生的利息： 本金 x (年利率/12)
则本月本金结余为：本金 + 利息 - 每月固定还款额
计算结果会四舍五入到“分”。

经计算，此种情况下，固定还款额应为：438.71

这样，第一月结算时的本金余额是：
9602.96
第二个月结算：
9204.26
第三个月结算：
8803.9
....
最后一个月如果仍按固定额还款，则最后仍有0.11元的本金余额，
但如果调整固定还款额为438.72, 则最后一个月会多还了银行0.14元。
银行会选择最后本金结算绝对值最小的情况来设定 每月的固定还款额度。
如果有两种情况最后本金绝对值相同，则选择还款较少的那个方案。

本题的任务是已知年化利率，还款期数，求每月的固定还款额度。

假设小明贷款为1万元，即：初始本金=1万元。
年化利率的单位是百分之多少。
期数的单位为多少个月。

输入为2行，
第一行为一个小数r，表示年率是百分之几。(0<r<30)
第二行为一个整数n，表示还款期限。 (6<=n<=120)

要求输出为一个整数，表示每月还款额（单位是：分）

例如：
输入：
4.01
24

程序应该输出：
43429

再比如：
输入：
6.85
36

程序应该输出：
30809

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms
*/


#include <stdio.h>
#define INITIAL_MONEY 1000000 //本金 

//四舍五入取整函数
 int cut_number(float num)
 {
 	return (num+0.5); 
 } 

//每月剩余本金计算函数
int remain_money(int money,float rate,int average_money) 
{
	float tmp;
	tmp = money+(money*rate/12)-average_money;
	return cut_number(tmp);//返回四舍五入后的整数 
}

//最后一月剩余本金计算
int last_remain(int money,float rate,int average_money,int months) 
{
	int i=0;
	for(i;i < months;i++)
	{
		money = remain_money(money,rate,average_money);
	}
	return money;
}


//二分法找最佳average_money  
int find_average_money(int average_money_low,int average_money_high, float rate, int months)
{
	int last_remain1,last_remain2;
	if (average_money_low==average_money_high-1)//此时不可再二分 
		{
			last_remain1 = last_remain(INITIAL_MONEY,rate,average_money_low,months);
	        last_remain2 = last_remain(INITIAL_MONEY,rate,average_money_high,months);
			if ((last_remain1+last_remain2)>0) return average_money_high;//取last_remain绝对值最小 
			else  return average_money_low; 	
		}
	
	//二分 
	int tmp;
	int tmp_money;	
	
	tmp = (average_money_low+average_money_high)/2; 	
	tmp_money = last_remain(INITIAL_MONEY,rate,tmp,months);
	
	if (tmp_money>0)//last_remain若大于0，说明 average_money_low<tmp<最佳<average_money_high 
	{
		average_money_low = tmp;
		return find_average_money(average_money_low,average_money_high, rate, months);
	}
	else if (tmp_money<0)//last_remain若小于0，说明 average_money_low<最佳<tmp<average_money_high 
	{
		average_money_high = tmp;
		return find_average_money(average_money_low,average_money_high, rate, months);
	} 
	else return tmp;// last_remain=0,刚好，找到绝对最佳 
		
}
 
int main()
{
	float rate;//利率 
	scanf("%f",&rate);
	rate = rate/100;
	
	int months;//还款期限 
	scanf("%d",&months);
	
	int average_money;//所求平均每个月固定还款数 
	
	int average_money_low; 
	int average_money_high;
	average_money_low = INITIAL_MONEY/months;//此时还款不够，银行不干 
	average_money_high = 2*average_money_low;//此时还给银行太多了，用户不干 
	
	//二分法找最佳 
	average_money = find_average_money(average_money_low,average_money_high, rate, months);
	printf("%d",average_money);
	return 0; 
} 
