#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int maxCapacity;
    int top;
    int size;

public:
    Stack(int capacity) {
        maxCapacity = capacity;
        arr = new int[capacity];
        top = -1;
        size = 0;
    }

    void push(int x) {
        if (top == maxCapacity - 1) {
            return;
        }
        top++;
        arr[top] = x;
        size++;
    }

    void pop() {
        if (top == -1) {
            return;
        }
        top--;
        size--;
    }

    void print() {
        if (top == -1) {
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.pop();
    s.push(5);
    s.print();
    return 0;
}


// BẮT ĐẦU

// // Định nghĩa lớp Stack (Ngăn xếp)
// LỚP Stack:
//     BIẾN arr  // Mảng động lưu dữ liệu
//     BIẾN maxCapacity  // Sức chứa tối đa của ngăn xếp
//     BIẾN top  // Chỉ số của phần tử trên cùng
//     BIẾN size  // Số lượng phần tử hiện tại

//     // Khởi tạo ngăn xếp
//     HÀM KHỞI_TẠO(capacity):
//         maxCapacity ← capacity
//         Tạo mảng arr có kích thước maxCapacity
//         top ← -1  // Ban đầu không có phần tử nào
//         size ← 0
//     KẾT THÚC HÀM

//     // Thêm phần tử vào ngăn xếp
//     HÀM PUSH(x):
//         NẾU top = maxCapacity - 1 THÌ
//             TRẢ VỀ  // Ngăn xếp đầy, không thêm được
//         KẾT THÚC NẾU
//         top ← top + 1
//         arr[top] ← x  // Đưa phần tử vào ngăn xếp
//         size ← size + 1
//     KẾT THÚC HÀM

//     // Xóa phần tử trên cùng của ngăn xếp
//     HÀM POP():
//         NẾU top = -1 THÌ
//             TRẢ VỀ  // Ngăn xếp rỗng, không thể xóa
//         KẾT THÚC NẾU
//         top ← top - 1  // Giảm top đi 1
//         size ← size - 1
//     KẾT THÚC HÀM

//     // In các phần tử trong ngăn xếp
//     HÀM PRINT():
//         NẾU top = -1 THÌ
//             TRẢ VỀ  // Ngăn xếp rỗng, không có gì để in
//         KẾT THÚC NẾU
//         LẶP i TỪ 0 ĐẾN top:
//             IN arr[i]
//         KẾT THÚC LẶP
//         IN xuống dòng
//     KẾT THÚC HÀM
// KẾT THÚC LỚP

// // Chương trình chính
// BẮT ĐẦU
//     TẠO ngăn xếp s với sức chứa 5
//     GỌI s.PUSH(1)
//     GỌI s.PUSH(2)
//     GỌI s.PUSH(3)
//     GỌI s.PUSH(4)
//     GỌI s.POP()
//     GỌI s.POP()
//     GỌI s.PUSH(5)
//     GỌI s.PRINT()  // Kết quả: 1 2 5
// KẾT THÚC

// Độ phức tập O(n)
