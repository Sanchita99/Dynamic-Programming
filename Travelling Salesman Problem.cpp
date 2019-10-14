#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

#define min(a,b) (a)<(b)?(a):(b)

long long int val(long long int * a, int i,int j, int n){  //getting value from 2d array
	return *((a+i*n)+j);
}


void setValue(long long int * a, int i,int j, int n,long long int value){ //setting value for 2D array
	*((a+i*n)+j)=value;
}


long long int tsp(long long int * A,long long int *dp, int city, int mask, int all_visited, int n, int path[]){ //Function to solve travelling
																												//salesman problem
	int N = pow(2,n); //Number of rows of dp matrix
	if(mask==all_visited) // if mask in binary = 1111111.. upto n, it means all vertex are visited
		return val(A,city,0,n);

	if(val(dp,mask,city,N)!=-1){ //dp[mask][city] is not equal to -1, that means, it is already visited and the value of that element is returned
		
		return val(dp,mask,city,N)!=-1;
	}

	long long int minimum = INT_MAX;
	int i,j=-1;
	for(i=0;i<n;i++){ //for every element for 1 to n
		if((mask&(1<<i))==0) //check whether the vertex is visited or not.. If not, the proceed
		{
			long long int temp = val(A,city,i,n)+tsp(A,dp,i,(mask|(1<<i)),all_visited,n,path); //temp holds the distance through
																							   // intermediate vertex i and order of traversing
			minimum = min(minimum,temp); //minimum finds the minimum value for traversing if choose i as intermediate vertext to travel through
			if(minimum==temp){
				j=i;
			}
		}
	}
	setValue((long long int *)dp,mask,city,N,minimum); //set the value of dp array as obtained minimum so that they canbe used again 
													   // when needed
	return val((long long int *)dp,mask,city,N);       //returning the value of the minimum distance for TSP
}



int main(int argc, char const *argv[])
{
	printf("Enter Number of Vertices: ");
	int n; scanf("%d",&n);
	long long int A[n][n];
	int path[n];
	int N=pow(2,n);
	long long int dp[N][N];
	int i,j,k;

	for(i=0;i<n;i++){
		path[i]=-1;
		for(j=0;j<n;j++){
			scanf("%lld",&A[i][j]);
			if(i!=j && A[i][j]==0)
				A[i][j]=INT_MAX;
		}
	}

	int all_visited=(1<<n)-1; 
	int mask =1; //Treated as visited vertex in binary 0000001 which makes 1st vertex as visited

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			setValue((long long int *)dp,i,j,N,-1); //initiate the dp array with -1
		}
	}

	long long int source;
	printf("Enter Source Vertex: ");
	scanf("%lld",&source);
	printf("%d\n",all_visited);

	printf("\n%lld\n",tsp((long long int * )A,(long long int * )dp,0,mask, all_visited,n,path)); // printing the optimal cost 
	

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%lld ",val((long long int *)dp,i,j,N));
		}
		printf("\n");
	}	
	return 0;
}


/*

Enter Number of Vertices: 4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Enter Source Vertex: 0
15

80

*/

/*

Enter Number of Vertices: 4
0 20 42 25
20 0 30 34
42 30 0 10
25 34 10 0
Enter Source Vertex: 0
15

85

*/