#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParenthesisHelper(int open, int close, string current, vector<string>& result) {
    // Nếu đã sử dụng đủ số lượng mở và đóng ngoặc
    if (open == 0 && close == 0) {
        result.push_back(current);
        return;
    }

    // Nếu còn ngoặc mở để thêm vào
    if (open > 0) {
        generateParenthesisHelper(open - 1, close, current + "(", result);
    }

    // Nếu số ngoặc đóng lớn hơn số ngoặc mở, ta có thể thêm ngoặc đóng
    if (close > open) {
        generateParenthesisHelper(open, close - 1, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisHelper(n / 2, n / 2, "", result);
    return result;
}

int main() {
    int n;
    cout << "Nhập số ký tự n: ";
    cin >> n;

    // Kiểm tra nếu n là số chẵn
    if (n % 2 != 0) {
        cout << "n phải là số chẵn để tạo ra biểu thức ngoặc đúng." << endl;
        return 1;
    }

    vector<string> result = generateParenthesis(n);
    cout << endl << result.size() << endl;
    cout << "Các biểu thức ngoặc đúng có " << n << " ký tự là:" << endl;
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
