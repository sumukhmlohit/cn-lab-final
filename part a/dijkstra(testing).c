
#include<stdio.h>
int a[200][200],mat[200][200],visited[200],via[200][200],n;
void dijkstra(int source)
{   int i,j,k;
    visited[source]=1;

    for(i=0;i<n;i++)
    {
        mat[source][i]=mat[i][source]=a[source][i];
    }

    for(i=0;i<n;i++){
    if(a[source][i]!=999)
    {
        visited[i]=1;
        mat[source][i]=mat[i][source]=a[source][i];
        via[source][i]=source;
    }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(mat[source][j]+mat[j][k]<mat[source][k])
                {
                    mat[source][k]=mat[source][j]+mat[j][k];
                    visited[k]=1;
                    via[source][k]=j;
                }
            }
        }
    }


        for(j=0;j<n;j++)
        {
            printf("Shortest distance from source to %d is %d via %d\n",j,mat[source][j],via[source][j]);
        }

}

void main()
{   int source;
    printf("Enter no of nodes\n");
    scanf("%d",&n);
    printf("Enter cost matrix\n");
    int i,j;
    for(i=0;i<n;i++)
    {  { for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        }
    }

    for(i=0;i<n;i++)
    {   for(j=0;j<n;j++)
        {
           mat[i][j]=a[i][j];
        }
    }
    printf("Enter source node\n");
    scanf("%d",&source);
    dijkstra(source);

    for(i=0;i<n;i++)
    {   for(j=0;j<n;j++)
        {
           printf("%d ",mat[i][j]);
        }printf("\n");
    }
}
