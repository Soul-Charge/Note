#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void showNums(Item item);

int main(void)
{
    int i;
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 10, 11, 12, 14, 15, 16, 17, 13, 19, 20, 18};
    Item item;
    Tree nums;

    InitializeTree(&nums);
    for (i = 0; i < 20; i++)
    {
        item.value = arr[i];
        AddItem(&item, &nums);
    }
    Traverse(&nums, showNums);
    putchar('\n');
    system("pause");
    return 0;
}

void showNums(Item item)
{
    printf("%d ", item.value);
}