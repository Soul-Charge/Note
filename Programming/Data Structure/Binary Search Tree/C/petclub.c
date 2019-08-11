/* 2019.6.15;18:17 */
/* petclub.c--测试二叉搜索树 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);

int main(void)
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while ( (choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a' : addpet(&pets);
                        break;
            case 'l' : showpets(&pets);
                        break;
            case 'f' : findpet(&pets);
                        break;
            case 'n' : printf("%d pets in club\n",
                                TreeItemCount(&pets));
                        break;
            case 'd' : droppet(&pets);
                        break;
            default  : puts("Switching error\n");
        }
    }

    DeleteAll(&pets);
    puts("Bye!");

    return 0;
}

char menu(void)
//显示菜单和获取选择并返回
{
    int ch;

    putchar('\n');
    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to you choice:");
    puts("a)add a pet       l)show list of pets");
    puts("n)number of pets  f)find pets");
    puts("d)delete a pet    q)quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n') //丢弃输入行剩余部分
            continue;
        ch = tolower(ch); //将输入转小写以使得大小写都可以匹配选项
        if (strchr("alnfdq", ch) == NULL)
            puts("Please enter an a, l, f, n, f, d, q:");
        else    
            break;
    }
    if (ch == EOF)
        ch = 'q';

    return ch;
}

void addpet(Tree * pt)
{
    Item temp;

    if (TreeIsFull(pt))
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet: ");
        fgets(temp.petname, STRLEN, stdin);
        puts("Please enter pet kind: ");
        fgets(temp.petkind, STRLEN, stdin);
        temp.petname[strlen(temp.petname)-1] = '\0';
        temp.petkind[strlen(temp.petkind)-1] = '\0';
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree * pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }

    puts("Please enter name of pet you wish to find: ");
    fgets(temp.petname, STRLEN, stdin);
    puts("Please enter pet kind");
    fgets(temp.petkind, STRLEN, stdin);
    temp.petname[strlen(temp.petname)-1] = '\0';
    temp.petkind[strlen(temp.petkind)-1] = '\0';
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (InTree(&temp, pt))
        printf("is a member.\n");
    else
        printf("is not a member.\n");
}

void droppet(Tree * pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }

    puts("Please enter name of pet you wish to delete: ");
    fgets(temp.petname, STRLEN, stdin);
    puts("Please enter pet kind");
    fgets(temp.petkind, STRLEN, stdin);
    temp.petname[strlen(temp.petname)-1] = '\0';
    temp.petkind[strlen(temp.petkind)-1] = '\0';
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (DeleteItem(&temp, pt))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void uppercase(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}