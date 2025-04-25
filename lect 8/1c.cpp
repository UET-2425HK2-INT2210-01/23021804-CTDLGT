#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right) {
    // Kích thước của hai mảng con
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo hai mảng tạm để chứa dữ liệu hai nửa
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy dữ liệu từ arr vào hai mảng tạm
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Chỉ số duyệt mảng tạm và mảng chính
    int i = 0;      // chỉ số cho L[]
    int j = 0;      // chỉ số cho R[]
    int k = left;   // chỉ số cho arr[]

    // Trộn hai mảng con vào arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Nếu còn phần tử thừa trong L[], copy hết vào arr
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Nếu còn phần tử thừa trong R[], copy hết vào arr
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    // Giải phóng bộ nhớ mảng tạm
    delete[] L;
    delete[] R;
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Tính chỉ số giữa (tránh tràn số)
        int mid = left + (right - left) / 2;

        // Sắp xếp nửa trái
        mergeSort(arr, left, mid);

        // Sắp xếp nửa phải
        mergeSort(arr, mid + 1, right);

        // Trộn hai nửa đã sắp
        merge(arr, left, mid, right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Đọc số lượng phần tử
    cin >> n;

    // Cấp phát mảng động chứa n phần tử
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Đọc từng phần tử
    }

    // Gọi Merge Sort trên toàn mảng
    mergeSort(arr, 0, n - 1);

    // In mảng đã sắp xếp (cách nhau một dấu cách)
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i + 1 < n ? ' ' : '\n');
    }

    delete[] arr;
    return 0;
}
