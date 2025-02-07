#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
using namespace std;

typedef struct node* treePointer;
typedef struct node{
    string word;
    treePointer leftChild, rightChild;
}node;

// declare function
treePointer create_BST();
int isEmpty(treePointer node);
void  insertNode(string word);
int deleteNode(string word);
void inorderTraversal(treePointer root);
treePointer search(string word);

// create a Binary Search Tree and count Nth
treePointer root = (treePointer) malloc(sizeof(struct node));
int countNth = 0;

int main(void){
    root = create_BST();
    string searchFileName;  // txt file name to read
    int mode;  // input int and choose mode
    string temp;
    string word;
    treePointer nth;  // store nth result


    // build dictionary BST
    ifstream file("test.txt");
    while(file >> temp){
        insertNode(temp);
    }
    file.close();

    cout << root->word << endl;
    // read file name
    // cout << "Put the file under this search file folder:" << endl;
    // cout << "[Enter the name of the file to read(not need to .txt)] > ";
    // cin >> searchFileName;
    // cout << endl;
    // searchFileName += ".txt";
    
    // interface
    while(1){
        int mode;
        // choose mode
        cout << "\n" << endl;
        cout << "<mode>" << endl;
        cout << "1. Add a new key value" << endl;
        cout << "2. Delete a key value" << endl;
        cout << "3. Find a key value" << endl;
        cout << "4. Output the sorting results of key values (from small to large)" << endl;
        cout << "5. End program" << endl;
        cout << "[Select the mode to use] " << endl;
        cin >> mode;

        switch(mode){
            case 1:       // Add a new key value
                cout << "[Enter the new key value] > ";
                cin >> word;
                cout << endl;
                insertNode(word);
                break;
            case 2:      // Delete a key value
                cout << "[Enter the delete key value] > ";
                cin >> word;
                cout << endl;
                deleteNode(word);
                break;
            case 3:      // Find a key value
                cout << "[Enter the key value you are looking for] > ";
                cin >> word;
                cout << endl;
                search(word);
                break;
            case 4:
                cout << "\nKey values are sorted from small to large:" << endl;
                inorderTraversal(root);
                break;
            default:     // End program
                cout << "End" << endl;
                exit(0);
        }
        cout << "\n\n[Enter to continue..]";
        getchar();
        getchar();
        cout << endl;
        cout << "----------------------------" << endl;
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
void insertNode(string word){
    treePointer temp, newNode;
    temp = (treePointer) malloc(sizeof(struct node));
    newNode = (treePointer) malloc(sizeof(struct node));
    // create a new node
    newNode->word = word;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    if(isEmpty(root)){root = newNode;}
    else{
        temp = root;
        while(temp != newNode){
            if(word > temp->word){
                if(temp->rightChild == NULL) temp->rightChild = newNode;
                temp = temp->rightChild;
            }
            else if(word < temp->word){
                if(temp->leftChild == NULL) temp->leftChild = newNode;
                temp = temp->leftChild;
            }
            else{
                cout << "Error: Unable to add key, value already exists";
                return;
            }
        }
    }
    free(newNode);
    free(temp);
    cout << "Added key value " << word << endl;
}

// delete node in binary search tree
int deleteNode(string word){
    treePointer node = root, switchNode = NULL, beforeSwitch = NULL, beforeNode = NULL;
    int right = 0;
    
    // search node and store parent node
    while(node){
        if (node->word == word) {break;}
        beforeNode = node;
        if(word > node->word) {right = 1; node = node->rightChild;}
        else {right = 0;node = node->leftChild;}
    }
    if(!node) {cout << "key value " << word << " not found"; return 0;}

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
    cout << "key value " << word << " deleted" << endl;
    // printf("inorder traversal: ");
    // inorderTraversal(root);
    return 1;
}

// inorder traversal binary search tree
void inorderTraversal(treePointer node){
    if(!root){cout << "NULL tree"; return;}
    if(node){
        inorderTraversal(node->leftChild);
        cout << node->word << " ";
        inorderTraversal(node->rightChild);
    }
}

treePointer search(string word){
    treePointer temp = root;
    while(temp){
        if (temp->word == word) {
            cout << "The key value has been found" << endl;
            // inorderTraversal(root);
            return temp;
        }
        else if(word > temp->word) temp = temp->rightChild;
        else temp = temp->leftChild;
    }
    cout << "key value " << word << " not found" << endl;
    return NULL;
}