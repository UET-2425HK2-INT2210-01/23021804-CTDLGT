#include <iostream>
using namespace std;

// Hàm đệ quy Tong: tính tổng các số từ 1 đến n
int Tong(int n) {
    // Base case: nếu n <= 1, không cần gọi đệ quy nữa
    // - n == 1 trả về 1 (tổng 1)
    // - n == 0 trả về 0 (tổng rỗng)
    if (n <= 1)
        return n;

    // Recursive case: chia bài toán lớn thành n + Tong(n-1)
    return n + Tong(n - 1);
}

int main() {
    int n;
    cout << "Nhập n: ";
    cin >> n;

    // Kiểm tra đầu vào: không chấp nhận số âm
    if (n < 0) {
        cout << "Vui lòng nhập n >= 0" << endl;
        return 0;
    }

    // Gọi hàm đệ quy để tính tổng
    int ketqua = Tong(n);
    cout << "Tổng từ 1 đến " << n << " là " << ketqua << endl;
    return 0;
}
