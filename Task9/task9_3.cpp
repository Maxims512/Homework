#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print(vector<set<int>> st){
    for (int i = 0; i < st.size(); i++){
        auto it = st[i].begin();
        cout<<i<<": ";
        for (it; it!=st[i].end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    //Пример списка смежности для графа с 6 узлами и 8 ребрами
    vector<set<int>> adj_list = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 4, 3},
        {1, 4, 5, 2},
        {2, 3},
        {3}
    };

    print(adj_list);

    for (int i = 0; i < adj_list.size(); i++){
        cout<<"Stepen vershini "<<i<<" = "<<adj_list[i].size()<<endl;
    }
}