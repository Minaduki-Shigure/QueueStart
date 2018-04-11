#include"CircQueue.h"

/*
思路来自https://blog.csdn.net/u013050857/article/details/48912863

设双端队列从头部开始的元素为值为xi,则xi<xi+1 && a(xi)<a(xi+1)
首先，为了计算b0,把0到 k-1 依次加入队列，在加入i时，当双端队列的末尾的值j满足aj>=ai,则不断取出
直到双端队列为空或者aj<ai之后再在末尾加入i

等到 k-1 都加入到队列里面，查看队列头部的值j，那么b0=aj,如果j==0,那么在之后的计算不会用到，所以删去
接下来，为了计算bi,需要在队列的末尾加入k, 不断加入元素，就可以计算后面的bi的值，由于双端队列的加入和     
删除都进行了O(n)次，因此算法复杂度O(n)
对于样例，队列模拟如下：
add 0 -> {0} (存的是下标)
add 1 -> {0,1}
add 2 -> {0,1,2}
b0=a0 =1;
remove 0 -> {1,2}
add 3 -> {1,3} (a2>=a3,因此删除2)
b1=a1=3;
remove 1 -> {3}
add 4 -> {4}  (a3>=a4,因此删除3)
b2=a4=2
*/

void solve(int n, int k,int a[])//a是原数组
{
	int b[100];//b是结果数组
	int deq[100];//新建队列  
	int s = 0, t = 0; //指向队列的头部和末尾  
	for (int i = 0; i < n; ++i)
	{
		//下面在双端队列的末尾加入a[i]的下标
		while (s < t&&a[deq[t - 1]] >= a[i]) t--;//如果队列非空且末尾的值大于a[i]则弹出队尾的值，直到小于为止
		deq[t++] = i;//插入a[i]的i至队尾
		if (i - k + 1 >= 0)//若已经看过了k个元素就开始
		{
			b[i - k + 1] = a[deq[s]];//此时最小的值就是a[]中第deq[s]个元素的值
			if (deq[s] == i - k + 1) s++;//比如现在是{2，5，7}的情况，就从双端队列的头部删除第一个元素（即2）  
		}
	}
	for (int i = 0; i <= n - k; ++i)
	{
		printf("%d%c", b[i], i == n - k ? '\n' : ' ');//输出
	}
	return 0;
}

int main(void)
{
	int i = 0;
	int n = 0;
	int k = 0;
	int buffer = 0;
	puts("Please enter the value of n:");
	scanf_s("%d", &n);
	CircQueue Q1 = QueueInit(n + 1);
	puts("Please input all the numbers one by one.");
	while (i < n)
	{
		scanf_s("%d", &buffer);
		EnQueue(&Q1, buffer);
		i++;
	}
	puts("Numbers sucessfully loaded!");
	puts("Please enter the value of k:");
	scanf_s("%d", &k);
	puts("Ready to start!");
	printf("n = %d\tk = %d\nThe numbers are:\n", n, k);
	QueuePrint(Q1);
	puts("Press any key to start the compare!");
	system("pause");
	solve(n, k, Q1.base);
	system("pause");
	return 0;
}