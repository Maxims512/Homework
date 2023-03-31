#include<iostream>

#include<list>

using namespace std;

void printList(list<int> list){
    for (auto i = list.begin(); i != list.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}



int lastEven(list<int> list){
    bool flag=true;
    auto p = list.end();
    p--;
    int ret;
    if (*list.begin()%2==0){
        ret = *list.begin();
    }
    for (p; p != list.begin(); p--){
        if ((*p)%2==0 && flag){
            ret = *p;
            flag=false;
        }
    }
    return ret;
}

int min_element(list<int> list){
    int min = *(list.end());
    for (auto i = list.end(); i != list.begin(); i--){
        if ((*i) < min){
            min = *i;
        }
    }
    if (*list.begin()<min){
        min = *list.begin();
    }

    return min;
}

void vstavk(list<int> &list, int chetn, int min){
    for (auto i = list.begin(); i != list.end(); i++){
        if (*i == min){
            i++;
            list.insert(i, chetn);
        }
    }
}

int main(){
    list<int> list = {2,3,1,4,51,1,7,6,1,3};
    printList(list);
    int chetn = lastEven(list);
    cout<<"lastEven = "<<chetn<<endl;
    int min = min_element(list);
    cout<<"min = "<<min<<endl;
    vstavk(list, chetn, min);
    printList(list);
}

