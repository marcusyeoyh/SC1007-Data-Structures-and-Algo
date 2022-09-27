#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    double item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char*);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    scanf("%[^\n]%*c",postfix);

    printf("The answer is %.2lf.\n",exePostfix(postfix));

    return 0;
}

void push(Stack *sPtr, double item){
    StackNode *newNode;
    newNode = (StackNode *) malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

double peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

double exePostfix(char* postfix)
{
 Stack newStack;
 newStack.size = 0;
 newStack.head = NULL;
 
 for (int i = 0; i < strlen(postfix); i++){
    if (postfix[i]>='0' && postfix[i]<='9'){
        double var1 = (double) postfix[i] - '0';
        push(&newStack, var1);
    }
    else if (postfix[i] == '+'){
        double var2 = peek(newStack);
        pop(&newStack);
        double var3 = peek(newStack);
        pop(&newStack);
        double var4 = (var3 + var2);
        push(&newStack, var4);
    }
    else if (postfix[i] == '-'){
        double var5 = peek(newStack);
        pop(&newStack);
        double var6 = peek(newStack);
        pop(&newStack);
        double var7 = (var6 - var5);
        push(&newStack, var7);
    }
    else if (postfix[i] == '*'){
        double var8 = peek(newStack);
        pop(&newStack);
        double var9 = peek(newStack);
        pop(&newStack);
        double var10 = (var9 * var8);
        push(&newStack, var10);
    }
    else if (postfix[i] == '/'){
        double var11 = peek(newStack);
        pop(&newStack);
        double var12 = peek(newStack);
        pop(&newStack);
        double var13 = (var12 / var11);
        push(&newStack, var13);
    }
 }
 double answer = peek(newStack);
 return answer;
}
