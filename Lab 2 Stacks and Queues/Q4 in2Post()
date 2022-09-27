#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

void in2Post(char*, char*);

int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    in2Post(infix,postfix);
    printf("The postfix expression is \n");
    printf("%s\n",postfix);
    return 0;
}

void push(Stack *sPtr, char item){
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

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

int pres(char infix){ 
    if (infix == '*' || infix == '/'){ 
        return 1; 
    } 
    else if (infix == '+' || infix =='-'){ 
        return 0; 
    } 
    else{
        return 0;
    }
}

void in2Post(char* infix, char* postfix)
{
Stack *newStack; 
newStack->size = 0; 
newStack->head = NULL; 

postfix[0] = 0;

for (int i = 0; i<strlen(infix);i++){ 
    if ((infix[i]>='a' && infix[i]<= 'z') || (infix[i]>='A' && infix[i]<= 'Z') || (infix[i]>='0' && infix[i]<= '9')){ 
        strncat(postfix, &infix[i], 1); 
    } 
    else if(infix[i] == ')'){ 
        while (peek(*newStack)!='('){ 
            char var1 = peek(*newStack); 
            strncat(postfix, &var1, 1); 
            pop(newStack); 
        } 
        pop(newStack); 
    } 
    else if (infix[i] == '('){ 
        push(newStack, infix[i]); 
    } 
    else{ 
        while (isEmptyStack(*newStack) == 0 && peek(*newStack)!='(' && pres(peek(*newStack))>=pres(infix[i])){ 
            char var2 = peek(*newStack); 
            strncat(postfix, &var2, 1); 
            pop(newStack); 
        } 
        push(newStack, infix[i]); 
    } 
} 
while (isEmptyStack(*newStack) == 0){ 
    char var3 = peek(*newStack); 
    strncat(postfix, &var3, 1); 
    pop(newStack); 
} 
}
