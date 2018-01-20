#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

bool mark = true;// можно ли создать дерево

struct Node{
  int apple;
  Node *left, *right;
};
typedef Node *PNode;

void cr_memor(PNode &root, int apple){//создание вершины
  root ->apple = apple;
  root ->left = NULL;
  root ->right = NULL;
}

void print_tree(PNode root, int h){//рисует дерево
  int i;
       if (root!=NULL)
	 {
         print_tree(root ->right, h + 1);
         for (i = 1; i <= h; ++i) 
			cout << "   ";
         cout << root ->apple << endl; 
         print_tree(root ->left, h + 1); 
	}
}

void sortir(int *weight,string *way, int n){//сортирует пути по длине
  int i, j, t;
  string t_str;
  for (i = 0; i < n; ++i)
    for (j = 0; j < n - i - 1; ++j)
      if (way[j].size() > way[j + 1].size()){
        t_str = way[j]; t = weight[j];
        way[j] = way[j + 1]; weight[j] = weight[j + 1];
        way[j + 1] = t_str; weight[j + 1] = t;
      }
}

void hang_apple(int apple, string branch, PNode &root){//навешивает вершину
  int i = 0;
  PNode copy_root = root;
  while (1){
    if (branch[i] == '0')
      if (copy_root ->left)
        copy_root = copy_root ->left;
      else
        break;
    if (branch[i] == '1')
      if (copy_root ->right)
        copy_root = copy_root ->right;
      else
        break;
    ++i;
  }
  if (i == branch.size() - 1){
    if (branch[i] == '0'){ 
      copy_root ->left = new Node;
      copy_root = copy_root ->left;
      cr_memor(copy_root ,apple);
    } else {
      copy_root ->right = new Node;
      copy_root = copy_root ->right;
      cr_memor(copy_root, apple);
    }
  } else {
    mark = false;
  } 
}

void create_tree(int *weight,string *way, int n, PNode &root){//создает дерево
  sortir(weight, way, n);
  int i;
  for (i = 0; i < n; ++i){
    hang_apple(weight[i], way[i], root);
    if (!mark)
      break;
  }
  if (i == n)
      print_tree(root,0);
  else
    cout << "invalid tree" << endl;
}

void main(){//main(), они и в Африке main()
  ifstream input("input.txt");
  const int N = 100;
  int weight[N], n = 0;
  string way[N];
  PNode root = new Node;

  while (!input.eof()){//считывание
    input >> weight[n];
    input >> way[n];
    ++n;
  }

  cr_memor(root,0);

  create_tree(weight,way, n, root);

  input.close();
  getch();
}