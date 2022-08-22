#include<pthread.h>
#include<stdio.h>  
int N; 

void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n) 
{ 
    int i = 0, j = 0,row,col = 0; 
    for(row = 0; row < n; row++) 
    { 
        for (col = 0; col < n; col++) 
        { 
            if (row != p && col != q) 
            { 
                temp[i][j++] = A[row][col]; 
 
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
  
 
void determinant(int A[N][N], int n) 
{ 
    int D = 0; 
    if (N == 1) 
        return A[0][0]; 
  
    int temp[N][N];  
  
    int sign = 1,f;    
    for (f = 0; f < n; f++) 
    { 
        getCofactor(A, temp, 0, f, n); 
        D += sign * A[0][f] * determinant(temp, n - 1); 
  
        sign = -sign; 
    } 
  
    pthread_exit(0) ;
} 
  
 
void adjoint(int A[N][N],int adj[N][N]) 
{ 
    if (N == 1) 
    { 
        adj[0][0] = 1; 
        return; 
    } 
  
    int sign = 1, temp[N][N]; 
  int i,j;
    for (i=0; i<N; i++) 
    { 
        for (j=0; j<N; j++) 
        {  
            getCofactor(A, temp, i, j, N); 
            sign = ((i+j)%2==0)? 1: -1; 

            adj[j][i] = (sign)*(determinant(temp, N-1)); 
        } 
    } 
} 
  

int inverse(int A[N][N], float inverse[N][N]) 
{ 
	pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int det=0;/* = determinant(A, N);*/
    pthread_create(&tid,&attr,determinant,&det);
    pthread_join(tid,NULL);
    if (det == 0) 
    { 
        printf("Singular matrix, can't find its inverse"); 
        return 0; 
    } 
  
    int adj[N][N]; 
    adjoint(A, adj); 
  int i,j;
    for (i=0; i<N; i++) 
        for (j=0; j<N; j++) 
            inverse[i][j] = (float)adj[i][j]/(det); 
  
    return 1; 
} 

void display(int A[N][N]) 
{ int i,j=0;
    for(i=0; i<N; i++) 
    { 
        for (j=0; j<N; j++) 
		printf("%d ",A[i][j]);
        printf("\n"); 
    } 
} 
void displayf(float A[N][N]) 
{ int i,j;
    for (i=0; i<N; i++) 
    { 
        for (j=0; j<N; j++) 
		printf("%f ",A[i][j]);
        printf("\n"); 
    } 
} 
  
 
int main() 
{ 
  	printf("\n Enter the size of the matrix: ");
	scanf("%d",&N);
	int A[N][N];
	printf("\n ENter the matrix: \n");
int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",&A[i][j]);
    int adj[N][N];  
  
    float inv[N][N]; 
  
    printf( "Input matrix is :\n"); 
    display(A); 
  
    printf("\nThe Adjoint is :\n"); 
    adjoint(A, adj); 
    display(adj); 
  
    printf("\nThe Inverse is :\n"); 
    if (inverse(A, inv)==1) 
        displayf(inv); 
  
    return 0; 
} 







