/* 单链表的实现文件，与list.h一起使用。 */
/* 需要自行根据需要修改ItemEqual()这一比较函数 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* 局部函数原型 */
static void CopyToNode(Item item, Node * pnode);
static bool ItemEqual(Item item1, Item item2); //判断两个项目是否相等

/* 接口函数 */

/* 把列表设置为空列表 */
void InitializeList(List * plist)
{
    plist->head = NULL;
    plist->tail = NULL;
    plist->size = 0;
}

/* 如果列表为空返回真 */
bool ListIsEmpty(const List * plist)
{
    if (plist->size == 0)
        return true;
    else
        return false;
}

/* 如果列表已满(没内存了）则返回真 */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    return full;
}

/* 返回节点数 */
unsigned int ListItemCount(const List * plist)
{
    return plist->size;
}

/* 创建存放项目的节点，并添加到 */
/* 由plist指向的列表尾部 */
bool AddListItem(List * plist, Item item)
{
    Node * pnew;
    Node * scan = plist->head;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)    //无法创造新节点时退出
    {
        fprintf(stderr, "Can't create new node.\n");
        return false;
    }

    /* 处理新节点 */
    CopyToNode(item, pnew);
    pnew->next = NULL;

    /* 链接新节点 */
    if (scan == NULL)    //列表为空直接放头部
        plist->head = pnew;
    else                 //列表不为空则添加到列表尾部
        plist->tail->next = pnew;

    /* 修改列表结构 */
    plist->tail = pnew; //无论列表是不是空，新节点都在列表尾部.
    plist->size++;

    return true;
}

bool DeleteListItem(List * plist, Item item)
{
    Node * temp;
    Node * psave; //备份用

    if (ListIsEmpty(plist))
        return false;

    if (ItemEqual(plist->head->item, item)) //要删除的项目是头项目
    {
        psave = plist->head;
        plist->head = plist->head->next;
        free(psave);
    }
    else if (ItemEqual(plist->tail->item, item)) //要删除的项目是尾项目
    {
        //不能直接用List结构的tail，因为要修改尾节点的父节点，所以只能遍历了。
        for (temp = plist->head; temp->next != plist->tail; temp = temp->next) //找到尾节点的父节点指针
            continue;
        temp->next = NULL;
        free(plist->tail);
        plist->tail = temp;
    }
    else //要删除的项目在列表中(非头非尾)
    {
        for (temp = plist->head; temp->next != NULL && !ItemEqual(temp->next->item, item);
            temp = temp->next) //找到指向目标项目所在节点的父节点的指针
            continue;
        if (temp->next == NULL)
        {
            fprintf(stderr, "There is no such a item.\n");
            return false;
        }
        psave = temp->next; //保存目标项目所在节点的指针
        temp->next = temp->next->next;
        free(psave);
    }
    plist->size--;
    return true;
}

/* 访问每个节点并对它们分别执行pfun执行的函数 */
void TraverseList(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = plist->head; //创造头指针副本
    while (pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

/* 释放由malloc()分配的内存 */
/* 把列表指针设置为NULL */
void EmptyTheList(List * plist)
{
    Node * psave; //备份用
    while (plist->head != NULL) //遍历节点逐个释放
    {
        psave = plist->head; //备份指针
        plist->head = plist->head->next;
        free(psave);
        plist->size--;
    }
    //plist->size = 0; 这样更快而且可能没问题，但感觉还是保险比较好放循环里。
}

unsigned int ListGoalItemCount(const List * plist, Item item)
{
    unsigned int count = 0;
    Node * temp;

    for (temp = plist->head; temp->next != NULL; temp = temp->next)
    {
        if (ItemEqual(temp->item, item))
        count++;
    }
    return count;
}

/* 局部函数定义 */

/* 把一个项目复制到一个节点中 */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item; //结构复制
}

static bool ItemEqual(Item item1, Item item2)
{
    if (item1.val == item2.val)
        return true;
    else
        return false;
}