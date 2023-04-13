#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define Linked List Binary Search Tree
typedef struct node* treePointer;
typedef struct node{
    int data;
    treePointer leftChild, rightChild;
}node;

// declare function
treePointer create_BST();
int isEmpty(treePointer node);
void  insertNode(int key);
int deleteNode(int key);
void inorderTraversal(treePointer root);
treePointer search(int key);
treePointer NthKey(treePointer node, int N);

// create a Binary Search Tree and count Nth
treePointer root = create_BST();
int countNth = 0;

int main(void){
    FILE *fp;  // read txt file
    char fileName[60];  // txt file name to read
    int input, mode;  // input int and choose mode
    treePointer nth;  // store nth result

    // read file name
    printf("Put the file under this original file folder:\n");
    printf("[Enter the name of the file to read(not need to .txt)] > ");
    scanf("%s", fileName);
    printf("\n");
    strcat(fileName, ".txt");
    
    // open file
    fp = fopen(fileName, "r");
    while(fscanf(fp, "%d", &input) != -1){
        insertNode(input);
        printf("\n\n");
    }
    fclose(fp);

    // interface
    while(1){
        int mode;
        // choose mode
        printf("\n");
        printf("<mode>\n");
        printf("1. Add a new key value\n");
        printf("2. Delete a key value\n");
        printf("3. Find a key value\n");
        printf("4. Find the Nth smallest key value\n");
        printf("5. Output the sorting results of key values (from small to large)\n");
        printf("6. End program\n");
        printf("\n[Select the mode to use] > ");
        scanf("%d", &mode);

        switch(mode){
            case 1:       // Add a new key value
                printf("[Enter the new key value] > ");
                scanf("%d", &input);
                printf("\n");
                insertNode(input);
                break;
            case 2:      // Delete a key value
                printf("[Enter the delete key value] > ");
                scanf("%d", &input);
                printf("\n");
                deleteNode(input);
                break;
            case 3:      // Find a key value
                printf("[Enter the key value you are looking for] > ");
                scanf("%d", &input);
                printf("\n");
                search(input);
                break;
            case 4:      // Find the Nth smallest key value
                printf("[Enter the nth] > ");
                scanf("%d", &input);
                printf("\n");
                countNth = 0;
                nth = NthKey(root, input);
                if(nth){
                    printf("key value: %d\n", nth->data);
                    inorderTraversal(root);
                }
                else{printf("Nth key value not found\n");}
                break;
            case 5:      // Output the sorting results of key values
                printf("\nKey values are sorted from small to large:\n");
                inorderTraversal(root);
                break;
            default:     // End program
                printf("End\n");
                exit(0);
        }
        printf("\n\n[Enter to continue...]");
        getchar();
        getchar();
        printf("\n----------------------------\n");
    }
}

//return a empty BST
treePointer create_BST(){
    treePointer temp;
    temp = NULL;
    return temp;
}

//return BST is empty
int isEmpty(treePointer node){
    if(node == NULL)
        return 1;
    return 0;
}

// insert node in binary search tree
void insertNode(int key){
    treePointer temp, newNode;
    // create a new node
    newNode = (treePointer) malloc(sizeof(struct node));
    newNode->data = key;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    if(isEmpty(root)){root = newNode;}
    else{
        temp = root;
        while(temp != newNode){
            if(key > temp->data){
                if(temp->rightChild == NULL) temp->rightChild = newNode;
                temp = temp->rightChild;
            }
            else if(key < temp->data){
                if(temp->leftChild == NULL) temp->leftChild = newNode;
                temp = temp->leftChild;
            }
            else{
                printf("Error: Unable to add key, value already exists");
                return;
            }
        }
    }
    printf("Added key value %d\n", key);
    printf("inorder Traversal: ");
    inorderTraversal(root);
}

// delete node in binary search tree
int deleteNode(int key){
    treePointer node = root, switchNode = NULL, beforeSwitch = NULL, beforeNode = NULL;
    int right = 0;
    
    // search node and store parent node
    while(node){
        if (node->data == key) {break;}
        beforeNode = node;
        if(key > node->data) {right = 1; node = node->rightChild;}
        else {right = 0;node = node->leftChild;}
    }
    if(!node) {printf("key value %d not found", key); return 0;}

    // case 1: node has no children
    if(!node->leftChild && !node->rightChild){
        if(!beforeNode){root = NULL;}
        else if(right){beforeNode->rightChild = NULL;}
        else{beforeNode->leftChild = NULL;}
    }
    // case 2: node has only right children 
    else if(!node->leftChild){
        if(!beforeNode){root = node->rightChild;}
        else if(right){beforeNode->rightChild = node->rightChild;}
        else{beforeNode->leftChild = node->rightChild;}
    }
    // case 3: node has only left children 
    else if(!node->rightChild){
        if(!beforeNode){root = node->leftChild;}
        else if(right){beforeNode->rightChild = node->leftChild;}
        else{beforeNode->leftChild = node->leftChild;}
    }
    // case 4: node has left children and right children
    else{
        // find the largest node of left subtree to replace the node to be delete
        switchNode = node->leftChild;
        while(switchNode->rightChild){
            beforeSwitch = switchNode;
            switchNode = switchNode->rightChild;
        }
        // replace node
        if(switchNode == node->leftChild){
            if(!beforeNode){root = switchNode;}
            else if(right){beforeNode->rightChild = switchNode;}
            else{beforeNode->leftChild = switchNode;}  
            switchNode->rightChild = node->rightChild;
        }
        else{
            if(!beforeNode){root = switchNode;}
            if(switchNode->leftChild){beforeSwitch->rightChild = switchNode->leftChild;}
            else{beforeSwitch->rightChild = NULL;}
            switchNode->leftChild = node->leftChild;
            switchNode->rightChild = node->rightChild;
        }
    }

    free(node);
    printf("key value %d deleted\n", key);
    printf("inorder traversal: ");
    inorderTraversal(root);
    return 1;
}

// inorder traversal binary search tree
void inorderTraversal(treePointer node){
    if(!root){printf("NULL tree"); return;}
    if(node){
        inorderTraversal(node->leftChild);
        printf("%d ", node->data);
        inorderTraversal(node->rightChild);
    }
}

// search binary search tree
treePointer search(int key){
    treePointer temp = root;
    while(temp){
        if (temp->data == key) {
            printf("The key value has been found\n");
            inorderTraversal(root);
            return temp;
        }
        else if(key > temp->data) temp = temp->rightChild;
        else temp = temp->leftChild;
    }
    printf("key value %d not found", key);
    return NULL;
}

// find the nth smallest value
treePointer NthKey(treePointer node, int N){
    if(node){
        treePointer left = NthKey(node->leftChild, N);
        if(countNth == N){return left;}
        countNth++;
        if(countNth == N){return node;}
        left = NthKey(node->rightChild, N);
        if(left){return left;}
    }
    return NULL;
}
