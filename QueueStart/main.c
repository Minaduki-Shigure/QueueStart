#include"CircQueue.h"

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

	system("pause");
	return 0;
}