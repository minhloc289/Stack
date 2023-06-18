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

void Pop(Stack& S) {
    if (!isEmpty(S)) {
        S.n--;
    }

}

bool isValid(string expr) {
    Stack S;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            Push(S, i);
        }
        else if (expr[i] == ')') {
            if (isEmpty(S)) {
                return false;
            }
            Pop(S);
        }
    }
    return isEmpty(S);
}

int main()
{
    string expr; cin >> expr;
    cout << isValid(expr);

    return 0;
}
