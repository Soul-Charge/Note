/* 队列类型的实现文件 */
/* 需要根据头文件的项目定义修改ItemEqual()函数 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* 局部函数声明 */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);
static bool ItemEqual(Item item1, Item item2);

/* 接口函数定义 */
void InitializeQueue(Queue * pq)
{
    pq->font = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue * pq)
{
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue * pq)
{
    return pq->items == 0;
}

unsigned int QueueItemCount(const Queue * pq)
{
    return pq->items;
}

unsigned int QueueGoalItemCount(const Queue * pq, Item item)
{
    unsigned int count = 0;
    Node * temp;

    for (temp = pq->font; temp != NULL; temp = temp->next) //foreach
        if (ItemEqual(temp->item, item))
            count++;
    return count;
}

bool EnQueue(Queue * pq, Item item)
{
    Node * pnew;

    if (QueueIsFull(pq))
    {
        fprintf(stderr, "Queue is full!\n");
        return false;
    }
    /* 创造新节点 */
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr, "Can't create a new node.\n");
        return false;
    }
    /* 处理新节点 */
    CopyToNode(item, pnew);
    pnew->next = NULL;
    /* 链接新节点 */
    if (QueueIsEmpty(pq)) //队列为空，添加到首部
        pq->font = pnew;
    else                  //队列非空，添加到尾部
        pq->rear->next = pnew;
    /* 其他处理 */
    pq->rear = pnew;      //记录尾端位置
    pq->items++;
    return true;
}

bool DeQueue(Queue * pq, Item * pitem)
{
    Node * pt; //备份用

    if (QueueIsEmpty(pq)) //队列为空直接返回
        return false;

    CopyToItem(pq->font, pitem);
    pt = pq->font;              //备份首端指针
    pq->font = pq->font->next;  //前进到下一个节点
    free(pt);
    pq->items--;

    if (pq->items == 0)
        pq->rear = NULL;
    return true;
}

bool DeleteQueueItem(Queue * pq, Item item)
{
    Node * temp;
    Node * psave;

    if (QueueIsEmpty(pq))
        return false;

    if (ItemEqual(pq->font->item, item)) //要删除项目是头项目
    {
        psave = pq->font;
        pq->font = pq->font->next;
        free(psave);
    }
    else if (ItemEqual(pq->rear->item, item)) //要删除项目是尾项目
    {
        for (temp = pq->font; temp->next != pq->rear; temp = temp->next)//找到要删除项目所在节点的父节点指针
            continue;
        temp->next = NULL;
        free(pq->rear);
        pq->rear = temp;
    }
    else
    {
        //找到要删除项目所在节点的父节点指针
        for (temp = pq->font;
            temp->next != NULL && !ItemEqual(temp->next->item, item);
            temp = temp->next)
            continue;
        if (temp->next == NULL)
        {
            fprintf(stderr, "There is no such a item.\n");
            return false;
        }
        psave = temp->next;
        temp->next = temp->next->next;
        free(psave);
    }
    pq->items--;
    return true;
}

void TraverseQueue(const Queue * pq, void (*pfun)(Item item))
{
    Node * temp;

    for (temp = pq->font; temp != NULL; temp = temp->next)
        (*pfun)(temp->item);
}

void EmptyTheQueue(Queue * pq)
{
    Item dummy;
    while (!QueueIsEmpty(pq))
        DeQueue(pq, &dummy);
}

/* 局部函数定义 */
static void CopyToNode(Item item, Node * pn)
{
    pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi)
{
    *pi = pn->item;
}

static bool ItemEqual(Item item1, Item item2)
{
    if (item1.val == item2.val)
        return true;
    else
        return false;
}