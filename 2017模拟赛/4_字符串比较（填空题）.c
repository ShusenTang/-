/*
(4)标题：字符串比较

我们需要一个新的字符串比较函数compare(s1, s2).
对这个函数要求是：
1. 它返回一个整数，表示比较的结果。
2. 结果为正值，则前一个串大，为负值，后一个串大，否则，相同。
3. 结果的绝对值表示：在第几个字母处发现了两个串不等。

下面是代码实现。对题面的数据，结果为：
-3
2
5

仔细阅读源程序，填写划线位置缺少的代码。
*/

#include <stdio.h>

int compare(const char* s1, const char* s2)
{
	if(s1==NULL && s2==NULL) return 0;
	if(s1==NULL) return -1;
	if(s2==NULL) return 1;
	
	if(*s1 == 0 && *s2== 0) return 0;
	if(*s1 == 0) return -1;
	if(*s2 == 0) return 1;
	
	if(*s1<*s2) return -1;
	if(*s1>*s2) return 1;
	
	int t = compare(s1+1,s2+1);
	if(t==0) return 0;
	
	return t+(t>0)*(1)+(t<0)*(-1); //return ____________________ ; //填空位置
}


int main()
{
	printf("%d\n", compare("abc","abk"));
	printf("%d\n", compare("abc","a"));
	printf("%d\n", compare("abcde","abcda"));
	return 0;
}
