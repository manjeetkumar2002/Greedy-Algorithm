// Given a string s of distinct characters and their corresponding frequency f[ ] i.e. character s[i] has f[i] frequency.

// Build the Huffman tree and return all the huffman codes in preorder traversal of the tree.

// Note: While merging, if two nodes have the same value (frequency), then the node whose subtree contains the character that appears earlier in the string s will be taken on the left of the Binary Tree and the other one to the right. Otherwise, the node with smaller value will be taken on the left of the subtree and the other one to the right.
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class Node
{
public:
    int freq;
    char c;
    int index;
    Node *left, *right;
    Node(int frequency, char name, int idx)
    {
        freq = frequency;
        c = name;
        index = idx;
        left = right = NULL;
    }
};
class Comp
{
public:
    bool operator()(Node *a, Node *b)
    {
        if (a->freq != b->freq)
        {
            return a->freq > b->freq;
        }
        // compare base on index
        return a->index > b->index;
    }
};
void preorder(Node *root, string &temp, vector<string> &ans)
{
    if (!root)
        return;

    // leaf node push the temp to ans
    if (!root->left and !root->right)
    {
        ans.push_back(temp);
        return;
    }

    // go to left
    temp.push_back('0');
    preorder(root->left, temp, ans);
    temp.pop_back();
    temp.push_back('1');
    preorder(root->right, temp, ans);
    temp.pop_back();

    // go to right
}
vector<string> huffmanCodes(string &s, vector<int> f)
{
    if (s.size() == 1)
        return vector<string>{"0"};
    // build the min heap
    priority_queue<Node *, vector<Node *>, Comp> pq;

    // push all the characters in min heap
    for (int i = 0; i < s.size(); i++)
    {
        Node *root = new Node(f[i], s[i], i);
        pq.push(root);
    }

    // build the huffman tree
    while (pq.size() > 1)
    {
        Node *first = pq.top();
        pq.pop();
        Node *second = pq.top();
        pq.pop();

        // create new root and push into heap
        Node *root = new Node(first->freq + second->freq, '$', min(first->index, second->index));
        root->left = first;
        root->right = second;
        pq.push(root);
    }

    Node *root = pq.top();
    pq.pop();

    // find the preorder of the tree
    vector<string> ans;
    string temp;
    preorder(root, temp, ans);
    return ans;
}
// Given a Huffman MinHeap tree and an encoded binary string, complete the function huffDecode() to decode the string and return the original text. Each node of the tree contains a character and its frequency, where the special character $ represents internal nodes. Traverse the tree from the root using 0 for left and 1 for right, and whenever a leaf node is reached, add its character to the answer and restart traversal from the root.

// Note: Compiler will take string s as an input and encode it in binary string internaly. 

struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;
};
 string huffDecode(struct MinHeapNode* root, string binaryString) {
        // Code here
       // Special case: only one character in Huffman tree
               if (root->left == NULL && root->right == NULL) {
                   string ans;

                   for (int i = 0; i < binaryString.size(); i++) {
                       ans.push_back(root->data);
                   }

                   return ans;
               }
        string ans;
        MinHeapNode * curr = root;
        for(int i=0;i<binaryString.size();i++){
            char ch = binaryString[i];
            if(ch=='1'){
               
                curr = curr->right;
            }
            else{
                
                curr = curr->left;
            }
            
            if(curr->data!='$'){
                ans.push_back(curr->data);
                curr = root;
            }
        }
        
        return ans;
    }