

// ######################################################################## //
//
//  本程序使用动态规划法解决 '编辑距离' 问题.
//
//  创建日期: 2016-04-03
//
//  修改记录:
//  ( 1 ) 2016-04-03 创建了初始版本( v0.10 )
//
//  版 本 号: v0.10
//
//  备    注: 使用标准 C 代码实现
//
//  作    者: 刘伟
//
// ######################################################################## //

// 使用的库定义
#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include <iostream>
using namespace std;

// ######################################################################## //
//                                                                          // 
//                              下面是数据定义区                               // 
//                                                                          // 
// ######################################################################## //

#define STR_LEN 100
#define TRUE    1
#define FALSE   0

//////////////////////////////////////////////////////////////////////////////


// ######################################################################## //
//                                                                          // 
//                           下面是各个子函数定义                               // 
//                                                                          // 
// ######################################################################## //

int  FindTripleMin(int a, int b, int c);
int  CalcEditDistance(char *StrA, char *StrB, int **d);
//void PrintEditDistanceMatrix(int **d, int RowNum, int ColNum);
void PrintEditDistanceMatrix(int **d, int RowNum, int ColNum, char *StrA, char *StrB);

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                          下面是各个子函数的实现                             // 
//                                                                          // 
// ######################################################################## //

// 取 3 个整数中的最小值...
int FindTripleMin(int a, int b, int c)
{
	int t = (a < b) ? a : b;

	return ((t < c) ? t : c);
}

// 使用动态规划法计算两个字符串之间的编辑距离 ...
//
// 测试数据如下 :
// ( 1 ) A = fxpimu  B = xwrs  d( A, B ) = 5
// ( 2 ) A = abc     B = cba   d( A, B ) = 2
// ( 3 ) A = stot    B = stop  d( A, B ) = 1
// ( 4 ) A = cd      B = abcb  d( A, B ) = 3
int CalcEditDistance(char *StrA, char *StrB, int **d)
{

	// 请将下面的代码补充完毕, 使程序可以正确运行 ...
	// ......
	int m = strlen(StrA);
	int n = strlen(StrB);
	d[0][0] = 0;
	for (int j = 1; j < n + 1; ++j)
		d[0][j] = j;
	for (int i = 1; i < m + 1; ++i)
		d[i][0] = i;
	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			if (StrA[i-1] == StrB[j-1])
				d[i][j] = d[i - 1][j - 1];
			else
			{
				d[i][j] = FindTripleMin(d[i][j - 1], d[i - 1][j], d[i - 1][j - 1]) + 1;;
			}
		}

	}

	// 返回编辑距离值 ...
	return d[strlen(StrA)][strlen(StrB)];
}

// 打印编辑距离矩阵 ...
//void PrintEditDistanceMatrix(int **d, int RowNum, int ColNum) /*这是老师给的显示函数*/
void PrintEditDistanceMatrix(int **d, int RowNum, int ColNum, char* StrA, char* StrB)
{

	// 请将下面的代码补充完毕, 使程序可以正确运行 ...
	// ......
	printf("\tThe EditDistanceMatrix is:\n");
	printf("\t\tStrB");
	for (int j = 0; j < ColNum; ++j)
		printf("\t%c", StrB[j]);
	printf("\n");
	for (int i = 0; i < RowNum; ++i)
	{
		if (i == 0)
			printf("\tStrA");
		else
			printf("\t%c", StrA[i-1]);

		for (int j = 0; j < ColNum; ++j)
		{	
			if (i == RowNum - 1 && j == ColNum - 1)
				printf("\t[%d]",d[i][j]);
			else
				printf("\t%d", d[i][j]);
		}
				
		printf("\n");
	}
	printf("\n");
}

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                             下面是主程序的实现                              // 
//                                                                          // 
// ######################################################################## //

void main(void)
{
	char StrA[STR_LEN];
	char StrB[STR_LEN];
	int  **d;
	int  i, m, n, dAB;
	int  IsStop;

	IsStop = FALSE;
	while (!IsStop)
	{
		// 清屏 ...
		system("cls");

		// 输入字符串 'A' ...
		printf("\n\n\t请输入 < 字符串 A > ， 输入 < q / Q > 表示结束 : ");
		cin >> StrA;
		//scanf("%s", StrA);
		m = strlen(StrA);
		if (m > 0)
			IsStop = ((StrA[0] == 'q') || (StrA[0] == 'Q'));
		else
			printf("\t输入的字符串 A 不能为空 !\n\n");

		if (!IsStop)
		{
			// 输入字符串 'B' ...
			printf("\n\t请输入 < 字符串 B > ， 输入 < q / Q > 表示结束 : ");
			cin >> StrB;
			//scanf("%s", StrB);
			n = strlen(StrB);
			if (n > 0)
				IsStop = ((StrB[0] == 'q') || (StrB[0] == 'Q'));
			else
				printf("\t输入的字符串 B 不能为空 !\n\n");

			// 输入的字符串 'A' 和 'B' 均不为空, 则计算其编辑距离 ...
			if (!IsStop)
			{
				// 动态申请二维数组 ...
				d = (int **)malloc(sizeof(int*) * (m + 1));
				for (int i = 0; i < m + 1; ++i)
				{
					d[i] = (int*)malloc(sizeof(int) * (n + 1));
				}
			
				// 请将下面的代码补充完毕, 使程序可以正确运行 ...
				// ......

				// 计算编辑距离 ...
				dAB = CalcEditDistance(StrA, StrB, d);

				// 显示计算结果 ...
				printf("\n\t< 字符串 A 和 B 之间的编辑距离为：%d > \n\n", dAB);

				// 打印编辑距离矩阵 ...
				//PrintEditDistanceMatrix(d, (m + 1), (n + 1));
				PrintEditDistanceMatrix(d, (m + 1), (n + 1), StrA, StrB);
				// 释放空间 ...
				for (i = 0; i <= m; i++)
					free(d[i]);
				free(d);

				// 等待用户输入任意一键返回 ...
				printf("\n\n");
				system("PAUSE");
			}
		}
	}

	// 等待用户输入任意一键返回 ...
	printf("\n\n");
	system("PAUSE");
}

//////////////////////////////////////////////////////////////////////////////