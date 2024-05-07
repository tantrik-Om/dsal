#include<iostream>
#include<string.h>
using namespace std;

class BST {
    string word;
    string meaning;
    BST *left, *right;
public:
    BST() {
        word = "";
        meaning = "";
        left = right = NULL;
    }
    
    BST(string w, string m) {
        word = w;
        meaning = m;
        left = right = NULL;
    }
    
    BST* insert(BST *root, string w, string m) {            //This function inserts a new node into the BST. 
        if (root == NULL) {
            return new BST(w, m);
        }
        if (w > root->word) {
            root->right = insert(root->right, w, m);
        }
        else if (w < root->word) {
            root->left = insert(root->left, w, m);
        }
        return root;
    }
    
    void ascorder(BST* root) {
        if (root != NULL) {
            ascorder(root->left);
            cout << root->word << "-" << root->meaning << endl;
            ascorder(root->right);
        }
    }
    
    void descorder(BST* root) {
        if (root != NULL) {
            descorder(root->right);
            cout << root->word << "-" << root->meaning << endl;
            descorder(root->left);
        }
    }
    
    int search(BST* root, string key) {
        int c = 0;
        while (root != NULL) {
            c++;
            if (root->word == key) {
                cout << "\nWord found with comparisons:" << c;
                return 1;
            }
            if (key > root->word)
                root = root->right;
            if (key < root->word)
                root = root->left;
        }
        return -1;
    }
    
    void update(BST* root, string key) {
        while (root != NULL) {
            if (root->word == key) {
                cout << "Enter new meaning of the word " << root->word << ": ";
                cin >> root->meaning;
                return;
            }
            else if (key > root->word)
                root = root->right;
            else
                root = root->left;
        }
        cout << "\nWord not found";
    }
    
    BST* delet(BST* root, string w) {
        BST* temp;
        if (root == NULL)
            return root;
        if (w < root->word) {
            root->left = delet(root->left, w);
            return root;
        }
        else if (w > root->word) {
            root->right = delet(root->right, w);
            return root;
        }
        if (root->right == NULL && root->left == NULL) {
            delete root;
            cout << "Deleted..";
            return NULL;
        }
        else if (root->left == NULL) {
            temp = root->right;
            delete root;
            cout << "Deleted..";
            return temp;;
        }
        else if (root->right == NULL) {
            temp = root->left;
            delete root;
            cout << "Deleted..";
            return temp;
        }
        else {
            BST* succParent = root;
            BST* succ = root->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }
            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
            root->word = succ->word;
            root->meaning = succ->meaning;
            delete succ;
            cout << "Deleted...";
            return root;
        }
    }
};

int main() {
    BST b, *root = NULL;
    int ch, n, count = 0;
    string word, meaning, key;
    while (1) {
        cout << "\n*****MENU*****";
        cout << "\n1.Create BST";
        cout << "\n2.Comparisons";
        cout << "\n3.Delete";
        cout << "\n4.Update";
        cout << "\n5.Ascending order";
        cout << "\n6.Descending order";
        cout << "\n7.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter number of elements in the BST:";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "\nEnter words:";
                cin >> word;
                cout << "\nEnter meaning:";
                cin >> meaning;
                root = b.insert(root, word, meaning);
            }
            break;
        case 2:
            cout << "\nEnter the word to search:";
            cin >> word;
            if (b.search(root, word) == 1)
                cout << "\nKeyword found";
            else
                cout << "\nKeyword not found";
            break;
        case 3:
            cout << "\nEnter word to delete:";
            cin >> key;
            b.delet(root, key);
            break;
        case 4:
            cout << "\nEnter word to update:";
            cin >> key;
            b.update(root, key);
            break;
        case 5:
            cout << "\nAscending Order:" << endl;
            b.ascorder(root);
            break;
        case 6:
            cout << "\nDescending Order:" << endl;
            b.descorder(root);
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}
