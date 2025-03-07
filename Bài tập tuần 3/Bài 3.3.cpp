#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int maxCapacity;
    int front;
    int rear;
    int size;

public:
    Queue(int capacity) {
        maxCapacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void push(int x) {
        if (size == maxCapacity) {
            return;
        }
        rear = (rear + 1) % maxCapacity;
        arr[rear] = x;
        size++;
    }

    void pop() {
        if (size == 0) {
            return;
        }
        front = (front + 1) % maxCapacity;
        size--;
    }

    void print() {
        if (size == 0) {
            return;
        }
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % maxCapacity;
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.push(5);
    q.print();
}


// BẮT ĐẦU

// HÀM KhoiTaoHangDoi(sucChua):
//     maxSucChua ← sucChua
//     Tạo một mảng 'arr' có kích thước 'sucChua'
//     dau ← 0
//     cuoi ← -1
//     kichThuoc ← 0
// KẾT THÚC HÀM

// HÀM ThemPhanTu(x):
//     NẾU kichThuoc = maxSucChua THÌ
//         IN "Hàng đợi đã đầy!"
//         TRẢ VỀ
//     KẾT THÚC NẾU
//     cuoi ← (cuoi + 1) MOD maxSucChua
//     arr[cuoi] ← x
//     kichThuoc ← kichThuoc + 1
// KẾT THÚC HÀM

// HÀM XoaPhanTu():
//     NẾU kichThuoc = 0 THÌ
//         IN "Hàng đợi rỗng!"
//         TRẢ VỀ
//     KẾT THÚC NẾU
//     dau ← (dau + 1) MOD maxSucChua
//     kichThuoc ← kichThuoc - 1
// KẾT THÚC HÀM

// HÀM InHangDoi():
//     NẾU kichThuoc = 0 THÌ
//         IN "Hàng đợi rỗng!"
//         TRẢ VỀ
//     KẾT THÚC NẾU
//     chiSo ← dau
//     LẶP i TỪ 0 ĐẾN kichThuoc - 1
//         IN arr[chiSo]
//         chiSo ← (chiSo + 1) MOD maxSucChua
//     KẾT THÚC LẶP
//     IN xuống dòng
// KẾT THÚC HÀM

// // CHƯƠNG TRÌNH CHÍNH
// BẮT ĐẦU
//     GỌI KhoiTaoHangDoi(5)
//     GỌI ThemPhanTu(1)
//     GỌI ThemPhanTu(2)
//     GỌI ThemPhanTu(3)
//     GỌI ThemPhanTu(4)
//     GỌI XoaPhanTu()
//     GỌI XoaPhanTu()
//     GỌI ThemPhanTu(5)
//     GỌI InHangDoi()  // Kết quả: 3 4 5
// KẾT THÚC

// Độ phức tạp O(n);
