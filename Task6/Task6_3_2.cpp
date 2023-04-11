#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct Node{            
    int x;
    Node *Next, *Prev;                      //Указатели 
};
 
class List{
    Node *Head, *Tail;                  
public:
    List():Head(NULL), Tail(NULL){}        
    ~List();                                
 
    void add(int);                         
    void show();                           
    void sort();
 
 
};
 
 

void List::add(int value){
    Node *temp = new Node;                  //Выделяем память
    temp->x = value;                        
    temp->Next = NULL;                      //основной признак последнего элемента списка
 
 
 
    if (!Head){                             //Если Head==NULL, то
        temp->Prev = NULL;                  //Предыдущий элемент указывает в пустоту
        Head = Tail = temp;                 //Голова тот же же элемент, что и хвост
    } else {
       temp->Prev = Tail;                   //Предыдущий элемент относительно нового — это хвостовой элемент не обновлённого ещё списка
       Tail->Next = temp;                   //Следующий элемент относительно нового — это прицепляемый элемент к необновлённого ещё списка, цепляем к хвостовому новый
       Tail = temp;                         //Меняем адрес хвоста
    }
 
}
 
void List::show(){
    Node * temp = Head;                     
    while (temp){                           //(temp != NULL)
        cout << temp->x <<" ";           
        temp = temp->Next;                 
    }
}
 
void List::sort(){
    Node *left = Head;                 //Первый элемент — это пусть будет голова
    Node *right = Head->Next;          //Второй элемент — это пусть будет следующий за головой элемент
 
    Node *temp = new Node;              //Временное звено для хранения переставляемого всех значений переставляемого звена
 
    while (left->Next){                 //Обходим по всем звеньям, за исключением крайнего правого
        while (right){              //Обходим по всем звеньям, включая крайний правый (по всем относительно первого левого на текущий момент)
            if ((left->x) > (right->x)){        //Проверяем необходимость перестановки
                temp->x = left->x;              //И переставляем все внутренние элементы, за исключением указателей связи, местами
                left->x = right->x;             
                right->x = temp->x;             
            }
            right = right->Next;                    //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
            }
        left = left->Next;                              //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
        right = left->Next;                             //второй указатель убежал немного вперёд, возвращаем его назад
    }
}
 
List::~List(){
   while (Head)                                     //Пока на начале списка что-то есть
   {
         Tail = Head->Next;                         //Резервная копия адреса следующего звена списка
         delete Head;                               //Очистка памяти от первого звена
         Head = Tail;                               //Смена адреса начала на адрес следующего элемента
   }
}
 
 
int main ()
{
    List lst;
    lst.add(9);
    lst.add(92);
    lst.add(3);
    lst.add(9);
    lst.add(32);

    lst.show();
 
    cout<<endl<<endl;

    lst.sort();

    lst.show();
 
}