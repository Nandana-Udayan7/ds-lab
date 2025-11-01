#include<stdio.h>
#include<conio.h>
int a[20][20],visited[20],stack[20],top=0,n,count=0;
void dfs(int v)
{
int i;
for(i=1;i<=n;i++)
{
if(a[v][i]&&!visited[i])
{
stack[++top]=i;
visited[i]=1;
count++;
printf("\t%d",stack[top]);
dfs(i);
}
}
}
void main()
{
int i,j,v;
clrscr();
printf("\n Enter number of vertices:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
visited[i]=0;
}
printf("Enter the adjancency matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("\n Enter starting vertix:");
scanf("%d",&v);
printf("\n DFS:Nodes visited are \n");
stack[++top]=v;
visited[v]=1;
count++;
printf("%d",stack[top]);
dfs(v);
if(count==n)
{
printf("\n Graph is connected");
}
else
{
printf("\n Graph is not connected");
}
getch();
}
}