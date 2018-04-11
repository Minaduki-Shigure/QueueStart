#include"CircQueue.h"

/*
˼·����https://blog.csdn.net/u013050857/article/details/48912863

��˫�˶��д�ͷ����ʼ��Ԫ��ΪֵΪxi,��xi<xi+1 && a(xi)<a(xi+1)
���ȣ�Ϊ�˼���b0,��0�� k-1 ���μ�����У��ڼ���iʱ����˫�˶��е�ĩβ��ֵj����aj>=ai,�򲻶�ȡ��
ֱ��˫�˶���Ϊ�ջ���aj<ai֮������ĩβ����i

�ȵ� k-1 �����뵽�������棬�鿴����ͷ����ֵj����ôb0=aj,���j==0,��ô��֮��ļ��㲻���õ�������ɾȥ
��������Ϊ�˼���bi,��Ҫ�ڶ��е�ĩβ����k, ���ϼ���Ԫ�أ��Ϳ��Լ�������bi��ֵ������˫�˶��еļ����     
ɾ����������O(n)�Σ�����㷨���Ӷ�O(n)
��������������ģ�����£�
add 0 -> {0} (������±�)
add 1 -> {0,1}
add 2 -> {0,1,2}
b0=a0 =1;
remove 0 -> {1,2}
add 3 -> {1,3} (a2>=a3,���ɾ��2)
b1=a1=3;
remove 1 -> {3}
add 4 -> {4}  (a3>=a4,���ɾ��3)
b2=a4=2
*/

void solve(int n, int k,int a[])//a��ԭ����
{
	int b[100];//b�ǽ������
	int deq[100];//�½�����  
	int s = 0, t = 0; //ָ����е�ͷ����ĩβ  
	for (int i = 0; i < n; ++i)
	{
		//������˫�˶��е�ĩβ����a[i]���±�
		while (s < t&&a[deq[t - 1]] >= a[i]) t--;//������зǿ���ĩβ��ֵ����a[i]�򵯳���β��ֵ��ֱ��С��Ϊֹ
		deq[t++] = i;//����a[i]��i����β
		if (i - k + 1 >= 0)//���Ѿ�������k��Ԫ�ؾͿ�ʼ
		{
			b[i - k + 1] = a[deq[s]];//��ʱ��С��ֵ����a[]�е�deq[s]��Ԫ�ص�ֵ
			if (deq[s] == i - k + 1) s++;//����������{2��5��7}��������ʹ�˫�˶��е�ͷ��ɾ����һ��Ԫ�أ���2��  
		}
	}
	for (int i = 0; i <= n - k; ++i)
	{
		printf("%d%c", b[i], i == n - k ? '\n' : ' ');//���
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