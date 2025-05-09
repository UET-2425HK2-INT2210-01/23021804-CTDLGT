#include <iostream>
#include <vector>
using namespace std;

// Hàm đệ quy kiểm tra xem có tồn tại tập con nào có tổng bằng target không
bool isSubsetSum(const vector<int>& arr, int n, int target) {
    // Trường hợp cơ sở: nếu tổng cần tìm là 0 => luôn có tập rỗng thỏa mãn
    if (target == 0) return true;
    // Nếu không còn phần tử nào mà tổng vẫn khác 0 => không thể
    if (n == 0) return false;

    // Nếu phần tử cuối lớn hơn tổng cần tìm, bỏ qua phần tử này
    if (arr[n - 1] > target)
        return isSubsetSum(arr, n - 1, target);

    // Gọi đệ quy: 
    // - Không chọn phần tử hiện tại
    // - Hoặc chọn phần tử hiện tại (giảm tổng đi arr[n - 1])
    return isSubsetSum(arr, n - 1, target) ||
           isSubsetSum(arr, n - 1, target - arr[n - 1]);
}

int main() {
    int n, X;
    // Đọc số lượng phần tử và giá trị X
    cin >> n >> X;
    vector<int> A(n);

    // Đọc mảng các số tự nhiên (tuổi của học sinh)
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Kiểm tra xem có tập con nào thỏa mãn không và in kết quả
    if (isSubsetSum(A, n, X))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
