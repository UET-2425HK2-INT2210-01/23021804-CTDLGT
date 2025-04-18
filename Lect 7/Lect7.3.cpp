#include <iostream>
#include <cmath>    // để dùng abs(), nếu bạn muốn xử lý số âm

using namespace std;

// Hàm đệ quy tính UCLN (gcd) của hai số x và y
int gcd(int x, int y) {
    // Chuẩn hóa: chuyển về số không âm (tuỳ chọn, đề bài không bắt buộc)
    x = abs(x);
    y = abs(y);

    // Base case: nếu y == 0 thì UCLN là x
    if (y == 0)
        return x;

    // Recursive case: theo định luật Euclid
    // gcd(x, y) = gcd(y, x % y)
    return gcd(y, x % y);
}

int main() {
    int X, Y;
    // 1) Nhập hai số nguyên X và Y từ bàn phím
    cin >> X >> Y;

    // 2) Gọi hàm đệ quy và in kết quả ra màn hình
    cout << gcd(X, Y) << endl;

    return 0;
}
