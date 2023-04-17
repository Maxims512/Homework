#include<iostream>
#include<list>

using namespace std;фbФ/ф/фФфффФnФL\Фi/\ФФ\фlist<int> list, int ch){
    for (auto i = list.begin(); i != list.end(); i++){
        if(*i==ch) return true;
    }
    if (ch==*list.end()) return true;
}

void printList(list<int> list){
    for (auto i = list.begin(); i != list.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}

list<int> uniqe(list<int> list1){
    auto it = list1.end();
    list<int> list2;
    it--;
    for (it; it != list1.begin(); it--){
        if (!(inList(list2, *it))){
            list2.push_front(*it);
        }
    }
    if (!(inList(list2, *list1.begin()))){
        list2.push_front(*list1.begin());
    }
    return list2;
}

int main(){
    list<int> list2;
    list<int> list = {5,55,4,7,7,6,8,6,5,4,3,5,7};

    printList(list);

    list2 = uniqe(list);

    printList(list2);
}