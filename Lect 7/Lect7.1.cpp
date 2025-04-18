#include <iostream>
#include <vector>
using namespace std;

// Sắp xếp nổi bọt (tương tự selection nhưng swap ngay khi phát hiện)
void bubbleSort(vector<double>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}

int main() {
    vector<double> a;
    double x;
    // Đọc từ stdin (có thể redirect từ file)
    while (cin >> x) {
        a.push_back(x);
    }

    if (a.empty()) {
        cerr << "Không có số nào để sắp xếp!\n";
        return 1;
    }

    bubbleSort(a);

    // In kết quả, cách nhau một khoảng trắng
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
    }
    return 0;
}
