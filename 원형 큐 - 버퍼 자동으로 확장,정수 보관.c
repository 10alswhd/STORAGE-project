//���� ť - ���� �ڵ����� Ȯ��, ���� ����
#include <stdio.h>
#include <stdlib.h>

#define NEXT(index,QSIZE)   ((index+1)%QSIZE)  //���� ť���� �ε����� �����ϴ� ��ũ�� �Լ�

typedef struct Queue //Queue ����ü ����
{
    int *buf;//�����
    int qsize;
    int front; //���� �ε���(���� �������� ������ �����Ͱ� �ִ� �ε���)
    int rear;//������ �ε���
    int count;//���� ����

}Queue;

Queue *NewQueue();//������
void DeleteQueue(Queue *queue);//�Ҹ���
int IsEmpty(Queue *queue); //ť�� ������� Ȯ��
void Enqueue(Queue *queue, int data); //ť�� ����
int Dequeue(Queue *queue); //ť���� ����

int main(void)
{
    int i;
    Queue *queue = NewQueue();//���� ����

    for (i = 1; i <= 5; i++)//1~5���� ť�� ����
    {
        Enqueue(queue, i);
    }
    while (!IsEmpty(queue))//ť�� ������� �ʴٸ� �ݺ�
    {
        printf("%d ", Dequeue(queue));//ť���� ������ �� ���
    }
    printf("\n");

    DeleteQueue(queue);//�Ҹ�
    return 0;
}

void InitQueue(Queue *queue, int qsize);//ť �ʱ�ȭ
Queue *NewQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));//���� �޸� �Ҵ�
    InitQueue(queue, 1);//ť �ʱ�ȭ
    return queue;
}
void InitQueue(Queue *queue, int qsize)
{
    queue->buf = (int *)malloc(sizeof(int)*qsize);//���۸� ���� �޸� �Ҵ�
    queue->qsize = qsize;
    queue->front = queue->rear = 0; //front�� rear�� 0���� ����
    queue->count = 0;//���� ������ 0���� ����
}

void DisposeQueue(Queue *queue);//ť ����ȭ
void DeleteQueue(Queue *queue)
{
    DisposeQueue(queue);//���� �޸� ����
    free(queue);//ť �޸� ����
}
void DisposeQueue(Queue *queue)
{
    free(queue->buf);//���� �޸� ����
}

int IsFull(Queue *queue)
{
    return queue->count == queue->qsize;//���� ������ qsize�� ������ �� �� ����
}
int IsEmpty(Queue *queue)
{
    return queue->count == 0;    //���� ������ 0�̸� �� ����
}
void Expand(Queue *queue);//���� Ȯ��
void Enqueue(Queue *queue, int data)
{
    if (IsFull(queue))//ť�� �� á�� ��
    {
        Expand(queue);//���� Ȯ��
    }
    queue->buf[queue->rear] = data;//rear �ε����� ������ ����
    queue->rear = NEXT(queue->rear, queue->qsize); //rear�� ���� ��ġ�� ����
    queue->count++;//���� ������ 1 ����
}
void Expand(Queue *queue)
{
    int i = 0;
    int count;
    int *buf = (int *)malloc(sizeof(int)*queue->qsize);//�ӽ� ����� �޸� �Ҵ�
    count = queue->count;//���� ���� ���
    for (i = 0; i<count; i++)//ť�� �ִ� ������ buf�� ����(������ �������)
    {
        buf[i] = Dequeue(queue);
    }
    queue->qsize *= 2;//ť ũ�� 2��� Ȯ��
    queue->buf = (int *)realloc(queue->buf, sizeof(int)*queue->qsize);//���� Ȯ��
    for (i = 0; i<count; i++)//�ӽ� ����ҿ� ������ ������ �ٽ� ť�� ����
    {
        Enqueue(queue, buf[i]);
    }
    free(buf);//�ӽ� ����� �޸� ����

}
int Dequeue(Queue *queue)
{
    int re = 0;
    if (IsEmpty(queue))//ť�� ����� ��
    {
        printf("ť�� �����\n");
        return re;
    }
    re = queue->buf[queue->front];//front �ε����� ������ ���� re�� ����
    queue->front = NEXT(queue->front, queue->qsize);//front�� ���� ��ġ�� ����
    queue->count--;//���� ������ 1 ����
    return re;
}