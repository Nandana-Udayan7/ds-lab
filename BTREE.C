#include<stdio.h>
#include<stdlib.h>
#define MAX 3
#define MIN 2
struct btreenode
{
int val[MAX+1],count;
struct btreenode*link[MAX+1];
};
struct btreenode*root;
struct btreenode*createnode(int val,struct btreenode*child)
{
struct btreenode*newnode;
newnode=(struct btreenode*)malloc(sizeof(struct btreenode));
newnode->val[1]=val;
newnode->count=1;
newnode->link[0]=root;
newnode->link[1]=child;
return newnode;
}
void insertnode(int val,int pos,struct btreenode*node,struct btreenode*child)
{
int j=node->count;
while(j>pos)
{
node->val[j+1]=node->val[j];
node->link[j+1]=node->link[j];
j--;
}
node->val[j+1]=val;
node->link[j+1]=child;
node->count++;
}
void splitnode(int val,int*pval,int pos,struct btreenode*node,struct btreenode*child,struct btreenode**newnode)
{
int median,j;
if(pos>MIN)
median=MIN+1;
else
median=MIN;
*newnode=(struct btreenode*)malloc(sizeof(struct btreenode));
j=median+1;
while(j<=MAX)
{
(*newnode)->val[j-median]=node->val[j];
(*newnode)->link[j-median]=node->link[j];
j++;
}
node->count=median;
(*newnode)->count=MAX-median;
if(pos<=MIN)
{
insertnode(val,pos,node,child);
}
else
{
insertnode(val,pos-median,*newnode,child);
}
*pval=node->val[node->count];
(*newnode)->link[0]=node->link[node->count];
node->count--;
}
int setvalue(int val,int *pval,struct btreenode*node,struct btreenode**child)
{
int pos;
if(!node)
{
*pval=val;
*child=NULL;
return 1;
}
if(val<node->val[1])
{
pos=0;
}
else
{
for(pos=node->count;(val<node->val[pos]&&pos>1);pos--);
if(val==node->val[pos])
{
printf("Duplicates are not permitted\n");
return 0;
}
}
if(setvalue(val,pval,node->link[pos],child))
{
if(node->count<MAX)
{
insertnode(*pval,pos,node,*child);
}
else
{
splitnode(*pval,pval,pos,node,*child,child);
return 1;
}
}
return 0;
}
void insert(int val)
{
int flag,i;
struct btreenode*child;
flag=setvalue(val,&i,root,&child);
if(flag)
root=createnode(i,child);
}
void traversal(struct btreenode*mynode)
{
int i;
if(mynode)
{
for(i=0;i<mynode->count;i++)
{
traversal(mynode->link[i]);
printf("\t%d",mynode->val[i+1]);
}
traversal(mynode->link[i]);
}
}
void main()
{
int val,ch;
clrscr();
insert(8);
insert(9);
insert(10);
insert(11);
insert(15);
insert(16);
insert(17);
insert(18);
insert(20);
insert(23);
traversal(root);
printf("\n");
getch();
}