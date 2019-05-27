#include <iostream>
#include <cstring>
using namespace std;

typedef struct Stack{
    int data;
    Stack *next;
};

void push (Stack *&s, int data){
    Stack *tmp = new Stack;
    tmp->data = data;
    tmp->next = s;
    s = tmp;
}

int pop (Stack *&s){
    Stack *tmp = s;
    int save = tmp->data;
    s = s->next;
    delete(tmp);
    return save;
}

void show(Stack *s){
    while (s!= NULL){
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}
int main(){
    int turn,n;
    char tmp[100];
    Stack *s = NULL;
    cin >> turn;
    while (turn--){
        cin >> tmp;
        if (strcmp(tmp,"push") == 0){
            cin >> n;
            push(s,n);
        }
        else if (strcmp(tmp,"pop") == 0){
            pop(s);
        }
        else{
            show(s);
        }
    }
    return 0;
}