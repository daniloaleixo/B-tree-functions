# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h> 

char getch(){
    /*#include <unistd.h>   //_getch*/
    /*#include <termios.h>  //_getch*/
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
 }

typedef struct BST
{
    int data;
    struct BST *lchild,*rchild;
}node;

void insert(node *,node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *,int,node **);

void main()
{
 int choice;
 char ans='N';
 int key;
 node *new_node,*root,*tmp,*parent;
 node *get_node();
 root=NULL;
 system("clear");

 printf("***Programa de busca em arvores binarias***\n");
 do
 {
   printf("1 - Criar\n");
   printf("2 - Buscar\n");
   printf("3 - Imprimir\n");
   printf("4 - Sair\n");
   printf("Faca a sua escolha :\n");
   scanf("%d",&choice);

   switch(choice)
   {
    case 1:
           do
             {
             new_node=get_node();

             printf("Entre com o elemento ");
             scanf("%d",&new_node->data);

             if(root==NULL)   /* Tree is not Created */
                 root=new_node;
             else
                 insert(root,new_node);

             printf("Gostaria de inserir mais elementos?(y/n)\n");
             ans=getch();

             }while(ans=='y');

             break;

     case 2:
             printf("Entre com o numero a ser buscado :");
             scanf("%d",&key);

             tmp = search(root,key,&parent);

             printf("Pai do no %d eh %d\n",
                              tmp->data,parent->data);
             break;

    case 3:

            if(root==NULL)
                printf("Arvore vazia\n");
            else
               {
               printf("Arvore em Ordem-Sim.: ");
               inorder(root);
               printf("\n");
               printf("Arvore em Pre-Ordem:  ");
               preorder(root);
               printf("\n");
               printf("Arvore em Pos-Ordem:  ");
               postorder(root);
               printf("\n\n");
               }

            break;
    }
 }while(choice!=4);
}
/*
  Get new Node 
*/
node *get_node()
 {
 node *temp;
 temp=(node *)malloc(sizeof(node));
 temp->lchild=NULL;
 temp->rchild=NULL;
 return temp;
 }
/*
  This function is for creating a binary search tree 
*/
void insert(node *root,node *new_node)
{
  if(new_node->data < root->data)
     {
     if(root->lchild==NULL)
         root->lchild = new_node;
     else
         insert(root->lchild,new_node);
     }

  if(new_node->data > root->data)
     {
     if(root->rchild==NULL)
         root->rchild=new_node;
     else
         insert(root->rchild,new_node);
     }
}
/*
This function is for searching the node from
      binary Search Tree
*/
node *search(node *root,int key,node **parent)
{
 node *temp;
 temp=root;
    while(temp!=NULL)
    {
      if(temp->data==key)
         {
         printf("O elemento %d esta presente na Arvore\n",temp->data);
         return temp;
         }
      *parent=temp;

      if(temp->data>key)
         temp=temp->lchild;
      else
         temp=temp->rchild;
    }
 return NULL;
}
/*
This function displays the tree in inorder fashion
*/
void inorder(node *temp)
{
   if(temp!=NULL)
    {
    inorder(temp->lchild);
    printf("%d  ",temp->data);
    inorder(temp->rchild);
    }
}
/*
This function displays the tree in preorder fashion
*/
void preorder(node *temp)
{
 if(temp!=NULL)
    {
    printf("%d  ",temp->data);
    preorder(temp->lchild);
    preorder(temp->rchild);
    }
}

/*
This function displays the tree in postorder fashion
*/
void postorder(node *temp)
{
 if(temp!=NULL)
    {
    postorder(temp->lchild);
    postorder(temp->rchild);
    printf("%d  ",temp->data);
    }
}

