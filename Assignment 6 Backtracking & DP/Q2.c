#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if(a>b) return a;
    if(b>a) return b;
    if(a==b) return a;
}

int bottom_up_dp(int n, int *s, int *v, int C)
{
    //write your code here
    int **memory;
    memory = (int**) malloc(sizeof(int*)*(n+1));
    for(int i = 0; i<(n+1); i++){
        memory[i] = (int*) malloc(sizeof(int)*(C+1));
    }
    for (int i = 0; i<(n+1); i++){
        for (int j = 0; j<(C+1); j++){
            memory[i][j]=0;
        }
    }

    for (int i = 1; i<=C; i++){
        if(i>=s[1]){
            memory[1][i]=v[1];
        }
        else{
            memory[1][i]=0;
        }
    }


    for(int i = 2; i<=n; i++){
        for (int j = 1; j<=C; j++){
            if((j-s[i])>=0){
                memory[i][j]=max(memory[i-1][j], (memory[i-1][j-s[i]] + v[i]));
            }
            else{
                memory[i][j]=memory[i-1][j];
            }
        }
    }


    int q = -1;
    for(int i = 0; i<=n; i++){
        for (int j = 0; j<=C; j++){
            q = max(q, memory[i][j]);
        }
    }
    return memory[n][C];
}

 
int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));
    
    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);
        
    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    
    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));
        
}