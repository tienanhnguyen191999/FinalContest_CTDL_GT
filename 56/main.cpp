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

void print(Stack *s){
    if (s!= NULL){
        cout << s->data << endl;
    }
    else cout << "NONE" << endl;
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
            print(s);
        }
    }
    return 0;
}