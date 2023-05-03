#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int element;

typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
}TreeNode;

typedef struct {
    TreeNode* Stack[N];
    int top;
}StackType;

typedef struct{
    TreeNode* Queue[N];
    int front, rear;
}QueueType;

void initQueue(QueueType *Q){
    Q->front = Q->rear = 0;
}

int isEmpty(QueueType *Q){
    return Q->front == (Q->rear + 1) %N;
}

// 더 ㅓㄶ어
void enqueue(QueueType* Q, TreeNode *e){
    Q->rear = (Q->rear +1) % N;
    Q->data[Q->rear] = e;

}

TreeNode* dequeue(QueueType *Q){
    Q->front = (Q->front + 1) % N;
    return Q->Queue[Q->front];
}

// 레벨오더도 추가해야함
void levelOrder(TreeNode *root){
    QueueType Q;
    initQueue(&Q);

    enqueue(&Q, root);
    while(!isEmpty(&Q)){
        root = dequeue(&Q);
        printf("[%d]", root->key);

        if (root->left != NULL)
            enqueue(&Q, root->left);
    }
}


void initStack(StackType *S){
    S->top = -1;
}

void push(StackType *S, TreeNode* e){
    // 꽉차지 않는다면
    if(S->top < N-1){
        S->Stack[++S->top] = e;
    }
}

TreeNode* pop(StackType *S){
    TreeNode *e = NULL;
    // 비어있지 않다면
    if(S->top >= 0){
        e = S->Stack[S->top--];
    }
    return e;
}

void iterOrder(TreeNode *root){
    StackType S;
    initStack(&S);

    while(1){
        for(; root != NULL; root = root->left){
            push(&S, root);
        }
        root = pop(&S);

        if (root == NULL)
            break;

        printf("[%d]",root->key);

        root = root->right;


    }
}

TreeNode* makeNode(element key){
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insertNode(TreeNode* root, element key){
    if (root == NULL)
        return makeNode(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;

}


void preOrder(TreeNode *root){
    if(root != NULL){
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root){
    if(root != NULL){
        inOrder(root->left);
        printf("[%d] ", root->key);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ", root->key);
    }
}




int main(){
    TreeNode *root = NULL;
    root = insertNode(root, 35);
    root = insertNode(root, 68);
    root = insertNode(root, 99);
    root = insertNode(root, 35);
    root = insertNode(root, 35);
    root = insertNode(root, 68);


//    printf("pre  : "); preOrder(N1); printf("\n");
//    printf("in   : "); inOrder(N1); printf("\n");
//    printf("post : "); postOrder(N1); printf("\n");

    iterOrder((N1));
}













