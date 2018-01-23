#include <iostream>
#include <windows.h>

using namespace std;

struct Tree {
    int value;
    Tree *left, *right;

};

void add_elem(int x, Tree *&tree) {
    if (tree) {
        if (x == tree ->value){
            cout << "uje sushestvuet)))" << endl;
            return;
        }
        if (x < tree->value)
            add_elem(x, tree->left);
        if (x > tree ->value)
            add_elem(x, tree->right);
    } else {
        tree = new Tree;
        tree->value = x;
        tree->left = nullptr;
        tree->right = nullptr;
    }
}

void print_tree(int deep, Tree *tree) {

    if (tree) {
        print_tree(deep + 1, tree->right);
        for (int i = 0; i < deep; i++)
            cout << "   ";
        cout << tree->value << endl;
        print_tree(deep + 1, tree->left);
    }
}

Tree *find_elem(Tree *&tree, int x){
    if (!tree){
        cout << "Invalid value" << endl;
        return nullptr;
    }
    if (tree ->value == x) return tree;
    if (tree ->value < x){
        return find_elem(tree->right, x);
    } else {
        return find_elem(tree->left, x);
    }
}

void delete_tree (Tree *&tree){
    if (tree){
        if (tree ->right) delete_tree(tree->right);
        if (tree ->left) delete_tree(tree->left);
        delete(tree);
    }
}

void delete_list (int x, Tree *&tree){
    Tree *node;
    if (tree){
        if (tree->left->value == x) {
            node = tree ->left;
            delete (node);
            tree->left = nullptr;
            return;
        }
        if (tree->right->value == x) {
            node = tree ->right;
            delete (node);
            tree->right = nullptr;
            return;
        }
        if (tree->value < x) {
            delete_list(x, tree->right);
        } else {
            delete_list(x, tree->left);
        }
    } else cout << "net takogo" << endl;
}

void remove_elem (int x, Tree *&tree){
    Tree *del_t = find_elem(tree,x);
    if (del_t == nullptr)
        return;
    Tree *tmp = del_t;
    Tree *node = del_t;
    if (del_t ->left == nullptr && del_t ->right == nullptr){
        delete_list(x,tree);
        //delete(del_t)

        return;
    }
    if (del_t ->right) {
        if (del_t->right->left == nullptr) {
            del_t->value = tmp->right->value;
            del_t->right = del_t->right->right;
            tmp = tmp ->right;
            delete (tmp);
        } else {
            del_t = del_t->right;
            tmp = tmp->right;
            while (del_t->left->left) {
                del_t = del_t->left;
                tmp = tmp->left;
            }
            del_t = del_t->left;
            node->value = del_t->value;
            tmp->left = del_t->right;
            delete (del_t);
        }
    } else {
        if (del_t->left->right == nullptr) {
            del_t->value = tmp->left->value;
            del_t->left = del_t->left->left;

            tmp = tmp ->left;
            delete (tmp);
        } else {
            del_t = del_t->left;
            tmp = tmp->left;
            while (del_t->right->right) {
                del_t = del_t->right;
                tmp = tmp->right;
            }
            del_t = del_t->right;
            node->value = del_t->value;
            tmp->right = del_t->left;
            delete (del_t);
        }
    }
}

void blinking(){
    Sleep(700);cout << ".";
    Sleep(700);cout << ".";
    Sleep(700);cout << ".";
    Sleep(700);
}

int main() {
    Tree *tree = nullptr;
    int const n = 9;
    int inp_arr[n] = {5, 3, 8, 7, 4, 1, 2, 9, 0};//начальные элементы дерева
    for (int i = 0; i < n; ++i)
        add_elem(inp_arr[i], tree);

    bool exit_mark = 1;
    int mark;

    cout << "Instruction:\n  1 - print()\n  2 - add(<number>)\n  3 - remove(<number>)\n  4 - get_joke()\n  5 - exit(true)\n  6 - exit(false)\n";
    while (exit_mark) {
        cin >> mark;
        switch (mark){
            case 1: cout << endl << endl;print_tree(0,tree);break;
            case 2:cout << "add_num = ";cin >> mark;add_elem(mark,tree);break;
            case 3:cout << "del_num = ";cin >> mark;remove_elem(mark,tree);break;
            case 4:cout << "-Why cats loves programmers?\n";Sleep(2000);cout <<"-Because there hands smell like mice.";Sleep(1000);cout << ")0)))00).\n";break;
            case 5:exit_mark = 0;break;
            case 6:cout << "exit()\nDownload parameters";blinking();cout << "\nCalculation";blinking();cout << "\nComputation";blinking();cout << "\nWTF parameter?!?!?!\n";break;
            default: cout << "invalid parameter" << endl;
        }
    }
    delete_tree(tree);
    return 0;
}