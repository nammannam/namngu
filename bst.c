#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int data_t;

typedef struct BNode_s{
    data_t inf;
    struct BNode_s * Left;
    struct BNode_s * Right;

}BNode;

BNode *makeNode(data_t x){
    BNode *newNode = (BNode *)malloc(sizeof(BNode));
    
    newNode->inf = x;
    newNode->Left = NULL;
    newNode->Right = NULL;

    return newNode;
}

void insert(BNode **root, data_t x){
    if((*root)== NULL){
        *root = makeNode(x);
    }

    if(x < (*root)->inf)
        insert(&((*root)->Left), x);

    if( x > (*root)->inf){
        insert(&((*root)->Right), x);
    }

}

void preOrder(BNode *root){
    if(root == NULL)
        return;

    printf("%d ",root->inf );
    preOrder(root->Left);
    preOrder(root->Right);
}

void postOrder(BNode *root){
     if(root == NULL)
        return;

    postOrder(root->Left);
    postOrder(root->Right);
    printf("%d ",root->inf );

}

BNode * find(BNode *root, data_t x){
   if(root == NULL)
        return NULL;
    if(root->inf == x)
        return root;
    
    BNode *res=find(root->Left ,x);
    if(res !=NULL)
        return res;

    return find(root->Right, x);
}


int main(){
    BNode * root = NULL;
    char cmd[50];
    int key;

    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0){
            break;
        }else if(strcmp(cmd, "insert") == 0){
            scanf("%d", &key);
            insert(&root, key);
        }else if(strcmp(cmd, "preorder") == 0){
            preOrder(root);
            printf("\n");
        }else if(strcmp(cmd, "postorder") == 0){
            postOrder(root);
            printf("\n");
        }else if(strcmp(cmd, "find") == 0){
            scanf("%d",&key);
            BNode *found = find(root, key);
            if(found != NULL)
            printf("%d\n", found->inf);
            else
            printf("not found\n");
        }
        

    }




    // insert(&root, 1);
    // insert(&root, 3);
    // insert(&root, 2);
    // insert(&root, 5);
    // preOrder(root);


    return 0;
}