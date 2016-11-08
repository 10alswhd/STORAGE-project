//���� ���Ḯ��Ʈ - ���� ����(���� �ֱٿ� ������ �����Ͱ� �� ��)
//��� ����, �ʱ�ȭ, �߰�, ����, �˻�, ��ü ���, ����
#include <stdio.h>
#include <stdlib.h>

typedef struct Node//��� ����
{
    int data;//������
    struct Node *next;//��ũ(���� ����� ��ġ ����)
    struct Node *prev;//��ũ(���� ����� ��ġ ����)
}Node;

void InitList(Node **phead);//�ʱ�ȭ
void AddData(Node **phead, int data);//������ �߰�
void Remove(Node **phead, Node *now);//��� ����
Node *Find(Node *seek, int data);//��� �˻�
void ViewAll(Node *head);//��ü ���
void Clear(Node **head);//����

int main(void)
{
    Node *head;
    {//�ʱ�ȭ �� �߰� �׽�Ʈ�� ���� ���
        InitList(&head);
        AddData(&head, 3); //3
        AddData(&head, 4); //4 3
        AddData(&head, 6); //6 4 3
        AddData(&head, 9); //9 6 4 3
        ViewAll(head);// 9 6 4 3 ���
    }

    {//�˻��� ���� �׽�Ʈ�� ���� ���
        Node *seek = Find(head, 4);
        if (seek)
        {
            printf("4�� ������ ��带 ã����\n");
            Remove(&head, seek); //9 6 3
            printf("4�� ������ ��� ���� ��\n");
            ViewAll(head);// 9 6 3 ���
        }
    }
    Clear(&head);//��ü ����
    printf("��ü ���� ��\n");
    ViewAll(head);// �ƹ��͵� ������� ����

    return 0;
}

void InitList(Node **phead)
{
    *phead = NULL;
}
void AddData(Node **phead, int data)
{
    Node *now = (Node *)malloc(sizeof(Node));//���ο� ��� ����
    now->data = data; //������ ��忡 data ����
    now->prev = NULL;//������ ����� prev�� NULL�� ����

                     //*phead�� ����Ʈ�� �� �տ� ����� ��ġ �����Դϴ�.
    now->next = (*phead);//���� ������ ����� next�� (*phead)�� ����
    if (*phead)//�� �� ��尡 �ִٸ�(*phead �� NULL�� �ƴϸ�)
    {
        (*phead)->prev = now;
    }
    *phead = now;//(*phead)�� now�� ����
}

void Remove(Node **phead, Node *now)
{
    if (now->prev)//now�� ���� ��尡 �ִٸ�
    {
        now->prev->next = now->next;//���� ����� next�� now�� ���� ���� ����
    }
    else//now�� ���� ��尡 ���ٸ�(now�� �� �� ���)
    {
        *phead = now->next;//�� �� ��带 now�� ���� ���� ����
    }
    if (now->next)//now�� ���� ��尡 �ִٸ�
    {
        now->next->prev = now->prev;//���� ����� prev�� now�� ���� ���� ����
    }
    free(now);//��� �Ҹ�
}

Node *Find(Node *seek, int data)
{
    while (seek) //seek�� ���̸�(NULL �� �ƴϸ�)
    {
        if (seek->data == data)//ã���� ��
        {
            return seek;
        }
        seek = seek->next;//seek�� �������� �̵�
    }
    return NULL;//�� ã���� ��
}
void ViewAll(Node *head)
{
    Node *seek = head;
    int i = 0;
    if (head == NULL)
    {
        printf("�� ������\n");
        return;
    }
    while (seek) //seek�� ���̸�(NULL �� �ƴϸ�)
    {
        i++;
        printf("[%2d]:%-05d ", i, seek->data);

        if (i % 5 == 0)//5�� ����� ��
        {
            printf("\n");//����
        }
        seek = seek->next;//seek�� �������� �̵�
    }
    printf("\n");
}

void Clear(Node **head)
{
    Node *prev = NULL;
    Node *seek = *head;
    while (seek) //seek�� ���̸�(NULL �� �ƴϸ�)
    {
        prev = seek;//seek�� �����ϱ� ���� prev�� ���
        seek = seek->next;//seek�� �������� �̵�
        free(prev);//���� ��� �޸� ����
    }
    *head = NULL;//���� �� �� ��尡 ����
}
