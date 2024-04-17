#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in the binary tree
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else {
        if (value < root->value) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    int numNodes, value;
    struct TreeNode* root = NULL;

    // Input the number of nodes in the binary tree
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);

    // Input the values of the nodes
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < numNodes; ++i) {
        printf("Node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Perform inorder traversal and print the values
    printf("Inorder Traversal:\n");
    inorderTraversal(root);

    return 0;
}
