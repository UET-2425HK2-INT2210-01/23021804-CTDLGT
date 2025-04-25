#include <iostream>
#include <algorithm>  // để dùng std::swap
using namespace std;


int partitionHoare(int arr[], int low, int high) {
    int pivot = arr[low];   // Chọn pivot là phần tử đầu vùng low
    int i = low - 1;        // i sẽ tăng dần từ low-1 lên
    int j = high + 1;       // j sẽ giảm dần từ high+1 xuống

    while (true) {
        // Tìm arr[i] đầu tiên sao cho arr[i] >= pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Tìm arr[j] đầu tiên sao cho arr[j] <= pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // Nếu hai con trỏ đã gặp hoặc vượt nhau, phân hoạch hoàn thành
        if (i >= j)
            return j;

        // Nếu chưa gặp nhau, hoán vị để đưa arr[i] về phần “< pivot” và arr[j] về phần “> pivot”
        swap(arr[i], arr[j]);
    }
}


void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        // Phân hoạch và lấy chỉ số pi
        int pi = partitionHoare(arr, low, high);
        // Đệ quy sắp vùng trái (low..pi)
        quickSortHoare(arr, low, pi);
        // Đệ quy sắp vùng phải (pi+1..high)
        quickSortHoare(arr, pi + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Đọc số lượng phần tử
    cin >> n;

    // Cấp phát mảng động
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Đọc từng phần tử
    }

    // Gọi QuickSort với phân hoạch Hoare
    quickSortHoare(arr, 0, n - 1);

    // In mảng đã sắp xếp, cách nhau một dấu cách
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';

    delete[] arr;  
    return 0;
}
