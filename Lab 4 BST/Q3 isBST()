#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

BTNode* insertBSTNode(BTNode* cur, int item);
BTNode* insertBTNode(BTNode* cur, int item);

void printBTNode(BTNode *root, int space,int left);
void deleteTree(BTNode **root);

int isBST(BTNode *root);

int main()
{
    BTNode* rootBST=NULL;
    BTNode* rootBT=NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item)){
        rootBST = insertBSTNode(rootBST, item);
        rootBT = insertBTNode(rootBT,item);
    }
    scanf("%*s");

    printf("The binary tree is %s:\n",isBST(rootBST)?"a BST": "not a BST");
    printBTNode(rootBST,0,0);
    printf("The binary tree is %s:\n",isBST(rootBT)?"a BST": "not a BST");
    printBTNode(rootBT,0,0);

    deleteTree(&rootBST);
    rootBST=NULL;
    deleteTree(&rootBT);
    rootBT=NULL;

    return 0;
}

BTNode* insertBTNode(BTNode* cur, int item){
    if (cur == NULL){
        BTNode* node = (BTNode*) malloc(sizeof(BTNode));
        node->item = item;
        node->left = node->right = NULL;
        return node;
	}
    if (rand()%2)
        cur->left  = insertBTNode (cur->left, item);
    else
        cur->right = insertBTNode (cur->right, item);

    return cur;
}

BTNode* insertBSTNode(BTNode* cur, int item){
    if (cur == NULL){
        BTNode* node = (BTNode*) malloc(sizeof(BTNode));
    	node->item = item;
    	node->left = node->right = NULL;
    	return node;
	}
    if (item < cur->item)
        cur->left  = insertBSTNode (cur->left, item);
    else if (item > cur->item)
        cur->right = insertBSTNode (cur->right, item);
    else
        printf("Duplicated Item: %d\n",item);

    return cur;
}

void printBTNode(BTNode *root,int space,int left){
      if (root != NULL)
      {

          int i;
          for (i = 0; i < space-1; i++)
                 printf("|\t");


          if(i<space){
            if(left==1)
              printf("|---");
            else
              printf("|___");
          }

          printf("%d\n", root->item);

          space++;
          printBTNode(root->left, space,1);
          printBTNode(root->right, space,0);
      }
}


void deleteTree(BTNode **root){
    if (*root != NULL)
	{
		deleteTree(&((*root)->left));
		deleteTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

int min(BTNode *root){
    int l, r;
    l = r = root->item;
    if (root->left != NULL){
        l = min(root->left);
    }
    if (root->right != NULL){
        r = min(root->right);
    }
    if(l < root->item && l < r){
        return l;
    }
    else if (r<root->item && r<l){
        return r;
    }
    else{
        return root->item;
    }
}

int max(BTNode *root){
    int l, r;
    l = root->item;
    r = root->item;
    if (root->left == NULL && root->right == NULL){
        return root->item;
    }
    if (root->left != NULL){
        l = max(root->left);
    }
    if (root->right != NULL){
        r = max(root->right);
    }
    if(l > root->item && l > r){
        return l;
    }
    else if (r>root->item && r>l){
        return r;
    }
    else{
        return root->item;
    }
}

int isBST(BTNode *root){
    if (root == NULL){
        return 1;
    }
    else if (root->left != NULL && max(root->left) > root->item){
        return 0;
    }
    else if (root->right != NULL && min(root->right) < root->item){
        return 0;
    }
    else if (root->right == NULL && root->left == NULL){
        return 1;
    }
    else{
        if(isBST(root->left) == 0){
            return 0;
        }
        else if (isBST(root->right) == 0){
            return 0;
        }
        else{
            return 1;
        }
    }
}


