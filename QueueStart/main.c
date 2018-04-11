#include"CircQueue.h"

int main(void)
{
	int size = 100;
	int buffer = 0;
	puts("Creating the queue, please enter the size of the queue:");
	scanf_s("%d", &size);
	CircQueue Q = QueueInit(size);
	puts("Initializing the queue, please input the elements of the queue one by one with a '-1' as the end.");
	while (1)
	{
		scanf_s("%d", &buffer);
		if (buffer == -1)
			break;
		EnQueue(&Q, buffer);
	}
	puts("Queue sucessfully initialized!");
	QueuePrint(Q);
	system("pause");
	return 0;
}