#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilities.h"

typedef int ELEMTYPE;

typedef struct QueueNode {
	ELEMTYPE data[MAX_ELEM_NUMBER];	/* fCost, gCost, hCost, y, x */
	struct QueueNode* prev, * next;
} Node;

typedef struct {
	Node* front, * rear;
	int size;
} MyQueue;

void init(MyQueue* q);
Node* getNode();
int isEmpty(MyQueue* q);
void push(MyQueue* q, ELEMTYPE* data);
void pop(MyQueue* q, ELEMTYPE* dst);
void putQueue(MyQueue* q);
void putNode(Node* node);
int getFCostInQueue(MyQueue* q, int x, int y);
//void print(MyQueue* q);
