#include"CircQueue.h"

int main(void)
{
	int size = 100;
	char buffer = 0;
	puts("Creating the queue, please enter the size of the queue:");
	scanf_s("%d", &size);
	CircQueue Q = QueueInit(size);
	puts("Initializing the queue, please input the elements of the queue one by one with a '$' as the end.");
	while (1)
	{
		buffer = _getche();
		if (buffer == '$')
			break;
		EnQueue(&Q, buffer);
	}
	puts("\nQueue sucessfully initialized!");
	QueuePrint(Q);
	system("pause");
	return 0;
}