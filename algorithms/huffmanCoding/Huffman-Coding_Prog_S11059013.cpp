#include<iostream>
#include<string>
#include<fstream>
#include<limits>
#include<vector>
#include<queue>
#include<bitset>
#include <ctime>
using namespace std;

struct PGMImage{
    int width;
    int high;
    int maxPixelValue = 255;
    int FreqPixelValue[256] = {0};
    string table[256] = {""};
    vector<int> pixels;
};

typedef struct huffmanNode* nodePointer;
struct huffmanNode{
    int pixel;
    int freq;
    nodePointer left;
    nodePointer right;
};

class cmp{
public:
    bool operator()(nodePointer a, nodePointer b){
        return a->freq > b->freq;
    }
};

void swap(char *x, char *y);
void reverse(char *first, char *last);
PGMImage readPGMFile(string fileName);
PGMImage readHCFile(string fileName);
void writeHCFile(string fileName, PGMImage image, nodePointer root);
void writePGMFile(string fileName, PGMImage image);
nodePointer createNode(int pixel, int freq);
void inorderTraversal(nodePointer node, string s, string* table);
void preorderTraversalWriteFile(ofstream &HCFile, nodePointer node);
void rebuildHuffmanTree(ifstream &HCFile, nodePointer node);
nodePointer buildHuffmanTree(int freq[]);
nodePointer decode(string s, nodePointer node);
double fileSize(string fileName);

int main(int argc, char* argv[]){
    PGMImage image;
    nodePointer root;
    string p, PGMFileName, HCFileName;

    
    p = (string) argv[1];
    if(p == "-c"){
        PGMFileName = (string) argv[2];
        PGMFileName.erase(PGMFileName.size()-4, 4);

        image = readPGMFile(PGMFileName + ".pgm");
        root = buildHuffmanTree(image.FreqPixelValue);
        inorderTraversal(root, "", image.table);
        writeHCFile(PGMFileName + ".hc", image, root);
       
        cout << endl;
        cout << "original image size: " << fileSize(PGMFileName + ".pgm") << " KB" << endl;
        cout << "compressed image size: " << fileSize(PGMFileName + ".hc") << " KB" << endl;
        cout << endl << "Compression completed." << endl;
    }
    else if(p == "-d"){
        HCFileName = (string) argv[2];
        PGMFileName = (string) argv[3];
        image = readHCFile(HCFileName);
        writePGMFile(PGMFileName, image);
        cout << "Deompression completed." << endl;
    }

    cout << (double)clock() / CLOCKS_PER_SEC << " S";
    return 0;
}

