#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* 局部函数原型 */
static void CopyToNode(Item item, Node * pnode);

/* 接口函数 */

/* 把列表设置为空列表 */
void InitializeList(List * plist)
{
    *plist = NULL;
}

/* 如果列表为空返回真 */
bool ListIsEmpty(const List * plist)
{
    if (plist == NULL)
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
    unsigned int count = 0;
    Node * pnode = *plist; //列表开始处

    while (pnode != NULL)
    {
        count++;
        pnode = pnode->next;
    }
    return count;
}

/* 创建存放项目的节点，并添加到 */
/* 由plist指向的列表尾部 */
/* 较慢的实现方法，需要从头找到尾 */
bool AddItem(Item item, List * plist)
{
    Node * pnew;
    Node * scan = *plist;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)    //无法创造新节点时退出
    {
        fprintf(stderr, "Can't create new node.\n");
        system("pause");
        return false;
    }

    /* 处理新节点 */
    CopyToNode(item, pnew);
    pnew->next = NULL;

    /* 链接新节点 */
    if (scan == NULL)    //列表为空直接放头部
        *plist = pnew;
    else                 //列表不为空则添加到列表尾部
    {
        while(scan->next != NULL) //找到列表尾部
            scan = scan->next;
        scan->next = pnew;
        /***
        *注意是scan->next != NULL，如果用scan != NULL找到尾部将无法修改链接
        *因为scan虽然指向列表尾，但不是列表中最后一个节点的原指针，而是副本。
        ***/
    }
    return true;
}

/* 访问每个节点并对它们分别执行pfun执行的函数 */
void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = *plist; //创造头指针副本
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
    while (*plist != NULL) //遍历节点逐个释放
    {
        psave = *plist; //备份指针
        *plist = (*plist)->next;
        free(psave);
    }
}

/* 局部函数定义 */

/* 把一个项目复制到一个节点中 */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item; //结构复制
}