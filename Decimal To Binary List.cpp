
#include <iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};

node* getNode(int x) {
    node* p = new node;
    if (p != NULL) {
        p->info = x;
        p->next = NULL;
    }
    return p;
}

void Init(Stack& S) {
    S.pHead = 0;
}

int IsEmpty(Stack S) {
    if (S.pHead == NULL) {
        return 1;
    }
    return 0;
}

void Push(Stack& S, int x) {
    node* newele = getNode(x);
    if (S.pHead == NULL) {
        S.pHead = newele;
    }
    else {
        newele->next = S.pHead;
        S.pHead = newele;
    }
}

int Pop(Stack& S) {
    node* p;
    int x;
    if (!IsEmpty(S)) {
        p = S.pHead;
        S.pHead = p->next;
        x = p->info;
        delete p;
        return x;
    }
}

void DecimaltoBinary1(int n, Stack& S) {
    if (n == 0) {
        Push(S, 0);
    }
    else {
        while (n != 0) {
            Push(S, n % 2);
            n /= 2;
        }
    }
}

void printStack(Stack &S) {
    while (!IsEmpty(S)) {
        cout << Pop(S);
    }
}
int main()
{
    Stack S; Init(S);
    int n, x;
    cin >> n;
    DecimaltoBinary1(n, S);
    printStack(S);
    return 0;
}


