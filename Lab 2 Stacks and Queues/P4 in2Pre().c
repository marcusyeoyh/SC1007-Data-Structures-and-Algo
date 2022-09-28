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

void in2Pre(char*, char*);

int main()
{
    char infix[SIZE];
    char prefix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    in2Pre(infix,prefix);
    printf("The prefix expression is \n");
    printf("%s\n",prefix);

    return 0;
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
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

int isOperand(char infix){
    if(infix>='a' && infix<= 'z'){
        return 1;
    }
    else if (infix>='A' && infix>= 'Z'){
        return 1;
    }
    else if (infix>='0' && infix<= '9'){
        return 1;
    }
    else{
        return 0;
    }
}

void in2Pre(char* infix, char* prefix)
{
Stack *newStack;  
newStack->size = 0;  
newStack->head = NULL;  
char postfix[SIZE] = ""; 
postfix[0] = 0; 
prefix[0] = 0; 
char var1, var2, var3; 
 
for (int i = strlen(infix); i>=0 ;i--){  
    Stack newstack; 
    newstack.head = NULL; 
    newstack.size = 0; 
 
    int length = strlen(infix); 
 
    int i,j; 
 
    int prefixindex = 0; 
 
    for(j=length-1;j>=0;j--){ 
 
        char character = infix[j]; 
 
        if((character >= '0' && character <= '9') || (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')){ 
 
 
            prefix[prefixindex++] = character; 
 
 
        } 
 
        if(character == ')') push(&newstack,character); 
 
 
        if(character == '*' || character == '/') push(&newstack,character); 
 
        if(character == '('){ 
 
            while(!isEmptyStack(newstack) && peek(newstack) != ')'){ 
 
                prefix[prefixindex++] = peek(newstack); 
 
                pop(&newstack); 
 
 
            } 
 
 
            pop(&newstack); 
           } 
 
        if(character == '+' || character == '-'){ 
 
            while(!isEmptyStack(newstack) && peek(newstack) != ')' && (peek(newstack) == '*' || peek(newstack) == '/' )){ 
 
                prefix[prefixindex++] = peek(newstack); 
 
                pop(&newstack); 
 
 
 
            } 
 
            push(&newstack,character); 
 
        } 
 
    } 
 
    while(!isEmptyStack(newstack)){ 
 
 
        prefix[prefixindex++] = peek(newstack); 
 
        pop(&newstack); 
 
 
    } 
 
    prefix[prefixindex] = '\0'; 
 
 
    int length2 = strlen(prefix); 
 
    char temparray[SIZE]; 
 
    int k; 
    int temparrayindex = 0; 
 
 
    for(k=length2-1;k>=0;k--){ 
 
 
        temparray[temparrayindex++] = prefix[k]; 
 
 
    } 
    temparray[temparrayindex] = '\0';
 
 
 
    strcpy(prefix,temparray); 
 

}
