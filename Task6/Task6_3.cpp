#include<iostream>
#include<list>

using namespace std;


void printList(list<int> list){
    for (auto i = list.begin(); i != list.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}

void bubbleSort(list<int> &list){
    auto it1 = list.begin();
    auto it2 = list.begin();
    auto kon2 = list.begin();
    kon2--;


    for (it1; it1!=kon2; it1++){ 
        for (it2; it2!=list.end(); it2++){
            cout<<"*";
        }
    }
}


int main(){
    list<int> list = {1,2,3,4,5,6,7,8,9};

    printList(list);

    bubbleSort(list);


}