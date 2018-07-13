
// ######################################################################## //
//
//  本程序使用贪心算法解决 '整数最优分解' 问题.
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
#include < iostream >
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

int DoIntOptDecomposition( int n, int *a );

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                          下面是各个子函数的实现                             // 
//                                                                          // 
// ######################################################################## //

// 整数最优分解 ...
//
// 测试数据如下 :
// ( 1 ) 10 = 2 + 3 + 5, 乘积为 30
// ( 2 ) 随机例子
int DoIntOptDecomposition( int n, int *a )
{
  int MaxProduct = 1; // 乘积 ...
  int k = 1;
  int i;

 // *( a + 1 ) = 2; // 从 '2' 开始处理 ...
  //n -= 2;
  if (n == 1)
  {
	  *(a) = 1;
	  return MaxProduct;
  }

  // 请将下面的代码补充完毕, 使程序可以正确运行 ...
  // ......
  for (k = 2; n>k-1; k++) {
	  *(a + k - 1) = k;
	  printf("%d	", *(a + k - 1));//观察程序运行情况
	  n -= k;
   }
  printf("剩余值：%d ", n);
  printf("\n");
  if (n == k-1) {
	  *(a + k - 2) += 1;
	  n--;
	  //观察
	  for (i = 1; i < k - 1; i++) {
		  if ( i+0 == k - 2)
			  printf("[%d]	", *(a + i));
		  else
			  printf("%d	", *(a + i));
	  }
	  printf("剩余值：%d ", n);
	  printf("\n");
  }
 
  if (n < k-1) {
	  for (; n > 0;n--) {
		  *(a + k - n -1) += 1;
		  //观察
		  for (i = 1; i < k - 1; i++) {
			  if (k - n -1 == i)
				  printf("[%d]	", *(a + i));
			  else
				  printf("%d	", *(a + i));
		  }
		  printf("剩余值：%d", n-1);
		  printf("\n");
	  }
  }
  
  // 设置 'a' 数组结束标记 ...
  *( a + k - 1) = -1;
  for (i = 1; i < k - 1; i++) {
	  MaxProduct *= *(a + i);
  }
  return MaxProduct;
}

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                             下面是主程序的实现                              // 
//                                                                          // 
// ######################################################################## //

int main( void )
{
  char StrN[ STR_LEN ];
  int  *a, *p;
  int  n, MaxProduct;
  int  IsStop;

  IsStop = FALSE;
  while ( !IsStop )
  {
    // 清屏 ...
    system( "cls" );

	// 输入字符串 'A' ...
    printf( "\n\n\t请输入 < 待分解的整数 > ， 输入 < q / Q > 表示结束 : " );
	cin >> StrN;
	//scanf( "%s", StrN );
    if ( strlen( StrN ) > 0 )
	  IsStop = ( ( StrN[ 0 ] == 'q' ) || ( StrN[ 0 ] == 'Q' ) );
    else
      printf( "\t输入的整数不能为空 !\n\n" );

	if ( !IsStop )
	{
      // 动态申请一维数组 ...
      a = ( int * )malloc( STR_LEN * sizeof( int ) );

	  // 得到输入的整数值 ...
	  n = atoi( StrN );
	  if (n <= 0) {
		  printf("!输入非正整数!\n");
		  system("pause");
		  continue;
	  }
      // 整数最优分解 ...
      MaxProduct = DoIntOptDecomposition( n, a );

	  // 显示计算结果 ...
      printf( "\n\t< 整数最优分解乘积为：%d > \n", MaxProduct );

	  // 打印分解结果 ...
	  printf( "\n\t< 分解因子值为 > " );

      // 请将下面的代码补充完毕, 使程序可以正确运行 ...
      // ......
	  
	  for (int i = 1; n != 1; ++i) {
		  if (a[i] == -1)
			  break;
		  printf("\t%d", a[i]);
	  }
	  if (n + 0 == 1) {
		  printf("\t%d", a[0]);
	  }
	  
      // 释放空间 ...
      free( a );

      // 等待用户输入任意一键返回 ...
      printf( "\n\n" );
      system( "PAUSE" );
	}
  }

  // 等待用户输入任意一键返回 ...
  printf( "\n\n" );
  system( "PAUSE" );
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
