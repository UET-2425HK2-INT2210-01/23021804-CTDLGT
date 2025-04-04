#include <iostream>
using namespace std;

// Cấu trúc nút của cây BST
struct Node {
    int val;       // Giá trị của nút
    Node* left;    // Con trỏ đến cây con bên trái
    Node* right;   // Con trỏ đến cây con bên phải

    // Hàm tạo cho nút, khởi tạo giá trị và đặt con trỏ về nullptr
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Hàm chèn một giá trị mới vào BST
// Quy tắc: Nếu giá trị cần chèn < nút hiện tại -> chèn vào bên trái,
//          Nếu giá trị cần chèn > nút hiện tại -> chèn vào bên phải.
Node* insert(Node* root, int value) {
    // Nếu cây rỗng, tạo nút mới và trả về nút đó
    if (root == nullptr)
        return new Node(value);

    // Nếu giá trị cần chèn nhỏ hơn giá trị của nút hiện tại,
    // chèn vào cây con bên trái.
    if (value < root->val)
        root->left = insert(root->left, value);
    // Nếu giá trị cần chèn lớn hơn giá trị của nút hiện tại,
    // chèn vào cây con bên phải.
    else if (value > root->val)
        root->right = insert(root->right, value);

    // Trả về nút gốc (cập nhật cây)
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

// Hàm tìm nút có giá trị nhỏ nhất trong cây con
// Dùng cho việc tìm "inorder successor" khi xóa nút có 2 con.
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;  // Duyệt về bên trái cho đến khi không còn nút bên trái
    return root;
}

// Hàm xóa một nút khỏi BST theo giá trị cho trước
// Xử lý 3 trường hợp: nút lá, nút có 1 con và nút có 2 con.
Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return root;

    // Nếu giá trị cần xóa nhỏ hơn giá trị của nút hiện tại, duyệt sang cây con bên trái.
    if (value < root->val)
        root->left = deleteNode(root->left, value);
    // Nếu giá trị cần xóa lớn hơn giá trị của nút hiện tại, duyệt sang cây con bên phải.
    else if (value > root->val)
        root->right = deleteNode(root->right, value);
    else {
        // Nếu tìm thấy nút cần xóa:
        // Trường hợp nút lá (không có con)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Trường hợp nút có 1 con (chỉ có con phải)
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Trường hợp nút có 1 con (chỉ có con trái)
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Trường hợp nút có 2 con:
        // Tìm nút nhỏ nhất ở cây con bên phải (inorder successor)
        Node* temp = findMin(root->right);
        // Thay thế giá trị của nút cần xóa bằng giá trị của nút tìm được
        root->val = temp->val;
        // Xóa nút vừa chuyển giá trị ở cây con bên phải
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main() {
    Node* root = nullptr;

    // 1. Chèn các phần tử ban đầu vào BST: 2, 1, 10, 6, 3, 8, 7, 13, 20
    int initialValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int value : initialValues) {
        root = insert(root, value);
    }
    cout << "Cay BST sau khi chen ban dau: ";
    inorder(root);
    cout << "\n";

    // 2. Chèn thêm các giá trị: 14, 0, 35
    int insertValues[] = {14, 0, 35};
    for (int value : insertValues) {
        root = insert(root, value);
    }
    cout << "Cay BST sau khi chen 14, 0, 35: ";
    inorder(root);
    cout << "\n";

    // 3. Xóa các giá trị: 6, 13, 35 (theo thứ tự)
    int deleteValues[] = {6, 13, 35};
    for (int value : deleteValues) {
        root = deleteNode(root, value);
    }
    cout << "Cay BST sau khi xoa 6, 13, 35: ";
    inorder(root);
    cout << "\n";

    return 0;
}
