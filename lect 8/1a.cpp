#include <iostream>
#include <algorithm>  // để dùng std::swap
using namespace std;


int partitionLomuto(int arr[], int low, int high) {
    int pivot = arr[high];     // Chọn pivot là phần tử cuối cùng
    int i = low - 1;           // i sẽ chạy và đánh dấu vùng các phần tử < pivot

    // Duyệt j từ low đến high-1
    for (int j = low; j < high; ++j) {
        // Nếu arr[j] nhỏ hơn pivot, mở rộng vùng < pivot
        if (arr[j] < pivot) {
            ++i;               // tăng chỉ số vùng nhỏ hơn
            swap(arr[i], arr[j]);  // đưa arr[j] vào vùng < pivot
        }
    }

    // Đưa pivot về đúng vị trí ngay sau vùng < pivot
    swap(arr[i + 1], arr[high]);
    return i + 1;  // trả về chỉ số của pivot
}


void quickSortLomuto(int arr[], int low, int high) {
    if (low < high) {
        // Phân hoạch, lấy vị trí pivot
        int pi = partitionLomuto(arr, low, high);
        // Đệ quy sắp trái của pivot
        quickSortLomuto(arr, low, pi - 1);
        // Đệ quy sắp phải của pivot
        quickSortLomuto(arr, pi + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Đọc số lượng phần tử
    cin >> n;

    // Cấp phát mảng động để chứa n số nguyên
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Đọc từng phần tử
    }

    // Gọi Quick Sort trên toàn mảng
    quickSortLomuto(arr, 0, n - 1);

    
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';

    delete[] arr; 
    return 0;
}
