#include <iostream>
using namespace std;

// Hàm đệ quy DemChuSo: đếm số chữ số của n
int DemChuSo(int n) {
    // Base case: khi n còn 1 chữ số (0–9) thì dừng, trả về 1
    if (n < 10)
        return 1;
    // Recursive case: loại bỏ chữ số cuối (n/10), cộng 1, rồi đệ quy tiếp
    return 1 + DemChuSo(n / 10);
}

int main() {
    int n;
    // Nhập vào số nguyên n
    cout << "Nhập số nguyên dương n: ";
    cin >> n;

    // Kiểm tra đầu vào
    if (n < 0) {
        cout << "Lỗi: vui lòng nhập n >= 0" << endl;
        return 0;
    }
    // Trường hợp đặc biệt: 0 có 1 chữ số
    if (n == 0) {
        cout << "Số 0 có 1 chữ số" << endl;
        return 0;
    }

    // Gọi hàm đệ quy và in kết quả
    int kq = DemChuSo(n);
    cout << "Số " << n << " có " << kq << " chữ số" << endl;
    return 0;
}
