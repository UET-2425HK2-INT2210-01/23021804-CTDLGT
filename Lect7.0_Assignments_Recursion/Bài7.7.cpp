#include <iostream>
using namespace std;

void Innguoc(int n) {
    if (n == 0) {
        cout << 0;      // In 0 nếu ban đầu n == 0
        return;
    }
    // Khi n > 0, cứ in chữ số cuối rồi đệ quy
    cout << n % 10;
    if (n / 10 != 0)
        Innguoc(n / 10);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n < 0) {
        cout << "Loi: n phai la so nguyen khong am" << endl;
        return 0;
    }

    cout << "Kq: ";
    Innguoc(n);
    cout << endl;      // Xuong dong sau khi in xong
    return 0;
}
