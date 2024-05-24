#include <bits/stdc++.h>
using namespace std;
/*

Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây đủ hay không (full binary tree)? Một cây nhị phân được gọi là cây đủ nếu tất cả các node trung gian của nó đều có hai node con.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

Output

2
4
1 2 L 1 3 R 2 4 L 2 5 R
3
1 2 L 1 3 R 2 4 L

YES
NO
*/
class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node (int data) {
		this->data = data;
		this->left = this->right;
	}
};
void buildTree(Node *root, int u, int v, char x) {
	if (root != NULL) {
		if (root->data == u) {
			if (x == 'L') {
				root->left = new Node(v);
			} else {
				root->right = new Node(v);
			}
			

		} else {
			buildTree(root->left, u, v, x);
			buildTree(root->right, u, v, x);
		}
	}
}
void checkTree(Node *root, bool &check) {
	if (root != NULL) {
		if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
			check = false;
			return;
		}
		checkTree(root->left, check);
		checkTree(root->right, check);
	}
}
bool isCompleteTree(Node *root) {
	bool check = true;
	checkTree(root, check);
	return check;
}
void testCase() {
	int n;
	cin >> n;
	int u, v;
	char x;
	cin >> u >> v >> x;
	Node *root = new Node(u);
	buildTree(root, u, v, x);
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> x;
		buildTree(root, u, v, x);
	}
	if (isCompleteTree(root)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while (t--) {
		testCase();
		cout << endl;
	}
}