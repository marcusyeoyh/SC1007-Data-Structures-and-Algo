#include <stdio.h>
#include <stdlib.h>

#define MAX_N 120

typedef struct _btnode{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode** node, char* preO, char* postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s",preO);
    scanf("%s",postO);

    BTNode* root=NULL;
    buildTree(&root,preO,postO);
    if(root==NULL) printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur){
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c",cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur){
    if (cur == NULL)
        return;

    printf("%c",cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur){
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c",cur->id);
}
#include <string.h>

void buildTree(BTNode** node, char* preO, char* postO)
{
int leftnum, rightnum;
char LPre[MAX_N] = "", LPost[MAX_N] = "", RPre[MAX_N] = "", RPost[MAX_N] = "";
BTNode* tempnode = *node;

if (strlen(preO) == 0 || strlen(postO) == 0){
    return;
}

else if (preO[0] == postO[strlen(postO)-1]){
    BTNode *newNode;
    newNode = (BTNode*) malloc(sizeof(BTNode));
    newNode->id = preO[0];
    newNode->left = NULL;
    newNode->right = NULL;
    *node = newNode;
    if (strlen(preO) == 1 || strlen(postO) == 1){
        return;
    }
    preO = preO + 1;
    postO[strlen(postO)-1] = '\0';
}

if (preO[0] == postO[strlen(postO)-1]){
    buildTree(&(*node)->left, preO, postO);
}

if ((*node)->left == NULL && (*node)->right == NULL){
    for (int i = 0; i<strlen(preO); i++){
        if (preO[i] == postO[strlen(postO)-1]){
            leftnum = i;
        }
    }
    for (int i = 0; i<strlen(postO); i++){
        if (postO[i] == preO[0]){
            rightnum = i;
        }
    }
    //printf("%d\n", leftnum);
    //printf("%d\n", rightnum);
    for (int i =0; i<leftnum; i++){
        strncat(LPre, &preO[i], 1);
    }
    for (int i = leftnum; i<strlen(preO); i++){
        strncat(RPre, &preO[i], 1);
    }
    for (int i =0; i<rightnum+1; i++){
        strncat(LPost, &postO[i], 1);
    }
    for (int i = rightnum+1; i<strlen(postO); i++){
        strncat(RPost, &postO[i], 1);
    }
    //printf("%s\n", LPre);
    //printf("%s\n", RPre);
    //printf("%s\n", LPost);
    //printf("%s\n", RPost);
    buildTree(&(*node)->left, LPre, LPost);
    buildTree(&(*node)->right, RPre, RPost);

}
}
