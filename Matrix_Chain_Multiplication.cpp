#include<stdio.h>

int main()
{
	int n,i,j,k,min,l;
	
	scanf("%d",&n);
	
	int a[n+1],m[n][n],z[n][n];
	printf("Enter dimensions\n");
	for(i=0;i<n+1;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				m[i][j]=0;
			}
			else
			m[i][j]=100000;
			
			z[i][j]=100;
		}
	}
	
	for(l=1;l<n;l++)
	{
		for(i=0,j=i+l;i<n&&j<n;i=i+1,j=i+l)
		{
			for(k=i;k<=j-1;k++)
			{
				min=m[i][k]+m[k+1][j]+(a[i]*a[k+1]*a[j+1]);
				if(min<m[i][j])
				{
					m[i][j]=min;
					z[i][j]=k;
				}
			}
			
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",m[i][j]);
		}
		
		printf("\n");
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",z[i][j]);
		}
		
		printf("\n");
	}
	
	
}
