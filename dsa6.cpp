                            Assignment 6
Code-
#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Insert a node into the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Delete a node from the BST
    void deleteNode(int value) {
        root = deleteRecursive(root, value);
    }

    // Search for a node in the BST
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Display the tree using in-order traversal
    void display() {
        displayInOrder(root);
        cout << endl;
    }

    // Display the depth of the tree
    int depth() {
        return calculateDepth(root);
    }

    // Display the mirror image of the tree
    void mirror() {
        root = mirrorRecursive(root);
    }

    // Create a copy of the tree
    BinarySearchTree copy() {
        BinarySearchTree copiedTree;
        copiedTree.root = copyRecursive(root);
        return copiedTree;
    }

    // Display all parent nodes with their child nodes
    void displayParents() {
        displayParentChild(root);
    }

    // Display leaf nodes
    void displayLeaves() {
        displayLeafNodes(root);
    }

    // Display the tree level wise
    void displayLevelWise() {
        displayLevelOrder(root);
        cout << endl;
    }

private:
    // Helper function for insertion
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr)
            return new TreeNode(value);

        if (value < node->data)
            node->left = insertRecursive(node->left, value);
        else if (value > node->data)
            node->right = insertRecursive(node->right, value);

        return node;
    }

    // Helper function for deletion
    TreeNode* deleteRecursive(TreeNode* node, int value) {
        if (node == nullptr)
            return node;

        if (value < node->data)
            node->left = deleteRecursive(node->left, value);
        else if (value > node->data)
            node->right = deleteRecursive(node->right, value);
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            node->data = minValue(node->right);
            node->right = deleteRecursive(node->right, node->data);
        }
        return node;
    }

    // Helper function for searching
    bool searchRecursive(TreeNode* node, int value) {
        if (node == nullptr)
            return false;

        if (value == node->data)
            return true;
        else if (value < node->data)
            return searchRecursive(node->left, value);
        else
            return searchRecursive(node->right, value);
    }

    // Helper function for in-order traversal
    void displayInOrder(TreeNode* node) {
        if (node != nullptr) {
            displayInOrder(node->left);
            cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

    // Helper function for calculating depth
    int calculateDepth(TreeNode* node) {
        if (node == nullptr)
            return 0;
        else {
            int leftDepth = calculateDepth(node->left);
            int rightDepth = calculateDepth(node->right);

            return max(leftDepth, rightDepth) + 1;
        }
    }

    // Helper function for creating the mirror image
    TreeNode* mirrorRecursive(TreeNode* node) {
        if (node == nullptr)
            return nullptr;

        TreeNode* temp = node->left;
        node->left = mirrorRecursive(node->right);
        node->right = mirrorRecursive(temp);

        return node;
    }

    // Helper function for creating a copy
    TreeNode* copyRecursive(TreeNode* node) {
        if (node == nullptr)
            return nullptr;

        TreeNode* newNode = new TreeNode(node->data);
        newNode->left = copyRecursive(node->left);
        newNode->right = copyRecursive(node->right);

        return newNode;
    }

    // Helper function for displaying parent nodes with child nodes
    void displayParentChild(TreeNode* node) {
        if (node != nullptr) {
            if (node->left != nullptr || node->right != nullptr) {
                cout << "Parent: " << node->data << " -> ";
                if (node->left != nullptr)
                    cout << "Left Child: " << node->left->data << " ";
                if (node->right != nullptr)
                    cout << "Right Child: " << node->right->data;
                cout << endl;
            }
            displayParentChild(node->left);
            displayParentChild(node->right);
        }
    }

    // Helper function for displaying leaf nodes
    void displayLeafNodes(TreeNode* node) {
        if (node != nullptr) {
            if (node->left == nullptr && node->right == nullptr)
                cout << node->data << " ";
            displayLeafNodes(node->left);
            displayLeafNodes(node->right);
        }
    }

    // Helper function for level order traversal
    void displayLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
    }

    // Helper function to find the minimum value in a BST
    int minValue(TreeNode* node) {
        int minValue = node->data;
        while (node->left != nullptr) {
            minValue = node->left->data;
            node = node->left;
        }
        return minValue;
    }
};

int main() {
    BinarySearchTree bst;

    char choice;
    do {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display Tree\n";
        cout << "5. Display Depth\n";
        cout << "6. Display Mirror Image\n";
        cout << "7. Create a Copy\n";
        cout << "8. Display Parent Nodes with Child Nodes\n";
        cout << "9. Display Leaf Nodes\n";
        cout << "10. Display Tree Level Wise\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                bst.insert(value);
                cout << "Value inserted successfully!\n";
                break;
            }
            case '2': {
                int value;
                cout << "Enter the value to delete: ";
                cin >> value;
                bst.deleteNode(value);
                cout << "Value deleted successfully!\n";
                break;
            }
            case '3': {
                int value;
                cout << "Enter the value to search: ";
                cin >> value;
                if (bst.search(value))
                    cout << "Value found in the tree!\n";
                else
                    cout << "Value not found in the tree.\n";
                break;
            }
            case '4':
                cout << "Tree: ";
                bst.display();
                break;
            case '5':
                cout << "Depth of the Tree: " << bst.depth() << endl;
                break;
            case '6':
                cout << "Mirror Image of the Tree: ";
                bst.mirror();
                bst.display();
                break;
            case '7': {
                BinarySearchTree copiedTree = bst.copy();
                cout << "Copied Tree: ";
                copiedTree.display();
                break;
            }
            case '8':
                cout << "Parent and Child Nodes: " << endl;
                bst.displayParents();
                break;
            case '9':
                cout << "Leaf Nodes: ";
                bst.displayLeaves();
                cout << endl;
                break;
            case '10':
                cout << "Tree Level Wise: ";
                bst.displayLevelWise();
                break;
            case '0':
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '0');

    return 0;
}

Output-

 
