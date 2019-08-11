#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

void showNode(Item item); //打印节点内容
void showListInfo(List * plist); //显示关于列表的信息
unsigned long get_ulong(void);
long get_long(void);
void eat_line(void);

int main(void)
{
    List test_list;
    InitializeList(&test_list);

    int i;
    Item item;
    unsigned long max; //the max nodes
    long delete_num; //the number which will be deleted

    srand((unsigned int)time(0));

    printf("Enter the number of nodes:");
    max = get_ulong();
    printf("Enter the number which you want to delete:");
    delete_num = get_long();

    showListInfo(&test_list);
    system("pause");

    printf("Using %lu random full the list.\n", max);
    for (i = 0; i < max; i++)
    {
        item.val = rand() % 101; //产生[0,100]的随机数
        AddListItem(&test_list, item);
    }
    puts("Done!");
    showListInfo(&test_list);
    system("pause");

    item.val = delete_num;
    printf("There are %u %ld.\n", ListGoalItemCount(&test_list, item), delete_num);
    printf("Now I delete all the number of %ld.\n", delete_num);
    i = 0;
    while (DeleteListItem(&test_list, item))
    {
        printf("You had deleted %d.\n", ++i);
    }
    puts("Done!");
    showListInfo(&test_list);
    system("pause");

    puts("Now I empty the list.");
    EmptyTheList(&test_list);
    puts("Done!");
    showListInfo(&test_list);

    system("pause");
    return 0;
}

void showNode(Item item) //打印节点内容
{
    printf("%5d", item.val);
}

void showListInfo(List * plist)
{
    puts("The list:");
    if (ListIsEmpty(plist))
        printf("is empty!\n");
    else
        TraverseList(plist, showNode);

    putchar('\n');
    printf("The list has %d nodes.\n", ListItemCount(plist));

    if (ListIsFull(plist))
        printf("The list is full.\n");
    else
        printf("The list is not full.\n");
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