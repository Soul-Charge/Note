/* 2019.6.15;12:42 */
/* 二叉搜索树实现文件--tree.c */
/*  使用说明：
 *  将tree.h包含，并将tree.c进行多文件编译
 *  需要自行更改的内容：
 *      Item：二叉搜索树的项目的类型(tree.h内)
 *      ToLeft()和ToRight()：比较项目的函数，根据Item定义
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* 局部数据类型 */
typedef struct pair{
    Node * parent;
    Node * child;
} Pair;

/* 局部函数原型 */
static Node * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(Node * new_node, Node * root);
static void InOrder(const Node * root, void (* pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Node **ptr);
static void DeleteAllNodes(Node * ptr);

/* 函数定义 */
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Node * new_node;

    if (TreeIsFull(ptree)) //树满时提前返回
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if (SeekItem(pi, ptree).child != NULL) //防止重复内容
    {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;
    }
    /* 创造新节点 */
    new_node = MakeNode(pi); //指向新节点
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }
    /* 成功创造节点后  */
    ptree->size++;

    if (ptree->root == NULL)              //情况1：树为空树
        ptree->root = new_node;           //新节点即为树的根节点
    else                                  //情况2：树非空
        AddNode(new_node, ptree->root);   //把新节点放入树中
    return true;
}

bool InTree(const Item * pi, const Tree * ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;

    /* 分情况处理 */
    if (look.parent == NULL)
        DeleteNode(&ptree->root);
    else if (look.child == look.parent->left)
        DeleteNode(&look.parent->left);
    else if (look.child == look.parent->right)
        DeleteNode(&look.parent->right);
    ptree->size--;

    return true;
}

void Traverse(const Tree * ptree, void (* pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

/* 局部函数 */
static void InOrder(const Node * root, void (* pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Node * root)
{
    Node * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Node * new_node, Node * root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)      //空子树
            root->left = new_node;   //把节点添加到此处
        else
            AddNode(new_node, root->left);
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)      //空子树
            root->right = new_node;   //把节点添加到此处
        else
            AddNode(new_node, root->right);
    }
    else //项目相同时
    {
        fprintf(stderr, "location error in AddNode()\n"); 
        //因为相同项目检测在AddItem()就有了还能检测到就是这里内部问题
        exit(1);
    }
}
/* 用于判断大小的两个函数，需要根据Item类型的定义进行更改 */
static bool ToLeft(const Item * i1, const Item * i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
        return true;
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
        return true;
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
        return true;
    else
        return false;
}

static Node * MakeNode(const Item * pi)
{
    Node * new_node;

    new_node = (Node *)malloc(sizeof(Node));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root; //从树根开始

    if (look.child == NULL)
        return look;
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else //相等即找到
            break;
    }
    return look;
}

static void DeleteNode(Node **ptr)
/* ptr是指向目标节点的父节点指针成员的地址 */
{
    Node * temp;

    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else //被删除节点有两个子节点
    {
        /* 找到右子树的依附位置 */
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        //移动右子树
        temp->right = (*ptr)->right;        
        //重置指针位置
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}
/* 2019.6.15;18:16 */