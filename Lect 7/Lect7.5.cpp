#include <iostream>
#include <algorithm>   // <-- cho std::swap
#include <vector>
using namespace std;

// Đệ quy sinh hoán vị trong vector a, 
//   l = chỉ số bắt đầu cần “fix”, 
//   r = chỉ số cuối cùng
void generatePerm(vector<int> &a, int l, int r) {
    if (l == r) {
        // Base case: đã fix hết vị trí từ 0..r
        for (int x : a) 
            cout << x;
        cout << '\n';
        return;
    }
    // Thử đặt mỗi phần tử i vào vị trí l
    for (int i = l; i <= r; ++i) {
        swap(a[l], a[i]);               // hoán vị a[l] <-> a[i]
        generatePerm(a, l + 1, r);     // đệ quy fix tiếp vị trí l+1
        swap(a[l], a[i]);               // backtrack: đổi lại
    }
}

int main() {
    int n;
    cin >> n;
    if (n <= 0) return 0;  // không sinh hoán vị với n <= 0

    // Khởi tạo vector [1, 2, ..., n]
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;

    // Gọi hàm sinh hoán vị
    generatePerm(a, 0, n - 1);

    return 0;
}
