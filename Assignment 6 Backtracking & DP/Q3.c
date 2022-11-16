#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int *memory;
int top_down_dp(int n)
{
    // write your code here

    memory[0] = 0;
    memory[1] = 1;
    memory[2] = 2;

    if (memory[n] != -1)
    {
        return memory[n];
    }

    if (memory[n - 1] == -1)
    {
        top_down_dp(n - 1);
    }
    if (memory[n - 2] == -1)
    {
        top_down_dp(n - 2);
    }
    if (memory[n - 3] == -1)
    {
        top_down_dp(n - 3);
    }
    memory[n] = memory[n - 1] + 2 * (memory[n - 2]) - 3 * (memory[n - 3]);
    return memory[n];
}

int main()
{
    int n;
    int function;
    int i;
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    
    memory = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        memory[i] = -1;
    }

    printf("The value of F(%d) is: %d \n", n, top_down_dp(n));
}