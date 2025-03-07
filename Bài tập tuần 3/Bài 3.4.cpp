#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* head;
    int size;

public:
    Queue() {
        head = NULL;
        size = 0;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* loop = head;
            while (loop->next != NULL) {
                loop = loop->next;
            }
            loop->next = newNode;
        }
        size++;
    }

    void pop() {
        if (head != NULL) {
            Node* trash = head;
            head = head->next;
            delete trash;
            size--;
        }
    }

    void print() {
        Node* loop = head;
        while (loop != NULL) {
            cout << loop->data << " ";
            loop = loop->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.push(5);
    q.print();
    return 0;
}


// BẮT ĐẦU

// // Định nghĩa cấu trúc Node
// CẤU TRÚC Node:
//     data  // Dữ liệu của nút
//     next  // Con trỏ trỏ đến nút tiếp theo
// KẾT THÚC CẤU TRÚC

// // Định nghĩa lớp Queue (Hàng đợi)
// LỚP Queue:
//     BIẾN head  // Con trỏ đầu hàng đợi
//     BIẾN size  // Kích thước hàng đợi

//     // Khởi tạo hàng đợi
//     HÀM KHỞI_TẠO():
//         head ← NULL
//         size ← 0
//     KẾT THÚC HÀM

//     // Thêm phần tử vào cuối hàng đợi
//     HÀM PUSH(x):
//         TẠO newNode
//         newNode.data ← x
//         newNode.next ← NULL

//         NẾU head = NULL THÌ
//             head ← newNode  // Nếu hàng đợi rỗng, gán head = newNode
//         NGƯỢC LẠI
//             BIẾN loop ← head
//             TRONG KHI loop.next ≠ NULL THÌ
//                 loop ← loop.next  // Duyệt đến phần tử cuối cùng
//             KẾT THÚC TRONG KHI
//             loop.next ← newNode  // Thêm newNode vào cuối hàng đợi
//         KẾT THÚC NẾU
//         size ← size + 1
//     KẾT THÚC HÀM

//     // Xóa phần tử đầu tiên trong hàng đợi
//     HÀM POP():
//         NẾU head ≠ NULL THÌ
//             BIẾN trash ← head
//             head ← head.next  // Cập nhật head lên phần tử tiếp theo
//             XÓA trash
//             size ← size - 1
//         KẾT THÚC NẾU
//     KẾT THÚC HÀM

//     // In hàng đợi
//     HÀM PRINT():
//         BIẾN loop ← head
//         TRONG KHI loop ≠ NULL THÌ
//             IN loop.data
//             loop ← loop.next  // Duyệt sang phần tử tiếp theo
//         KẾT THÚC TRONG KHI
//         IN xuống dòng
//     KẾT THÚC HÀM
// KẾT THÚC LỚP

// // Chương trình chính
// BẮT ĐẦU
//     TẠO hàng đợi q
//     GỌI q.PUSH(1)
//     GỌI q.PUSH(2)
//     GỌI q.PUSH(3)
//     GỌI q.PUSH(4)
//     GỌI q.POP()
//     GỌI q.POP()
//     GỌI q.PUSH(5)
//     GỌI q.PRINT()  // Kết quả: 3 4 5
// KẾT THÚC

// Độ phức tạp là O(n^2)