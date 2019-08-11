/* list.h 简单列表类型的头文件 */
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

/* 根据需要修改 */
typedef struct item
{
    int val;
} Item;

/* 一般类型定义 */
typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct list
{
    Node * head;
    Node * tail;
    unsigned int size;
} List;

/* 函数原型 */

/* 操作：初始化一个列表            */
/* 操作前：plist指向一个列表       */
/* 操作后：该列表被初始化为空列表   */
void InitializeList(List * plist);

/* 操作：确定列表是否是空列表                      */
/* 操作前：plist指向一个已初始化的列表             */
/* 操作后：如果该列表为空则返回true，否则返回false  */
bool ListIsEmpty(const List * plist);

/* 操作：确定列表是否已满                         */
/* 操作前：plist指向一个已初始化的列表             */
/* 操作后：如果该列表已满则返回true，否则返回false  */
bool ListIsFull(const List * plist);

/* 操作：确定列表中项目的个数             */
/* 操作前：plist指向一个已初始化的列表    */
/* 操作后：返回该列表中项目的个数         */
unsigned int ListItemCount(const List * plist);

/* 操作：在列表尾部添加一个项目                 */
/* 操作前：item是要被增加到列表中的项目         */
/*         plist指向一个已初始化的列表         */
/* 操作后：如果可能，在列表尾部添加一个新项目    */
/*         函数返回true；否则返回false         */
bool AddListItem(List * plist, Item item);

/* 操作：删除列表中一个给定的项目            */
/* 操作前：plist指向一个已初始化的列表       */
/*        item为要删除的项目               */
/* 操作后：如果可能，删除列表中的item项目    */
/*        并返回true，否则返回false         */
bool DeleteListItem(List * plist, Item item);

/* 操作：把一个函数作用于列表的每个项目      */
/* 操作前：plist指向一个已初始化的列表      */
/*        pfun指向一个函数，该函数接受      */
/*        一个Item参数并且无返回值         */
/* 操作后：pfun指向的函数被作用到          */
/*        列表中每个项目一次              */
void TraverseList(const List * plist, void (*pfun)(Item item));

/* 操作：释放已分配的内存（如果有）       */
/* 操作前：plist指向一个已初始化的列表    */
/* 操作后：为该列表分配的内存已被释放     */
/*         并且该列表被置为空列表        */
void EmptyTheList(List * plist);

/* 操作：返回列表中给定项目的个数                  */
/* 操作前：plist指向一个已初始化的列表;            */
/*        item是需要计算数量的项目                */
/* 操作后：返回item项目在plist指向的列表中的数量   */
unsigned int ListGoalItemCount(const List * plist, Item item);

#endif 