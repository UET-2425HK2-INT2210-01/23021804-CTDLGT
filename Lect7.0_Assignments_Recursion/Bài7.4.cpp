#include <iostream>
using namespace std;

// Hàm đệ quy tính x^n (với n >= 0)
long long Tinhluythua(int x, int n) {
    // Base case: n = 0 → x^0 = 1
    if (n == 0)
        return 1LL;
    // Base case: x = 0 và n > 0 → 0^n = 0
    if (x == 0)
        return 0LL;
    // Recursive case
    return (long long)x * Tinhluythua(x, n - 1);
}

int main() {
    int x, n;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap n (n >= 0): ";
    cin >> n;

    if (n < 0) {
        cout << "Loi: n phai >= 0" << endl;
        return 0;
    }

    long long Kq = Tinhluythua(x, n);
    cout << x << "^" << n << " = " << Kq << endl;
    return 0;
}
