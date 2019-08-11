/* 2019.6.15;9:09 */
/* tree.h -- 二叉搜索树 */
/* 树中不允许有相同项目 */
/*  使用说明：
 *  将tree.h包含，并将tree.c一起编译
 *  需要自行更改的内容：
 *      Item：二叉搜索树的项目的类型
 *      ToLeft()和ToRight()：比较项目的函数，根据Item定义(tree.c内)
*/

#ifndef TREE_H //书中原内容是: _TREE_H_ 但这种风格C标准库保留使用所以不好
#define TREE_H
#include <stdbool.h>

//可根据需要修改Item的类型
#define STRLEN 20
typedef struct item {
    int value;
} Item;

#define MAXITEMS 30

typedef struct node {
    Item item;
    struct node * left;  //指向左分支的指针
    struct node * right; //指向右分支的指针
} Node;

typedef struct tree {
    Node * root; //指向树根的指针
    int size;    //树中项目个数
} Tree;//
//下面是函数原型

/* 操作：把一个树初始化为空树 */
/* 操作前：ptree指向一个树 */
/* 操作后：该树已被初始化为空树 */
void InitializeTree(Tree * ptree);

/* 操作：确定树是否为空 */
/* 操作前：ptree指向一个树 */
/* 操作后：树为空则返回true；否则返回false */
bool TreeIsEmpty(const Tree * ptree);

/* 操作：确定树是否已满 */
/* 操作前：ptree指向一个树 */
/* 操作后：树已满则返回true；否则返回false */
bool TreeIsFull(const Tree * ptree);

/* 操作：确定树中项目个数 */
/* 操作前：ptree指向一个树 */
/* 操作后：函数返回树中项目的个数 */
int TreeItemCount(const Tree * ptree);

/* 操作：向树中添加一个项目 */
/* 操作前：pi是待添加的项目的地址 */
/*        ptree是指向一个已经初始化的树 */
/* 操作后：如果可能，函数把项目 */
/*        添加到数中并返回true； */
/*        否则函数返回false */
bool AddItem(const Item * pi, Tree * ptree);

/* 操作：在树中查找一个项目 */
/* 操作前：pi指向一个项目 */
/*        ptree指向一个已经初始化的树 */
/* 操作后：如果项目在树中，则函数返回true； */
/*        否则返回false */
bool InTree(const Item * pi, const Tree * ptree);

/* 操作：从树中删除一个项目 */
/* 操作前：pi是待删除的项目的地址 */
/*        ptree是指向一个已经初始化的树 */
/* 操作后：如果可能，函数从树中删除项目 */
/*        并返回true；否则返回false */
bool DeleteItem(const Item * pi, Tree * ptree);

/* 操作：把一个函数作用于树中每一个项目 */
/* 操作前：ptree指向一个树 */
/*        pfun指向一个没有返回值的函数*/
/*        该函数接受一个Item类型值为参数 */
/* 操作后：pfun指向的函数被作用于 */
/*        树中每个项目一次 */
void Traverse(const Tree * ptree, void (* pfun)(Item item));

/* 操作：从树中删除所有节点 */
/* 操作前：ptree指向一个已经初始化的树 */
/* 操作后：该树为空树 */
void DeleteAll(Tree * ptree);

#endif
/* 2019.6.15;10:24 */