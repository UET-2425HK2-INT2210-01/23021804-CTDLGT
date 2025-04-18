#include <iostream>
using namespace std;

// Hàm đệ quy tính n!
// - Base case: n <= 1 thì trả về 1 (0! = 1, 1! = 1)
// - Recursive case: n! = n * (n-1)!
unsigned long long TinhGiaiThua(int n) {
    if (n <= 1)
        return 1ULL;
    return (unsigned long long)n * TinhGiaiThua(n - 1);
}

int main() {
    int n;
    cout << "Nhập n (n >= 0): ";
    cin >> n;

    if (n < 0) {
        cout << "Lỗi: vui lòng nhập số nguyên không âm!" << endl;
        return 0;
    }

    // Tính giai thừa và in kết quả
    unsigned long long ketQua = TinhGiaiThua(n);
    cout << n << "! = " << ketQua << endl;
    return 0;
}
