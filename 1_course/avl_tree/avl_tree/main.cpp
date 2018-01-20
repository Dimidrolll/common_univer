//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//struct Node 
//{
//   int x; 
//   Node *l,*r;
//
//};
//
//void add_node(int x,Node *&MyTree) 
// {
//  if (MyTree) 
//    {
//      if (x < MyTree->x)
//        add_node(x, MyTree->l);
//      else
//        add_node(x, MyTree->r); 
//    } else 
//    {
//    MyTree=new Node; 
//    MyTree->x=x; 
//    MyTree->l=MyTree->r=NULL; 
//    }
//}
//
//
//
//Node* destroy(Node *Tree)
//{
//
//    if( Tree->l == 0 )
//    {
//
//        Node* right = Tree->r;
//
//        *Tree = *right;
//
//        right->l = 0;
//        right->r = 0;
//        delete right;
//    } 
//    else
//
//    {
//
//        Node *c = Tree->l;
//
//        Node *p = Tree->l;
//
//        while( c->r )
//        {
//            p = c;
//            c = c->r;
//        }
//
//        p->r = c->l;
//
//        c->l = NULL;
//
//        Tree->x = c->x;
//
//        delete c;
//    }
//    return Tree;
//}
//
//Node* remove(Node *Tree, int x)
//{
//
//    if( Tree == NULL )
//        return 0;
//
//    if( Tree->x < x )
//    {
//
//        Tree->r = remove(Tree->r, x);
//        return Tree;
//    }
//    else
//
//    if( x < Tree->x )
//    {
//
//        Tree->l = remove(Tree->l, x);
//        return Tree;
//    }
//
//    return destroy(Tree);
//}
//
//void DeleteTree(Node *Tree)
//{
//  if (Tree) 
//  {
//      DeleteTree(Tree->l);
//      DeleteTree(Tree->r);
//      delete Tree;
//  }
//}
//
//void print_tree(int deep, Node *p)
//{
// if(p)
// {
//  print_tree(deep + 1, p->r);
//  for ( int i = 0; i < deep; i ++ )
//	  printf("  ");
//  printf("%d",p->x);
//  printf("\n");
//  print_tree(deep + 1, p->l);
// }
//}
//int main()
//{
//  Node *Tree=NULL;  
//  int z,k;
//  cout << "vvedit kilkist\n";
//  cin >> z;
//  for (int i=0;i<z;i++) 
//  {
//      cout << "vvedit chisla\n";
//    cin >> k;
//    add_node(k,Tree);
//  }
//  
// print_tree(0,Tree);
// int remove_data;
// cin >> remove_data;
// remove(Tree,remove_data);
// print_tree(0,Tree);
// DeleteTree(Tree);
// system("pause");
//  return 0;
//}
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL,"Russian");
float l, p, r, n;
printf("Вычисление стоимости поездки на дачу.\n");
printf("Введите исходные данные: \n");
printf("\nРасстояние до дачи в одну сторону (км) -> ");
scanf("%f",&l);
l = l / 50;
printf("\nРасход бензина (л на 100 км) -> ");
scanf("%f",&r);
printf("\nЦена литра бензина (руб.) -> ");
scanf("%f",&p);
n = l * r *p;
printf("\nПоездка на дачу обойдется %.2f руб. \n", n);
system("pause");
return(0);
}