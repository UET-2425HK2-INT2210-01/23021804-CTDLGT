#include <bits/stdc++.h>
using namespace std;

// Định nghĩa số lượng đỉnh tối đa của cây. Nếu số đỉnh lớn hơn, hãy tăng giá trị này.
static const int MAXN = 100000;

// childrenList[i] chứa các nút là con trực tiếp của nút i (theo thứ tự nhập vào).
vector<int> childrenList[MAXN + 1];

// Nếu parentOf[i] = -1, nghĩa là nút i không có cha (nút gốc).
int parentOf[MAXN + 1];

// leftChild[i] lưu con trái của nút i, rightChild[i] lưu con phải của nút i.
int leftChild[MAXN + 1];
int rightChild[MAXN + 1];

// Biến cờ để đánh dấu nếu phát hiện có nút có hơn 2 con.
// Nếu có nút nào có số con > 2, cây đó không phải là cây nhị phân theo yêu cầu đề.
bool notBinary = false;


// Hàm getHeight: Tính chiều cao của cây theo số cạnh (edge) dài nhất từ nút hiện tại xuống lá.
 
int getHeight(int node) {
    if (node == -1) return -1;  // Nếu nút không tồn tại, trả về -1
    int hLeft = getHeight(leftChild[node]);    // Tính chiều cao của cây con trái
    int hRight = getHeight(rightChild[node]);    // Tính chiều cao của cây con phải
    return 1 + max(hLeft, hRight);  // Mỗi bước đi xuống từ nút hiện tại cộng thêm 1 cạnh
}

/*
 * Hàm preorder:
 * Duyệt cây theo thứ tự NLR (Node - Left - Right).
 * Thứ tự duyệt: xử lý nút hiện tại, sau đó duyệt cây con trái, tiếp theo duyệt cây con phải.
 * Kết quả duyệt được lưu vào vector 'res'.
 */
 
void preorder(int node, vector<int> &res) {
    if (node == -1) return;       // Nếu không còn nút nào để duyệt, dừng lại
    res.push_back(node);          // Xử lý nút hiện tại: thêm vào vector kết quả
    preorder(leftChild[node], res);   // Duyệt cây con trái
    preorder(rightChild[node], res);  // Duyệt cây con phải
}

void postorder(int node, vector<int> &res) {
    if (node == -1) return;       // Nếu nút không tồn tại, dừng lại
    postorder(leftChild[node], res);  // Duyệt cây con trái
    postorder(rightChild[node], res); // Duyệt cây con phải
    res.push_back(node);              // Xử lý nút hiện tại: thêm vào vector kết quả
}

/*
 * Hàm inorder:
 * Duyệt cây theo thứ tự LNR (Left - Node - Right).
 * Thứ tự duyệt: duyệt cây con trái, xử lý nút hiện tại, sau đó duyệt cây con phải.
 * Hàm này chỉ được sử dụng nếu cây được xác định là cây nhị phân.
 */
void inorder(int node, vector<int> &res) {
    if (node == -1) return;       // Nếu không còn nút để duyệt, kết thúc đệ quy
    inorder(leftChild[node], res);    // Duyệt cây con trái
    res.push_back(node);              // Xử lý nút hiện tại: thêm vào kết quả
    inorder(rightChild[node], res);   // Duyệt cây con phải
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    // Đọc số lượng nút (N) và số cạnh (M) từ đầu vào
    cin >> N >> M;

    // Khởi tạo các mảng cho mỗi nút từ 1 đến N
    for (int i = 1; i <= N; i++){
        parentOf[i] = -1;          // Ban đầu, chưa xác định cha nên gán là -1
        childrenList[i].clear();   // Danh sách con ban đầu rỗng
        leftChild[i] = -1;         // Chưa xác định con trái nên gán là -1
        rightChild[i] = -1;        // Chưa xác định con phải nên gán là -1
    }

    /*
     * Nhập M cạnh: mỗi cạnh có dạng (u, v) với u là cha của v.
     * - Thêm v vào danh sách con của u.
     * - Đánh dấu parentOf[v] = u, xác định cha của v.
     */
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        childrenList[u].push_back(v);
        parentOf[v] = u;
    }

    /*
     * Tìm nút gốc:
     * Gốc là nút không có cha (parentOf[i] = -1).
     * Chúng ta duyệt từ 1 đến N để tìm ra nút đầu tiên không có cha.
     */
    int root = -1;
    for (int i = 1; i <= N; i++){
        if (parentOf[i] == -1){
            root = i;
            break;
        }
    }

    /*
     * Xây dựng cấu trúc cây dưới dạng nhị phân:
     * Với mỗi nút, nếu số lượng con > 2 thì đánh dấu notBinary = true (không phải cây nhị phân).
     * Nếu số lượng con <= 2, ta gán lần lượt:
     * - leftChild[i] là con đầu tiên trong danh sách
     * - rightChild[i] là con thứ hai (nếu có)
     */
    for (int i = 1; i <= N; i++){
        int sz = (int)childrenList[i].size();
        if (sz > 2) {
            notBinary = true;  // Có nút với hơn 2 con => không phải cây nhị phân
        }
        if (sz >= 1) {
            leftChild[i] = childrenList[i][0];
        }
        if (sz >= 2) {
            rightChild[i] = childrenList[i][1];
        }
    }

    // Tính chiều cao của cây tính theo số cạnh (edge) bằng hàm getHeight.
    int h = getHeight(root);

    // Duyệt cây theo thứ tự preorder (NLR)
    vector<int> preRes;
    preorder(root, preRes);

    // Duyệt cây theo thứ tự postorder (LRN)
    vector<int> postRes;
    postorder(root, postRes);

    // Chiều cao của cây (số cạnh)
    cout << h << "\n";

    // Duyệt từng phần tử trong vector preRes và in ra cách nhau bằng dấu cách.
    for (int i = 0; i < (int)preRes.size(); i++){
        cout << preRes[i];
        if (i + 1 < (int)preRes.size())
            cout << " ";
    }
    cout << "\n";

    // Kết quả duyệt postorder.
    for (int i = 0; i < (int)postRes.size(); i++){
        cout << postRes[i];
        if (i + 1 < (int)postRes.size())
            cout << " ";
    }
    cout << "\n";

    // Nếu cây là nhị phân (không có nút nào có >2 con), in thứ tự duyệt inorder; ngược lại, in "NOT BINARY TREE".
    if (!notBinary) {
        vector<int> inRes;
        inorder(root, inRes);
        for (int i = 0; i < (int)inRes.size(); i++){
            cout << inRes[i];
            if (i + 1 < (int)inRes.size())
                cout << " ";
        }
        cout << "\n";
    } else {
        cout << "NOT BINARY TREE\n";
    }

    return 0;
}
