#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 3


void *determinant(void *param[]); 
void *adjoint(void *param[]);

int determinantOfMatrix(int mat[N][N], int n);
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n);


int det;
int m[N][N];
int adj[N][N];

int main()
{
	int i,j;
	float inverse[N][N];
	printf("\nEnter the matrix:\n");
	for(i=0;i<N;i++)
	{	
		for(j=0;j<N;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}

	pthread_t tid[2];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	pthread_create(&tid[0],&attr,determinant,NULL);
	pthread_create(&tid[1],&attr,adjoint,NULL);
	
	pthread_join(tid[0],NULL);
	if(det==0)
	{
		pthread_cancel(tid[1]);
		printf("\nDeterminant = 0 . Inverse cannot be computed\n");
	
	}
	else	
	{
		pthread_join(tid[1],NULL);//wait for the adjoint thread to exit


		printf("\nDeterminant %d\nAdj:\n",det);


		for(i=0;i<N;i++)
		{	
			for(j=0;j<N;j++)
			{
				printf("%d ",adj[i][j]);
			}
			printf("\n");
		}


		for (i=0;i<N;i++) 
    	{
    		for (j=0;j<N;j++) 
    		{
    			inverse[i][j] = adj[i][j]/(float)(det); 
    		}
    	}

    	printf("\nInverse:\n");
    	for(i=0;i<N;i++)
		{	
			for(j=0;j<N;j++)
			{
				printf("%f ",inverse[i][j]);
			}
			printf("\n");
		}
	}
		return(0);
}

void *determinant(void *param[])
{
	 det=0; 
	 int i;
	 int temp[N][N]; 
     int sign=1;  
    if (N==1) 
        printf("\nOnly one element"); 
  
    
    for(i=0;i<N;i++) 
    { 
        
        getCofactor(m,temp,0,i,N); 
        det+ = sign * m[0][i] * determinantOfMatrix(temp,N-1); 
  
        
        sign=-sign; 
       
    } 
    pthread_exit(NULL);
  
}
void *adjoint(void *param[]) 
{ 
    if (N == 1) 
    { 
        adj[0][0] = 1; 
        return; 
    } 
  
    // temp is used to store cofactors 
    int sign=1,temp[N][N]; 
  	int i,j;
    for (i=0;i<N;i++) 
    { 
        for (j=0;j<N;j++) 
        { 
            
            getCofactor(m,temp,i,j,N); 
            // sign of adj[j][i] positive if sum of row and column is even. 
            if((i+j)%2==0)
	            sign=1;
	        else
	        	sign=-1;  
           
            adj[j][i] = (sign)*(determinantOfMatrix(temp, N-1)); 
        } 
    } 
    pthread_exit(NULL);
} 
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) 
{ 
    int i=0,j=0; 
    int row,col;
  
    //for each element in the matrix 
    for (row=0;row<n;row++) 
    { 
        for (col=0;col<n;col++) 
        { 
           
            if (row!=p&&col!=q) 
            { 
                temp[i][j++] = mat[row][col]; 
                 
                if (j==n-1) 
                { 
                    j=0; 
                    i++; 
                } 
            } 
        } 
    } 
}
int determinantOfMatrix(int mat[N][N], int n) 
{ 
    int D = 0; // Initialize result   
    //If matrix contains single element 
    if (n == 1) 
        return mat[0][0]; 
  
    int temp[N][N]; // To store cofactors 
  	int f;
    int sign = 1;  // To store sign multiplier 
  
    
    for (f=0;f<n;f++) 
    { 
        // Getting Cofactor of mat[0][f] 
        getCofactor(mat,temp,0,f,n); 
        D+=sign * mat[0][f] * determinantOfMatrix(temp, n - 1); 
        // terms are to be added with alternate sign 
        sign=-sign; 
    } 
  
    return D; 
} 

	
