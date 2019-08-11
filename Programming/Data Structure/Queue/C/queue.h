/* 队列类型的头文件 */
#pragma c9x on //support for stdbool.h
#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdbool.h>

/* definition of Item here */
/* example */
typedef struct item
{
    int val;
} Item;

/* limit of length */
#define MAXQUEUE 10000

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct queue
{
    Node * font;
    Node * rear;
    unsigned int items;
} Queue;

/* 操作：初始化队列                */
/* 操作前：pq指向一个队列          */
/* 操作后：该队列被初始化为空队列   */
void InitializeQueue(Queue * pq);

/* 操作：检查队列是否已满                   */
/* 操作前：pq指向一个已初始化的队列          */
/* 操作后：队列已满返回true；否则返回false   */
bool QueueIsFull(const Queue * pq);

/* 操作：检查队列是否为空                   */
/* 操作前：pq指向一个已初始化的队列          */
/* 操作后：队列为空返回true；否则返回false   */
bool QueueIsEmpty(const Queue * pq);

/* 操作：确定队列中项目的个数         */
/* 操作前：pq指向一个已初始化的队列   */
/* 操作后：返回队列中项目的个数       */
unsigned int QueueItemCount(const Queue * pq);

/* 操作：返回队列中给定项目的个数      */
/* 操作前：pq指向一个已初始化的队列    */
/*        item是要计算个数的项目      */
/* 操作后：返回队列中给定项目的个数     */
unsigned int QueueGoalItemCount(const Queue * pq, Item item);

/* 操作：向队列尾端添加项目                         */
/* 操作前：pq指向一个已初始化的队列                  */
/*        item是要添加到队列尾端的项目              */
/* 操作后：如果队列未满，item被添加到队列尾部        */
/*        函数返回true，否则不改变队列并返回false   */
bool EnQueue(Queue * pq, Item item);

/* 操作：从队列首端删除项目                     */
/* 操作前：pq指向一个已初始化的队列             */
/* 操作后：如果队列非空，队列首端的项目         */
/*        被复制到*pitem，并从队列中删除，     */
/*        函数返回true，如果此操作使队列为空   */
/*        则把队列重置为空队列                */
/*        如果队列开始时为空                  */
/*        则不改变队列，函数返回false         */
bool DeQueue(Queue * pq, Item * pitem);

/* 操作：从队列中删除一个给定的项目 */
/* 操作前：pq指向一个已初始化的队列 */
/*        item是要删除的项目 */
/* 操作后：如果可能，删除队列中的所有给定项目 */
/*        并返回true，否则返回false */
bool DeleteQueueItem(Queue * pq, Item item);

/* 操作：将一个函数作用于队列中的每一个项目   */
/* 操作前：pq指向一个已初始化的队列            */
/*        pfun指向一个函数，该函数接受      */
/*        一个Item参数并且无返回值          */
/* 操作后：pfun指向的函数被作用到            */
/*        队列的每个项目一次                */
void TraverseQueue(const Queue * pq, void (*pfun)(Item item));

/* 操作：清空队列                    */
/* 操作前：pq指向一个已初始化的队列   */
/* 操作后：队列被清空                */
void EmptyTheQueue(Queue * pq);

#endif