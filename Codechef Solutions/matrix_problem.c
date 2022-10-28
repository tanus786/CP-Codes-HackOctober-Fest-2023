#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,k,n,m,angle,**arr,**arr1;
    scanf("%d %d",&n,&m);
    arr=(int**)malloc(sizeof(int*)*n);
    arr1=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        arr[i]=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        arr1[i]=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            arr1[i][j]=arr[i][j];
        }

    for(k=0;k<m;k++)
    {
        scanf("%d",&angle);
        if((angle/90)%4==0)
        {
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        printf("%d ",arr[i][j]);
                    }
                    printf("\n");
                }

        }
        else if((angle/90)%4==1)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    arr1[i][j]=arr[n-1-j][i];
                    printf("%d ",arr1[i][j]);
                }
                printf("\n");
            }

        }
        else if((angle/90)%4==2)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    arr1[i][j]=arr[n-1-i][n-1-j];
                    printf("%d ",arr1[i][j]);
                }
                printf("\n");
            }

        }

        else
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    arr1[i][j]=arr[j][n-1-i];
                    printf("%d ",arr1[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
