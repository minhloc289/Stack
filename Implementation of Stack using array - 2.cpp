
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int t; // t là chỉ số của phần tử cuối mảng, tức là đỉnh stack
};
void Init(Stack& S)
{
    S.t = -1; //Khi stack chưa có phần tử nào thì top được khởi tạo là -1,
    // nếu khởi tạo t = 0 là SAI vì khi đó sẽ hiểu top tại a[0]
}

int isEmpty(Stack S) {
    return S.t == -1;
}

int isFull(Stack S) {
    return S.t == MAX - 1;
}



void Push(Stack& S, int x) {
    if (isFull(S)) {
        return;
    }
    S.arr[++S.t] = x;
}

void Pop(Stack& S) {
    if (isEmpty(S)){
        return;
    }
    S.t--;
}

int Top(Stack& S) {
    if (isEmpty(S)) {
        return -1;
    }
    return S.arr[S.t];
}

void printStack(Stack S) {
    if (!isEmpty(S)) {
        for (int i = 0; i <= S.t ; i++) {
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





