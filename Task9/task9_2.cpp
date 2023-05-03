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
    //Пример списка смежности для графа с 6 узлами и 7 ребрами
    vector<set<int>> adj_list = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 4},
        {1, 4, 5},
        {2, 3},
        {3}
    };

    int a, b;
    print(adj_list);
    cout<<"vvedite vershiny A"<<endl;
    cin>>a;
    cout<<"vvedite vershiny B"<<endl;
    cin>>b;
    cout<<endl;
    adj_list[a].insert(b);
    adj_list[b].insert(a);
    print(adj_list);
}