#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // Đọc số lượng đồ vật và trọng lượng tối đa

    vector<int> weight(n), value(n);

    // Nhập trọng lượng và giá trị từng đồ vật
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    // Tạo bảng dp[n+1][X+1], khởi tạo toàn bộ = 0
    // dp[i][j] = giá trị lớn nhất có thể khi xét i đồ vật đầu, với trọng lượng tối đa là j
    vector<vector<int>> dp(n + 1, vector<int>(X + 1, 0));

    // Bắt đầu điền bảng dp
    for (int i = 1; i <= n; ++i) { // Xét từng đồ vật
        for (int j = 0; j <= X; ++j) { // Xét từng mức trọng lượng từ 0 đến X
            if (weight[i - 1] <= j) {
                // Có thể chọn đồ vật i-1 (vì mảng bắt đầu từ 0)
                // So sánh giữa không lấy và lấy nó
                dp[i][j] = max(dp[i - 1][j],               // Không chọn đồ vật i
                               dp[i - 1][j - weight[i - 1]] + value[i - 1]); // Chọn đồ vật i
            } else {
                // Không thể chọn đồ vật i-1 vì quá nặng
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Kết quả cuối cùng: xét tất cả đồ vật và trọng lượng tối đa X
    cout << dp[n][X] << endl;

    return 0;
}
