#include <iostream>
#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

void Init(Stack &S) {
    S.n = 0;
}

int isFull(Stack &S) {
    return S.n >= MAX;
}

int isEmpty(Stack &S) {
    return S.n == 0;
}


void Push(Stack& S, const int x) {
    if (!isFull(S)) {
        S.arr[S.n++] = x;
    }
}

int Top(Stack &S) {
    if (isEmpty(S)) {
        return -1;
    }
    return S.arr[S.n - 1];
}

void Pop(Stack& S) {
    if (!isEmpty(S)) {
        S.n--;
    }
    
}

void printStack(Stack &S) {
    if (!isEmpty(S)) {
        for (int i = 0; i <= S.n - 1; i++) {
            cout << S.arr[i] << " ";
        }
    }
    else {
        cout << "Stack is empty";
    }
}

int main()
{
    Stack S; Init(S);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        Push(S, x);

    }
    cout << "Stack:";
    printStack(S);
    cout << "\nTop:" << Top(S);
    Pop(S);
    cout << "\nUpdated Stack:";
    printStack(S);
    cout << "\nTop:" << Top(S);
    return 0;
}




