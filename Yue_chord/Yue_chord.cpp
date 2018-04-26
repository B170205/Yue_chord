// Yue_chord.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
约瑟夫环问题的具体描述是：设有编号为1,2，……，n的n个（n>0）个人围成一个圈，从第1个人开始报数，
报到m时停止报数，报m的人出圈，才从他的下一个人起重新报数，报到m时停止报数，
报m的出圈，……，如此下去，知道剩余1个人为止。当任意给定n和m后，设计算法求n个人出圈的次序。
*/
#include<malloc.h>
int main()
{
	int n, m,i;
	printf("Please input n,m\n");
	scanf_s("%d%d", &n, &m);
	int *p = (int *)malloc(sizeof(int)*n);
	for ( i = 0; i < n; i++)
		p[i] = i + 1;
	int count = n;
	i = 0;
	int pos = 0;
	while (count > 1)
	{
		//计算下标为m的数组元素，如果pos值超过count,则从头计数,注意count是不断减少的
		pos = (pos + m - 1) % count;
		printf("要删除的元素是%d\n",p[pos]);
		//删除该下标为m的元素，数组有效元素count--,pos清0
		{
			for (i = pos; i < count; i++)
				p[i] =p[i + 1];
		}
		count -= 1;
		
	}
	//最后只剩下下标为0的值
	printf("winner ：%d", p[0]);
	return 0;
}