void swap(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void reverse(char *first, char *last) {
    --last;
    while (first < last) {
        swap(first, last);
        ++first;
        --last;
    }
}

PGMImage readPGMFile(string fileName){
    PGMImage image;
    ifstream PGMFile(fileName, ios::in);
    if(!PGMFile.is_open()){ cout << "File cannot be opened." << endl; }

    char P[100];
    PGMFile.getline(P, 30);
    PGMFile.getline(P, 30);
    PGMFile >> image.width >> image.high;
    PGMFile >> image.maxPixelValue;

    int pixel;
    while(PGMFile >> pixel){
        image.pixels.push_back(pixel);
        image.FreqPixelValue[pixel]++;
    }
    PGMFile.close();
    
    return image;
}

PGMImage readHCFile(string fileName){
    PGMImage image;
    nodePointer root=createNode(-1, -1);
    string P;
    int integer;
    bitset<16> bit("1010");
    ifstream HCFile(fileName, ios::in|ios::binary);

    if(!HCFile.is_open()){ cout << "File cannot find." << endl; }

    getline(HCFile, P);
    rebuildHuffmanTree(HCFile, root);
    
    HCFile.read((char *)&integer, sizeof(int));
    image.width = integer;
    HCFile.read((char *)&integer, sizeof(int));
    image.high = integer;
    HCFile.read((char *)&integer, sizeof(int));
    image.maxPixelValue = integer;

    while(HCFile.read((char*)&bit, 2*sizeof(char))){
        image.pixels.push_back((decode(bit.to_string(), root))->pixel);
    }
    HCFile.close();
    return image;
}

void writeHCFile(string fileName, PGMImage image, nodePointer root){
    ofstream HCFile(fileName, ios::out|ios::binary);
    string s;
    if(!HCFile.is_open()){ cout << "File cannot be opened." << endl; }

    HCFile.write("P2\n", 4);
    preorderTraversalWriteFile(HCFile, root);

    HCFile.write((char*) &(image.width), sizeof(int));
    HCFile.write((char*) &(image.high), sizeof(int));
    HCFile.write((char*) &(image.maxPixelValue), sizeof(int));

    for(int i=0;i<image.pixels.size();i++){
        s = image.table[image.pixels[i]];
        reverse(&s[0], &s[s.size()]);
        bitset<15> bit(s);
        HCFile.write((char*)&bit, 2*sizeof(char));
    }
    
    HCFile.close();
}

void writePGMFile(string fileName, PGMImage image){
    ofstream PGMFile(fileName, ios::out);
    if(!PGMFile.is_open()) cout << "File cannot be opened." << endl;

    PGMFile << "P2\n";
    PGMFile << image.width << " " << image.high << endl;
    PGMFile << image.maxPixelValue << endl;
    for (int i=0;i<=image.pixels.size();i++){
        PGMFile << image.pixels[i] << " ";
        if (i % 15 == 14) PGMFile << endl;
    }
    PGMFile.close();
}

nodePointer createNode(int pixel, int freq){
    nodePointer x = (nodePointer) malloc(sizeof(struct huffmanNode));
    x->pixel = pixel;
    x->freq = freq;
    x->left = NULL;
    x->right = NULL;
    return x;
}

void inorderTraversal(nodePointer node, string s, string* table){
    if(!node) return;
    else{
        s += "0";
        inorderTraversal(node->left, s, table);
        s.pop_back();
        s += "1";
        inorderTraversal(node->right, s, table);
        s.pop_back();
    }
    if (!(node->left) && !(node->right)){
        table[node->pixel] = s;
    }
    return ;
}

void preorderTraversalWriteFile(ofstream &HCFile, nodePointer node){
    if(!node) return; 
    else{
        HCFile << node->pixel << endl;
        HCFile << node->freq << endl;
        if(node->left){ HCFile << 1 << endl; }
        else{ HCFile << 0 << endl; }
        if(node->right){ HCFile << 1 << endl; }
        else{ HCFile << 0 << endl; }
        preorderTraversalWriteFile(HCFile, node->left);
        preorderTraversalWriteFile(HCFile, node->right);
    }
}

void rebuildHuffmanTree(ifstream &HCFile, nodePointer node){
    if(!node) return; 
    else{
        string s;
        getline(HCFile, s);
        node->pixel = atoi(s.c_str());
        getline(HCFile, s);
        node->freq = atoi(s.c_str());
        getline(HCFile, s);
        if(s == "1") { node->left = createNode(-1, -1);}
        else node->left = NULL;
        getline(HCFile, s);
        if(s == "1") { node->right = createNode(-1, -1); }
        else node->right = NULL;
        rebuildHuffmanTree(HCFile, node->left);
        rebuildHuffmanTree(HCFile, node->right);
    }
}

nodePointer buildHuffmanTree(int freq[]){
    priority_queue<nodePointer, vector<nodePointer>, cmp> pq;
    nodePointer now;
    for(int i=0;i<256;i++){
        now = createNode(i, freq[i]);
        pq.push(now);
    }
    cout << "the table of pixel values and their bit encoding: " << endl;
    priority_queue<nodePointer, vector<nodePointer>, cmp> copy_pq(pq);
    while(!copy_pq.empty()){
        cout << copy_pq.top()->pixel << ": " << copy_pq.top()->freq << endl;
        copy_pq.pop();
    }

    nodePointer min1, min2, parent;
    while(pq.size() > 1){
        min1 = pq.top();
        pq.pop();
        min2 = pq.top();
        pq.pop();

        parent = createNode(-1, min1->freq+min2->freq);
        parent->left = min1;
        parent->right = min2;
        pq.push(parent);
    }
    return parent;
}

nodePointer decode(string s, nodePointer node){
    if(!node) return NULL;
    else if(!node->left && !node->right) { return node; }
    else if(s.back() == '1') { return decode(s.erase(s.size()-1, 1), node->right); }
    else if(s.back() == '0') { return decode(s.erase(s.size()-1, 1), node->left); }
    return NULL;
}

double fileSize(string fileName){
    ifstream file(fileName, ios::in);
    if(!file.is_open()){
        cout << "Failed to open file.\n";
        return -1;
    }
    file.seekg(0, ifstream::end);
    double fsize = file.tellg()/1024;
    file.close();
    return fsize;
}