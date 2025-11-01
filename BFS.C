#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int start)
{
q[++r]=start;
visited[start]=1;
for(i=1;i<=n;i++)
{
if(a[start][i]&&!visited[i])
{
q[++r]=i;
visited[i]=1;
printf("%d",q[r]);
bfs(q[f++]);
}
}
}
void main()
{
int v;
clrscr();
printf("\n Enter the number of vertices:");
scanf("%d",&n);
for(i=1;i<n;i++)
{
q[i]=0;
visited[i]=0;
}
printf("\nEnter values in adjacency matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("\n Enter the starting vertex:");
scanf("%d",&v);
printf("\n The node which are rechable are:\n);
printf("%d",v);
bfs(v);
getch();
}
