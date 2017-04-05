/*
(4)���⣺�ַ����Ƚ�

������Ҫһ���µ��ַ����ȽϺ���compare(s1, s2).
���������Ҫ���ǣ�
1. ������һ����������ʾ�ȽϵĽ����
2. ���Ϊ��ֵ����ǰһ������Ϊ��ֵ����һ�����󣬷�����ͬ��
3. ����ľ���ֵ��ʾ���ڵڼ�����ĸ�����������������ȡ�

�����Ǵ���ʵ�֡�����������ݣ����Ϊ��
-3
2
5

��ϸ�Ķ�Դ������д����λ��ȱ�ٵĴ��롣
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
	
	return t+(t>0)*(1)+(t<0)*(-1); //return ____________________ ; //���λ��
}


int main()
{
	printf("%d\n", compare("abc","abk"));
	printf("%d\n", compare("abc","a"));
	printf("%d\n", compare("abcde","abcda"));
	return 0;
}
