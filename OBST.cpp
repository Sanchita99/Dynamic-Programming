#include<stdio.h>

int main()
{
	int n,i,j,k,l,min;
	
	printf("Enter number of identifiers");
	scanf("%d",&n);
	
	int p[n],q[n+1],w[n+1][n+1],c[n+1][n+1],r[n+1][n+1];
	
	printf("Enter internal probabilities");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
		
	printf("Enter external probabilities");
	for(i=0;i<=n;i++)
		scanf("%d",&q[i]);
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==j)
			{
				w[i][j]=q[j];
				c[i][j]=0;
				r[i][j]=0;
			}
			else
			{
				w[i][j]=10000;
				c[i][j]=10000;
				r[i][j]=10000;
			}
		}
	}
	
	for(l=1;l<=n;l++)
	{
		for(i=0,j=i+l;i<=n&&j<=n;i=i+1,j=i+l)
		{
			w[i][j]=p[j-1]+q[j]+w[i][j-1];
				
			for(k=i+1;k<=j;k++)
			{
				min=c[i][k-1]+c[k][j]+w[i][j];
				
				if(min<c[i][j])
				{
					c[i][j]=min;
					r[i][j]=k;
				}
			}
		}
		printf("\n");
	}
	
	printf("\nWeight Matrix\n");
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%d ",w[i][j]);
		}
		printf("\n");
	}
	
	printf("\nCost matrix\n");
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	
	printf("\nk Matrix\n");

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%d ",r[i][j]);
		}
		printf("\n");
	}
}
