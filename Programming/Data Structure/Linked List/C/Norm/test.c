#pragma list.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define MAX 1000

void showNode(Item item); //打印节点内容

int main(void)
{
    List test_list;
    InitializeList(&test_list);

    int i;
    Item item;

    for (i = 0; i < MAX; i++)
    {
        item.val = rand() % 101; //产生[0,100]的随机数
        AddItem(item, &test_list);
    }

    if (ListIsEmpty(&test_list))
        printf("List is empty.\n");
    else
        printf("List nodes: %d\n", ListItemCount(&test_list));

    Traverse(&test_list, showNode); //显示列表
    EmptyTheList(&test_list);

    if (ListIsEmpty(&test_list))
        printf("List is empty.\n");
    else
        printf("List nodes: %d\n", ListItemCount(&test_list));

    system("pause");
    return 0;
}

void showNode(Item item) //打印节点内容
{
    printf("%10d", item.val);
}