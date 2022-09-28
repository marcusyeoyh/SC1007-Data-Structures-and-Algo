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
    else if (infix>='A' && infix<= 'Z'){
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
    Stack s; 
    s.head = NULL; 
    s.size = 0; 

    char temp[SIZE] = "";
    int tempindex = 0;
    int length = strlen(infix);
 
    for (int i = length-1; i>=0; i--){
        //temp[tempindex++] = infix[i];
        if ((infix[i]>='0' && infix[i]<='9') || (infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z')){
            temp[tempindex++] = infix[i];
        }
        else if (infix[i]==')'){
            push(&s, infix[i]);
        }
        else if (infix[i] == '('){
            while(peek(s)!=')'){
                temp[tempindex++] = peek(s);
                pop(&s);
            }
            pop(&s);
        }
        else{
            while(isEmptyStack(s)==0 && peek(s) != ')' && pres(peek(s))>pres(infix[i])){
                temp[tempindex++] = peek(s);
                pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    while(isEmptyStack(s)==0){
        temp[tempindex++] = peek(s);
        pop(&s);
    }
    //strcpy(prefix, temp);
    
    int length2 = strlen(temp);
    int prefixindex = 0;
    for(int j = length2-1; j>=0;j--){
        prefix[prefixindex++]=temp[j];
    }
    prefix[prefixindex]='\0';
}
