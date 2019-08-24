#include "queue.h"

void init(MyQueue* q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

Node* getNode()
{
	return (Node*)calloc(1, sizeof(Node));
}

int isEmpty(MyQueue* q)
{
	return (q->front == NULL && q->rear == NULL);
}

void push(MyQueue* q, ELEMTYPE* data)
{
	Node* newNode = getNode();
	memcpy(newNode->data, data, sizeof(ELEMTYPE) * MAX_ELEM_NUMBER);

	if (isEmpty(q))
	{
		q->front = newNode;
		q->rear = newNode;
	}
	else
	{
		Node* behindNode = q->front;
		while (behindNode && behindNode->data[FCOST] < newNode->data[FCOST])
			behindNode = behindNode->next;

		if (behindNode == q->front)	/* conn to front */
		{
			newNode->next = behindNode;
			behindNode->prev = newNode;
			q->front = newNode;
		}
		else if (behindNode == NULL)	/* conn to rear */
		{
			newNode->prev = q->rear;
			q->rear->next = newNode;
			q->rear = newNode;
		}
		else	/* if node is not rear */
		{
			newNode->prev = behindNode->prev;
			newNode->next = behindNode;
			behindNode->prev->next = newNode;
			behindNode->prev = newNode;
		}
	}
	q->size++;
}

void pop(MyQueue* q, ELEMTYPE* dst)
{
	if (isEmpty(q))
		return;

	Node* delNode = q->front;
	memcpy(dst, delNode->data, sizeof(ELEMTYPE) * MAX_ELEM_NUMBER);

	if (q->front == q->rear) /* include only one member */
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		q->front = q->front->next;
		q->front->prev = NULL;
	}

	putNode(delNode);
	q->size--;
}

void putQueue(MyQueue* q)
{
	while (!isEmpty(q)) {
		Node* delNode = q->front;
		q->front = q->front->next;
		putNode(delNode);
		q->size--;

		if (!q->size) break;
	}
	free(q);
}

void putNode(Node* node)
{
	free(node);
}

int getFCostInQueue(MyQueue* q, int x, int y)
{
	Node* node = q->front;

	while (node && !(node->data[X] == x && node->data[Y] == y))
		node = node->next;

	return node ? node->data[FCOST] : 0;
}

//void print(MyQueue* q)
//{
//	if (isEmpty(q)) return;
//	Node* node = q->front;
//	while (node)
//	{
//		printf("(f, g, h, cx, cy): (%d, %d, %d, %d, %d)\n",
//			node->data[FCOST], node->data[GCOST], node->data[HCOST], node->data[X], node->data[Y]);
//		node = node->next;
//	}
//}
