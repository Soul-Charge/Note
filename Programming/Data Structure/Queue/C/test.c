#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

void showNode(Item item); //打印节点内容
void showQueueInfo(Queue * pq); //显示关于列表的信息
unsigned long get_ulong(void);
long get_long(void);
void eat_line(void);

int main(void)
{
    Queue test_queue;
    InitializeQueue(&test_queue);

    int i;
    Item item;
    unsigned long max; //the max nodes
    long delete_num; //the number which will be deleted

    srand((unsigned int)time(0));

    printf("Enter the number of nodes:");
    max = get_ulong();
    printf("Enter the number which you want to delete:");
    delete_num = get_long();

    showQueueInfo(&test_queue);
    system("pause");

    printf("Using %lu random full the queue.\n", max);
    for (i = 0; i < max; i++)
    {
        item.val = rand() % 101; //产生[0,100]的随机数
        EnQueue(&test_queue, item);
    }
    puts("Done!");
    showQueueInfo(&test_queue);
    system("pause");

    item.val = delete_num;
    printf("There are %u %ld.\n", QueueGoalItemCount(&test_queue, item), delete_num);
    printf("Now I delete all the number of %ld.\n", delete_num);
    i = 0;
    while (DeleteQueueItem(&test_queue, item))
    {
        printf("You had deleted %d.\n", ++i);
    }
    puts("Done!");
    showQueueInfo(&test_queue);
    system("pause");

    puts("Now I extract 10 items.");
    puts("Here is them:");
    for (i = 0; i < 10; i++)
    {
        DeQueue(&test_queue, &item);
        printf("    %3d", item.val);
    }
    putchar('\n');
    puts("Done");
    showQueueInfo(&test_queue);
    system("pause");

    puts("Now I empty the queue.");
    EmptyTheQueue(&test_queue);
    puts("Done!");
    showQueueInfo(&test_queue);

    system("pause");
    return 0;
}

void showNode(Item item) //打印节点内容
{
    printf("%5d", item.val);
}

void showQueueInfo(Queue * pq)
{
    puts("The queue:");
    if (QueueIsEmpty(pq))
        printf("is empty!\n");
    else
        TraverseQueue(pq, showNode);

    putchar('\n');
    printf("The queue has %d nodes.\n", QueueItemCount(pq));

    if (QueueIsFull(pq))
        printf("The queue is full.\n");
    else
        printf("The queue is not full.\n");
}

unsigned long get_ulong(void)
{
    unsigned long input;
    char ch;

    while (scanf("%lu", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        puts("is not a unsigned integer.");
        puts("Please enter a unsigned integer");
    }
    eat_line();
    return input;
}

long get_long(void)
{
    long input;
    char ch;

    while (scanf("%ld", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        puts(" is not a integer.");
        puts("Please enter a integer");
    }
    eat_line();
    return input;
}

void eat_line(void)
{
    char ch;
    while ((ch = getchar()) != '\n')
        continue;
}