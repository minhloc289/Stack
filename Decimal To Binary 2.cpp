#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

void Init(Stack& S) {
    S.n = 0;
}

int isFull(Stack& S) {
    return S.n >= MAX;
}

int isEmpty(Stack& S) {
    return S.n == 0;
}


void Push(Stack& S, const int x) {
    if (!isFull(S)) {
        S.arr[S.n++] = x;
    }
}

int Top(Stack& S) {
    if (isEmpty(S)) {
        return -1;
    }
    return S.arr[S.n - 1];
}

void pop(Stack& S) {
    if (isEmpty(S)) {
        return;
    }
    S.n--;
}

void DecimaltoBinary2(int n, Stack& S) {
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

void printStack(Stack S) {
    for (int i = S.n - 1; i >= 0; i--) {
        cout << S.arr[i];
    }
}

int main()
{
    Stack S; Init(S);
    int n, x;
    cin >> n;
    DecimaltoBinary2(n, S);
    printStack(S);
    return 0;
}




