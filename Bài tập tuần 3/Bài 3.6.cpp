#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;

        if (top == NULL) top = newNode;
        else
        {
            Node* loop = top;
            while (loop->next != NULL) loop = loop->next;

            loop->next = newNode;
        }
        size++;
    }

    void pop() {
        if (top == NULL) {
            return;
        }
        Node* loop = top;
        for (int i = 1; i < size - 2; i++)
        {
            loop =  loop->next;
        }
        Node* trash = loop->next;
        loop->next = NULL;
        delete trash;
        size--;
    }

    void print() {
        if (top == NULL) {
            return;
        }
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
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

// // Định nghĩa cấu trúc Node
// CẤU TRÚC Node:
//     data  // Dữ liệu của nút
//     next  // Con trỏ trỏ đến nút tiếp theo
// KẾT THÚC CẤU TRÚC

// // Định nghĩa lớp Stack (Ngăn xếp)
// LỚP Stack:
//     BIẾN top  // Con trỏ đến phần tử đầu tiên của ngăn xếp
//     BIẾN size  // Số lượng phần tử trong ngăn xếp

//     // Khởi tạo ngăn xếp
//     HÀM KHỞI_TẠO():
//         top ← NULL
//         size ← 0
//     KẾT THÚC HÀM

//     // Thêm phần tử vào ngăn xếp
//     HÀM PUSH(x):
//         TẠO newNode
//         newNode.data ← x
//         newNode.next ← NULL

//         NẾU top = NULL THÌ
//             top ← newNode  // Nếu ngăn xếp rỗng, gán top = newNode
//         NGƯỢC LẠI
//             BIẾN loop ← top
//             TRONG KHI loop.next ≠ NULL THÌ
//                 loop ← loop.next  // Duyệt đến phần tử cuối cùng
//             KẾT THÚC TRONG KHI
//             loop.next ← newNode  // Thêm newNode vào cuối ngăn xếp
//         KẾT THÚC NẾU
//         size ← size + 1
//     KẾT THÚC HÀM

//     // Xóa phần tử trên cùng của ngăn xếp
//     HÀM POP():
//         NẾU top = NULL THÌ
//             TRẢ VỀ  // Ngăn xếp rỗng, không thể xóa
//         KẾT THÚC NẾU
//         BIẾN loop ← top
//         LẶP i TỪ 1 ĐẾN size - 2:
//             loop ← loop.next  // Duyệt đến phần tử áp chót
//         KẾT THÚC LẶP
//         BIẾN trash ← loop.next
//         loop.next ← NULL
//         XÓA trash
//         size ← size - 1
//     KẾT THÚC HÀM

//     // In các phần tử trong ngăn xếp
//     HÀM PRINT():
//         NẾU top = NULL THÌ
//             TRẢ VỀ  // Ngăn xếp rỗng, không có gì để in
//         KẾT THÚC NẾU
//         BIẾN current ← top
//         TRONG KHI current ≠ NULL THÌ
//             IN current.data
//             current ← current.next
//         KẾT THÚC TRONG KHI
//         IN xuống dòng
//     KẾT THÚC HÀM
// KẾT THÚC LỚP

// // Chương trình chính
// BẮT ĐẦU
//     TẠO ngăn xếp s
//     GỌI s.PUSH(1)
//     GỌI s.PUSH(2)
//     GỌI s.PUSH(3)
//     GỌI s.PUSH(4)
//     GỌI s.POP()
//     GỌI s.POP()
//     GỌI s.PUSH(5)
//     GỌI s.PRINT()  // Kết quả: 1 2 5
// KẾT THÚC

// Độ phức tạp O(n^2)