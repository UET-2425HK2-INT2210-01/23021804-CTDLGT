#include <iostream>
using namespace std;

double bitleft(int n){
    double result;
    if (n>=0){
        result = 1 <<n;
    } else {
        result = 1 << -(n);
        result = 1/result;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    cout << bitleft(n);
    return 0;
}

// BẮT ĐẦU

// // Hàm tính toán dịch bit trái
// HÀM BITLEFT(n):
//     BIẾN result
//     NẾU n >= 0 THÌ
//         result ← 1 DỊCH TRÁI n lần  // 1 << n
//     NGƯỢC LẠI
//         result ← 1 DỊCH TRÁI (-n) lần  // 1 << -n
//         result ← 1 / result  // Lấy nghịch đảo
//     KẾT THÚC NẾU
//     TRẢ VỀ result
// KẾT THÚC HÀM

// // Chương trình chính
// BẮT ĐẦU
//     BIẾN n
//     NHẬP n
//     IN BITLEFT(n)
// KẾT THÚC


// Độ phức tạp: O(1)