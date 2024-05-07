#include<iostream>
using namespace std;

class BST {
    int data;
    BST* left, *right;
public:
    BST() {
        data = 0;
        left = right = NULL;
    }
    BST(int value) {
        data = value;
        left = right = NULL;
    }
    BST* insert(BST*, int);
    void inorder(BST*);
    BST* search(BST*, int);
    void minvalue(BST*);
    void mirror(BST*);
    int height(BST*);
};

BST* BST::insert(BST* root, int value) {
    if (!root) {
        return new BST(value);
    }
    if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    return root;
}

void BST::inorder(BST* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

BST* BST::search(BST* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

void BST::minvalue(BST* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    cout << "Minimum Value=" << root->data << endl;
}

void BST::mirror(BST* root) {
    BST* temp = NULL;
    temp = root;
    if (root != NULL) {
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int BST::height(BST* root) {
    if (root == NULL) {
        return 0;
    }
    return (max((height(root->left)), (height(root->right))) + 1);
}

int main() {
    BST b, *root = NULL;
    int ch, n, value, key;
    while (1) {
        cout << "\n*******MENU*******";
        cout << "\n1.Create BST";
        cout << "\n2.Insert new node";
        cout << "\n3.Length";
        cout << "\n4.Minimum value";
        cout << "\n5.Mirror";
        cout << "\n6.Search";
        cout << "\n7.Display(inorder)";
        cout << "\n8.Exit";
        cout << "\nEnter your choice:) ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter number of elements in the BST:)  ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "NUMBER = ";
                cin >> value;
                root = b.insert(root, value);
            }
            cout << "INORDER Traversal: " << endl;
            b.inorder(root);
            break;
        case 2:
            cout << "NUMBER = ";
            cin >> value;
            root = b.insert(root, value);
            cout << "INORDER Traversal: " << endl;
            b.inorder(root);
            break;
        case 3:
            cout << "\nNumber of nodes in longest path:) " << b.height(root);
            break;
        case 4:
            b.minvalue(root);
            break;
        case 5:
            cout << "Inorder traversal: ";
            b.inorder(root);
            b.mirror(root);
            cout << "\nThe mirror of tree is:)";
            b.inorder(root);
            break;
        case 6:
            cout << "\nEnter key to search:) ";
            cin >> key;
            if (b.search(root, key) == NULL)
                cout << key << " Notfound" << endl;
            else
                cout << key << "found" << endl;
            break;
        case 7:
            cout << "Inorder traversal: " << endl;
            b.inorder(root);
            break;
        case 8:
            exit(0);
        }
    }
    return 0;
}
