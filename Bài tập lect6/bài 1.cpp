#include <iostream>
using namespace std;

// Cấu trúc của một nút trong cây BST
struct Node {
    int val;       // Giá trị của nút
    Node* left;    // Con trỏ trỏ đến con trái
    Node* right;   // Con trỏ trỏ đến con phải

    // Hàm tạo cho nút, khởi tạo giá trị và gán con trỏ về nullptr
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Hàm chèn một nút mới vào cây BST theo quy tắc:
// Nếu giá trị nhỏ hơn nút hiện tại thì chèn vào bên trái, nếu lớn hơn thì chèn vào bên phải.
Node* insert(Node* root, int value) {
    // Nếu cây rỗng, tạo một nút mới và trả về nút đó
    if (root == nullptr)
        return new Node(value);
    
    // Nếu giá trị cần chèn nhỏ hơn giá trị của nút hiện tại, chèn vào bên trái
    if (value < root->val)
        root->left = insert(root->left, value);
    // Nếu giá trị cần chèn lớn hơn giá trị của nút hiện tại, chèn vào bên phải
    else if (value > root->val)
        root->right = insert(root->right, value);
    
    // Trả về nút hiện tại (cập nhật cây)
    return root;
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây con
// Dùng để tìm "inorder successor" khi xóa nút có hai con
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;  // Duyệt về bên trái cho đến khi không có nút bên trái
    return root;
}

// Hàm xóa một nút có giá trị xác định khỏi BST
// Xử lý các trường hợp: nút lá, nút có 1 con, và nút có 2 con.
Node* deleteNode(Node* root, int value) {
    // Nếu cây rỗng, trả về ngay
    if (root == nullptr)
        return root;
    
    // Nếu giá trị cần xóa nhỏ hơn giá trị của nút hiện tại,
    // tiếp tục tìm kiếm ở cây con bên trái.
    if (value < root->val) {
        root->left = deleteNode(root->left, value);
    }
    // Nếu giá trị cần xóa lớn hơn giá trị của nút hiện tại,
    // tiếp tục tìm kiếm ở cây con bên phải.
    else if (value > root->val) {
        root->right = deleteNode(root->right, value);
    }
    // Nếu tìm thấy nút cần xóa (value == root->val)
    else {
        // Trường hợp nút không có con (là nút lá)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;   // Giải phóng bộ nhớ
            return nullptr;
        }
        // Trường hợp nút có một con (chỉ có con phải)
        else if (root->left == nullptr) {
            Node* temp = root->right;  // Lưu lại nút con phải
            delete root;               // Xóa nút hiện tại
            return temp;               // Nối nút cha với nút con
        }
        // Trường hợp nút có một con (chỉ có con trái)
        else if (root->right == nullptr) {
            Node* temp = root->left;   // Lưu lại nút con trái
            delete root;               // Xóa nút hiện tại
            return temp;               // Nối nút cha với nút con
        }
        // Trường hợp nút có 2 con:
        // Tìm nút có giá trị nhỏ nhất trong cây con bên phải (inorder successor)
        Node* temp = findMin(root->right);
        // Thay thế giá trị của nút hiện tại bằng giá trị của nút tìm được
        root->val = temp->val;
        // Xóa nút có giá trị vừa được thay thế khỏi cây con bên phải
        root->right = deleteNode(root->right, temp->val);
    }
    // Trả về nút hiện tại sau khi đã xóa và cập nhật cây
    return root;
}

// Hàm duyệt cây theo thứ tự trung thứ tự (inorder traversal)
// Giúp in ra các giá trị của cây theo thứ tự tăng dần.
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);          // Duyệt cây con bên trái
    cout << root->val << " ";     // In giá trị của nút hiện tại
    inorder(root->right);         // Duyệt cây con bên phải
}

int main() {
    Node* root = nullptr;
    
    // 1. Chèn các phần tử ban đầu: 2, 1, 10, 6, 3, 8, 7, 13, 20
    int initialValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int value : initialValues) {
        root = insert(root, value); // Chèn từng giá trị vào BST
    }
    cout << "BST sau khi chèn ban đầu: ";
    inorder(root); // Duyệt và in cây theo thứ tự trung thứ tự
    cout << "\n";
    
    // 2. Chèn thêm các giá trị: 14, 0, 35
    int insertValues[] = {14, 0, 35};
    for (int value : insertValues) {
        root = insert(root, value); // Chèn từng giá trị mới vào BST
    }
    cout << "BST sau khi chèn 14, 0, 35: ";
    inorder(root); // Duyệt và in cây sau khi chèn thêm
    cout << "\n";
    
    // 3. Xóa các giá trị: 6, 13, 35 theo thứ tự
    int deleteValues[] = {6, 13, 35};
    for (int value : deleteValues) {
        root = deleteNode(root, value); // Xóa từng giá trị ra khỏi BST
    }
    cout << "BST sau khi xóa 6, 13, 35: ";
    inorder(root); // Duyệt và in cây sau khi xóa
    cout << "\n";
    
    return 0;
}
