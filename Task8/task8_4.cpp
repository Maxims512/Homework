#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
 
 
struct tree {
   int inf;
   tree *right;
   tree * left ;
};
  
tree *node(int x){
   tree *n = new tree;
   n ->inf = x;
   n ->left = n ->right = NULL;
   return n;
}
  
  
void create(tree *&tr, int n){
    int x;
    if (n > 0){
        cout<<"x: ";
        cin >> x;
        tr = node(x);
        int nl = n/2;
        int nr = n  - nl  -  1;
        create(tr ->left, nl);
        create(tr ->right,nr);
    }
}

int righth(tree *tr){
    int k = 0;
    tree *x = tr;
    while (x){
        k++;
        x = x ->right;
    }
    return k  -  1;
}

int lefth(tree *tr){
    int k = 0;
    tree *x = tr;
    while (x){
        k++;
        x = x ->left;
    }
    return k  -  1;
}
   
void print(tree *tr, int k){
    if (! tr ) cout << "Empty tree\n";

    else{
        queue<tree*> cur, next;
        tree *r = tr;
        cur.push(r);
        int j = 0;
        while (cur.size()){
            if (j == 0) {
                for (int i = 0; i < (int)pow(2.0, k)  -  1; i++)
                    cout << ' ';
            }

            tree *buf = cur.front() ;
            cur.pop();
            j++;
            if (buf){
                cout << buf->inf;
                next.push(buf ->left);
                next.push(buf ->right);
                for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
                    cout << ' ';
            }

            if (!buf){
                for (int i = 0; i < (int)pow(2.0 , k + 1)  - 1; i++)
                    cout << ' ';
                cout << ' ';
            }
            if(cur.empty()){
                cout << endl;
                swap(cur, next);
                j = 0;
                k--;
            }
        }
    }
}

tree* find(tree* node, int x) {
    if (node == NULL)
        return NULL;
 
    if (node->inf == x)
        return node;
 
    tree* res = NULL;
 
    if (node->right != NULL)
        res = find(node->right, x);
 
    if (res == NULL && node->left != NULL)
        res = find(node->left, x);
 
    return res;
}

int height(tree* node) {
    if (node == NULL)
        return 0;
 
    else if (node->left == NULL && node->right == NULL)
        return 0;
 
    else if (height(node->left) > height(node->right))
        return height(node->left) + 1;
 
    else
        return height(node->right) + 1;
}
 
    
int main(){
    tree *tr = NULL;
    int n = 9;
    create(tr , n);
    int k = int (log((float)n)/log((float)2.0));
    print(tr, k);

    cout<<height(find(tr, 2));   
}
