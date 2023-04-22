#include <iostream>
#include <string>

#include <stack>
using namespace std;

struct tree{ //узел
    int inf;
    tree* right ;
    tree * left ;
    tree *parent;
};

tree *node(int x){ //создание узла
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void inorder(tree *tr){//симметричный обход
    if(tr){
        inorder ( tr->left);
        cout << tr->inf << " ";
        inorder ( tr->right);
    }
}



void insert(tree *&tr, int x){//вставка
    tree *n = node(x);
    if (!tr) tr = n; //если дерево пустое - корень
    else {
        tree *y = tr;
        while(y){ //ищем куда вставлять
            if (n->inf > y->inf){ //правая ветка
                if (y->right){
                    y = y->right;
                }
                else{
                    n->parent = y; //узел становится правым ребенком
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf){//левая ветка
                if (y->left){
                    y = y->left;
                } else{
                    n->parent = y;//узел становится левым ребенком
                    y->left = n;
                    break;
                }
            }
            else {
                break;
            }   
        }
    }
}


int heigh(tree *tr)
{
    if (tr == NULL) {
        return 0;
    }
    else if (tr->left == NULL&&tr->right == NULL) {
        return 0;
    }
    else if (heigh(tr->left) > heigh(tr->right))
        return heigh(tr->left) + 1;
    else
        return heigh(tr->right) + 1;
 
}


int main(){
    int x;
    tree *tr = NULL;
    for(int i = 0; i < 9; i++){
        cout << i <<": ";
        cin >> x;
        insert (tr , x);
    }
    cout << endl;
    inorder(tr);

    cout<<endl<<heigh(tr);
}