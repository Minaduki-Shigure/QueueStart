#include"CircQueue.h"

void solve(int n, int k,int a[])
{
	int b[100];
	int deq[100];//双端队列  
	int s = 0, t = 0; //双端队列的头部和末尾  
	for (int i = 0; i < n; ++i)
	{
		//在双端队列的末尾加入i  
		while (s < t&&a[deq[t - 1]] >= a[i]) t--;
		deq[t++] = i;
		if (i - k + 1 >= 0)
		{
			b[i - k + 1] = a[deq[s]];
			if (deq[s] == i - k + 1) s++;//从双端队列的头部删除元素  
		}
	}
	for (int i = 0; i <= n - k; ++i)
	{
		printf("%d%c", b[i], i == n - k ? '\n' : ' ');
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