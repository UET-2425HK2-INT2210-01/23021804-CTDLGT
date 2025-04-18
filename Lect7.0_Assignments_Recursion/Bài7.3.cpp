#include <iostream>
using namespace std;

// Hàm đệ quy tính F(n)

int Fibonacci(int n) {
    // Base case 1: nếu n = 0, trả về 0
    if (n == 0)
        return 0;
    // Base case 2: nếu n = 1, trả về 1
    if (n == 1)
        return 1;
    // Recursive case: gọi hàm chính nó với n-1 và n-2
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Nhập n (n >= 0): ";
    cin >> n;

    // Kiểm tra đầu vào: không cho phép n âm
    if (n < 0) {
        cout << "Lỗi: vui lòng nhập n >= 0" << endl;
        return 0;
    }

    // Gọi hàm đệ quy tính F(n)
    int result = Fibonacci(n);

    cout << "F(" << n << ") = " << result << endl;

    return 0;
}
