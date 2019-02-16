#include<stdio.h>
#include<limits.h>


void path(long long int * p,int i,int j,int n)
{
	if(*((p+n*i)+j)==-1)
	{
		if(i==j)
		{
			printf("%d \n",i);
			return;
		}
		
		printf("%d %d\n",i,j);
		return;
	}
	else {
		printf("%d ",i);
		path(p,*((p+n*i)+j),j,n);
	}

	
}

int main()
{
	int n,i,j,k;
	
	printf("Enter no. of vertices");
	scanf("%d",&n);
	
	long long int a[n][n],p[n][n];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
			p[i][j]=-1;
			if(a[i][j]==0&&i!=j)
			{
				a[i][j]=INT_MAX;
			}
			
		}
	}
	
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][k]==INT_MAX||a[k][j]==INT_MAX)
					continue;
				a[i][j]=a[i][j]<=(a[i][k]+a[k][j])?a[i][j]:INT_MIN;
				if(a[i][j]==INT_MIN)
				{
					a[i][j]=(a[i][k]+a[k][j]);
					p[i][j]=k;
				}
			}
		}
	}
	
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%lld ",a[i][j]);
			}
			
			printf("\n");
		}
		
		
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%lld ",p[i][j]);
			}
			
			printf("\n");
		}
		
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				path((long long int *)p,i,j,n);
			}
			
			printf("\n");
		}
	
	
}
/*
0 4 11
6 0 2
3 0 0
*/
