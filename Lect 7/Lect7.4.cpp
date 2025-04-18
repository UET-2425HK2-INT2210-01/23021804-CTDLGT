#include <iostream>
#include <string>   // Cho phép dùng std::string

using namespace std;

// Hàm đệ quy sinh tất cả chuỗi nhị phân độ dài n
// - n: độ dài cần sinh
// - s: chuỗi đang xây dựng
void generateBinary(int n, const string &s) {
    // Base case: nếu độ dài chuỗi đã đạt n, in ra và dừng nhánh
    if ((int)s.length() == n) {
        cout << s << '\n';
        return;
    }
    // Thêm '0' vào chuỗi và gọi tiếp
    generateBinary(n, s + '0');
    // Thêm '1' vào chuỗi và gọi tiếp
    generateBinary(n, s + '1');
}

int main() {
    int n;
    // Nhập độ dài n từ bàn phím
    cin >> n;

    // Nếu cần, có thể kiểm tra điều kiện n >= 1
    // if (n <= 0) return 0;

    // Bắt đầu sinh với chuỗi rỗng
    generateBinary(n, "");

    return 0;
}
