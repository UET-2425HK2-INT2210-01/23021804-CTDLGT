#include <iostream>
using namespace std;

// Hàm đệ quy TongChuSo: tính tổng các chữ số của n
int TongChuSo(int n) {
    // Base case: nếu n chỉ còn 1 chữ số (0–9), trả về n
    if (n < 10)
        return n;
    // Recursive case: lấy chữ số cuối (n % 10) cộng với tổng
    // các chữ số của phần còn lại (n / 10)
    return (n % 10) + TongChuSo(n / 10);
}

int main() {
    int n;
    cout << "Nhập số nguyên dương n: ";
    cin >> n;

    // Kiểm tra đầu vào
    if (n < 0) {
        cout << "Lỗi: vui lòng nhập n >= 0" << endl;
        return 0;
    }

    // Gọi hàm đệ quy và in kết quả
    int ketQua = TongChuSo(n);
    cout << "Tổng các chữ số của " << n << " là " << ketQua << endl;
    return 0;
}
