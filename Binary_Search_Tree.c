#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>  

void clrscr() // Ham clear man hinh
{
    system("@cls||clear");
}

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *tree;

void khoitaocay(node *tree)
{
    tree = NULL;   
}

node *themnodevaocay(node *tree, int x)  // khác với c++ thì có thể dùng hàm void và truyền thẳng gía trị mà không cần gán lại node left, right
{
    if (tree == NULL)
    {
        node *p = (node*) malloc (sizeof(node));
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        tree = p;    // node p chính là node gốc 
    }
    else   // cây có tồn tại phần tử 
    {
        if (tree->data > x)  // nếu phần tử thêm vào mà nhỏ hơn node gốc => thêm nó vào bên trái
        {   
            tree->left = themnodevaocay(tree->left, x);
        }
        else if (tree->data < x)  // nếu phần tử thêm vào mà lớn hơn node gốc => thêm nó vào bên phải
        {
            tree->right = themnodevaocay(tree->right, x);
        }
    }
    return tree;
}

void xuatcay_NLR(node *tree)
{
    if (tree != NULL)    //nếu cây còn phần tử thì tiếp tục duyệt 
    {   
        printf("%d  ",tree->data);
        xuatcay_NLR(tree->left);
        xuatcay_NLR(tree->right);
    }
}

int main()
{   
    khoitaocay(tree);
    int  k; 
    char so;
    do 
    {   
        clrscr();
        printf("1:PUSH:Nhap du lieu.\n");
        printf("2:Xuat du lieu cay NLR.\n");
        printf("3:Thoat chuong trinh.\n");
        printf("Hay chon cac options tu 1-3: \n");
        scanf("%c", &so);

        switch(so)
        {
            case '1':
            printf("Hay nhap phan tu vao TREE:\n");
            scanf("%d", &k);
            tree = themnodevaocay(tree, k);
            system("pause");
            break;

            case '2':
            printf("Cac phan tu trong TREE la:\n");
            xuatcay_NLR(tree);
            system("pause");
            break;
            
            case '3': 
            break;    
        }
    }
    while (so != '3');
}