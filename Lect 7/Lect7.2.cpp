#include <iostream>
using namespace std;

const int MAX = 100;  // Giả định ma trận không vượt quá 100×100

int main() {
    // 1) Đọc kích thước ma trận từ bàn phím (hoặc file)
    //    m = số hàng, n = số cột
    int m, n;
    cin >> m >> n;

    // 2) Đọc ma trận A[m][n]
    int A[MAX][MAX];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    // 3) Khởi tạo kết quả
    //    maxSum = tổng lớn nhất tìm được (khởi bằng phần tử đầu tiên để xử lý cả trường hợp toàn âm)
    int maxSum    = A[0][0];
    int final_r1  = 0, final_c1 = 0;  // toạ độ góc trên‑trái (0‑based)
    int final_r2  = 0, final_c2 = 0;  // toạ độ góc dưới‑phải (0‑based)

    // 4) Duyệt tất cả cặp hàng (r1 ≤ r2) để xác định "đỉnh trên" và "đỉnh dưới" của rectangle
    for (int r1 = 0; r1 < m; ++r1) {
        // temp[col] sẽ lưu tổng dồn từ hàng r1 đến r2 của mỗi cột col
        int temp[MAX] = {0};

        for (int r2 = r1; r2 < m; ++r2) {
            // Cộng dòng r2 vào mảng tạm temp
            for (int col = 0; col < n; ++col) {
                temp[col] += A[r2][col];
            }

            // 5) Áp dụng Kadane 1D lên temp để tìm đoạn cột liên tiếp có tổng lớn nhất
            //    sumHere  = tổng của đoạn hiện tại
            //    bestHere = tổng lớn nhất tìm được trên temp
            int sumHere   = temp[0];
            int bestHere  = temp[0];
            int startCol  = 0;  // đánh dấu cột bắt đầu của sumHere hiện tại
            int best_c1   = 0;  // cột bắt đầu của bestHere
            int best_c2   = 0;  // cột kết thúc của bestHere

            // Duyệt qua các cột 1..n‑1
            for (int col = 1; col < n; ++col) {
                // Nếu sumHere âm, khởi lại tại temp[col]
                if (sumHere < 0) {
                    sumHere  = temp[col];
                    startCol = col;
                } else {
                    sumHere += temp[col];
                }

                // Cập nhật bestHere nếu sumHere tốt hơn
                if (sumHere > bestHere) {
                    bestHere = sumHere;
                    best_c1  = startCol;
                    best_c2  = col;
                }
            }

            // 6) So sánh với maxSum toàn cục
            if (bestHere > maxSum) {
                maxSum   = bestHere;
                final_r1 = r1;
                final_r2 = r2;
                final_c1 = best_c1;
                final_c2 = best_c2;
            }
        }
    }

    // 7) In kết quả ra màn hình (hoặc ghi file)
    //    Đề bài yêu cầu indexing bắt đầu từ 1, nên mình +1 tất cả
    cout 
        << final_r1 + 1 << " "  // hàng trên
        << final_c1 + 1 << " "  // cột trái
        << final_r2 + 1 << " "  // hàng dưới
        << final_c2 + 1 << " "  // cột phải
        << maxSum               // tổng lớn nhất
        << endl;

    return 0;
}
