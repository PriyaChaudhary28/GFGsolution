//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *newNode(int key)
{
    Node *node = new Node(key);
    return node;
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void printList(Node *head)
{
    if(head){
        while (head)
        {
            if(head->left)
                cout<<"-1 ";
            cout << head->data << " ";
            head = head->right;
        }
        cout << "\n";
    }
    else{
        cout << "Empty Tree!!";
    }
}


// } Driver Code Ends

// User function Template for C++

/* Node of the binary search tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    Node *flattenBST(Node *root) {
        if(!root) {
            return NULL;
        }
        
        Node* head   = flattenBST(root->left);
        root->left = NULL;
        root->right  = flattenBST(root->right);
        
        if (head) {
            Node *temp = head;
            while (temp->right) {
                temp = temp->right;
            }
            temp->right = root;
        } else {
            // If head is NULL, root becomes the head
            head = root;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        auto ans = ob.flattenBST(root);
        printList(ans);
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends