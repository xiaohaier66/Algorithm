

// ######################################################################## //
//
//  ������ʹ�ö�̬�滮����� '�༭����' ����.
//
//  ��������: 2016-04-03
//
//  �޸ļ�¼:
//  ( 1 ) 2016-04-03 �����˳�ʼ�汾( v0.10 )
//
//  �� �� ��: v0.10
//
//  ��    ע: ʹ�ñ�׼ C ����ʵ��
//
//  ��    ��: ��ΰ
//
// ######################################################################## //

// ʹ�õĿⶨ��
#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include <iostream>
using namespace std;

// ######################################################################## //
//                                                                          // 
//                              ���������ݶ�����                               // 
//                                                                          // 
// ######################################################################## //

#define STR_LEN 100
#define TRUE    1
#define FALSE   0

//////////////////////////////////////////////////////////////////////////////


// ######################################################################## //
//                                                                          // 
//                           �����Ǹ����Ӻ�������                               // 
//                                                                          // 
// ######################################################################## //

int  FindTripleMin(int a, int b, int c);
int  CalcEditDistance(char *StrA, char *StrB, int **d);
//void PrintEditDistanceMatrix(int **d, int RowNum, int ColNum);
void PrintEditDistanceMatrix(int **d, int RowNum, int ColNum, char *StrA, char *StrB);

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                          �����Ǹ����Ӻ�����ʵ��                             // 
//                                                                          // 
// ######################################################################## //

// ȡ 3 �������е���Сֵ...
int FindTripleMin(int a, int b, int c)
{
	int t = (a < b) ? a : b;

	return ((t < c) ? t : c);
}

// ʹ�ö�̬�滮�����������ַ���֮��ı༭���� ...
//
// ������������ :
// ( 1 ) A = fxpimu  B = xwrs  d( A, B ) = 5
// ( 2 ) A = abc     B = cba   d( A, B ) = 2
// ( 3 ) A = stot    B = stop  d( A, B ) = 1
// ( 4 ) A = cd      B = abcb  d( A, B ) = 3
int CalcEditDistance(char *StrA, char *StrB, int **d)
{

	// �뽫����Ĵ��벹�����, ʹ���������ȷ���� ...
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

	// ���ر༭����ֵ ...
	return d[strlen(StrA)][strlen(StrB)];
}

// ��ӡ�༭������� ...
//void PrintEditDistanceMatrix(int **d, int RowNum, int ColNum) /*������ʦ������ʾ����*/
void PrintEditDistanceMatrix(int **d, int RowNum, int ColNum, char* StrA, char* StrB)
{

	// �뽫����Ĵ��벹�����, ʹ���������ȷ���� ...
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
//                             �������������ʵ��                              // 
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
		// ���� ...
		system("cls");

		// �����ַ��� 'A' ...
		printf("\n\n\t������ < �ַ��� A > �� ���� < q / Q > ��ʾ���� : ");
		cin >> StrA;
		//scanf("%s", StrA);
		m = strlen(StrA);
		if (m > 0)
			IsStop = ((StrA[0] == 'q') || (StrA[0] == 'Q'));
		else
			printf("\t������ַ��� A ����Ϊ�� !\n\n");

		if (!IsStop)
		{
			// �����ַ��� 'B' ...
			printf("\n\t������ < �ַ��� B > �� ���� < q / Q > ��ʾ���� : ");
			cin >> StrB;
			//scanf("%s", StrB);
			n = strlen(StrB);
			if (n > 0)
				IsStop = ((StrB[0] == 'q') || (StrB[0] == 'Q'));
			else
				printf("\t������ַ��� B ����Ϊ�� !\n\n");

			// ������ַ��� 'A' �� 'B' ����Ϊ��, �������༭���� ...
			if (!IsStop)
			{
				// ��̬�����ά���� ...
				d = (int **)malloc(sizeof(int*) * (m + 1));
				for (int i = 0; i < m + 1; ++i)
				{
					d[i] = (int*)malloc(sizeof(int) * (n + 1));
				}
			
				// �뽫����Ĵ��벹�����, ʹ���������ȷ���� ...
				// ......

				// ����༭���� ...
				dAB = CalcEditDistance(StrA, StrB, d);

				// ��ʾ������ ...
				printf("\n\t< �ַ��� A �� B ֮��ı༭����Ϊ��%d > \n\n", dAB);

				// ��ӡ�༭������� ...
				//PrintEditDistanceMatrix(d, (m + 1), (n + 1));
				PrintEditDistanceMatrix(d, (m + 1), (n + 1), StrA, StrB);
				// �ͷſռ� ...
				for (i = 0; i <= m; i++)
					free(d[i]);
				free(d);

				// �ȴ��û���������һ������ ...
				printf("\n\n");
				system("PAUSE");
			}
		}
	}

	// �ȴ��û���������һ������ ...
	printf("\n\n");
	system("PAUSE");
}

//////////////////////////////////////////////////////////////////////////////