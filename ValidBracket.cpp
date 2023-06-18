#include <iostream>
#include <string>
#include <stack>
using namespace std;

void Valid() {
	string s;
	cin >> s;
	stack<char> st;
	for (auto x : s) {
		if (x == '(') {
			st.push(x);
		}
		else {
			if (st.empty()) {
				cout << "INVALID";
				return;
			}
			else {
				st.pop();
			}
		}
	}
	if (st.empty()) {
		cout << "VALID";
	}
	else {
		cout << "INVALID";
	}
}

int main() {
	int n; cin >> n;
	while (n--) {
		Valid();
	}
}