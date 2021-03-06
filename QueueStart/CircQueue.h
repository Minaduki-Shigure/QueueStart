#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<conio.h>

typedef char QElemType;

typedef struct {
	QElemType *base;
	int front;
	int rear;
	int size;
}CircQueue;

CircQueue QueueInit(int size);
void QueueDestroy(CircQueue *Q);
int QueueLength(CircQueue Q);
int EnQueue(CircQueue *Q, QElemType e);
QElemType DeQueue(CircQueue *Q);
int QueuePrint(CircQueue Q);