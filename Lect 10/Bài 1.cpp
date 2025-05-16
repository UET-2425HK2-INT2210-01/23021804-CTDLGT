#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;       // Danh sách kề để biểu diễn đồ thị
vector<bool> visited;          // Mảng đánh dấu các đỉnh đã được thăm

// Hàm DFS: Duyệt toàn bộ các đỉnh trong một thành phần liên thông bắt đầu từ đỉnh u
void dfs(int u) {
    visited[u] = true;         // Đánh dấu đỉnh u đã được thăm
    for (int v : adj[u]) {     // Duyệt qua tất cả đỉnh kề với u
        if (!visited[v]) {
            dfs(v);            // Đệ quy DFS cho đỉnh kề chưa được thăm
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;             // Nhập số lượng đỉnh (n) và cạnh (m)

    adj.resize(n + 1);         // Khởi tạo danh sách kề (đánh số từ 1 đến n)
    visited.resize(n + 1, false); // Khởi tạo mảng visited với giá trị false

    // Nhập m cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;         // Nhập cạnh nối giữa x và y
        adj[x].push_back(y);   // Thêm y vào danh sách kề của x
        adj[y].push_back(x);   // Thêm x vào danh sách kề của y (vì đồ thị vô hướng)
    }

    int count = 0;             // Biến đếm số lượng thành phần liên thông

    // Duyệt qua tất cả các đỉnh
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {     // Nếu đỉnh i chưa được thăm
            dfs(i);            // Thực hiện DFS từ đỉnh đó
            count++;           // Tăng số lượng thành phần liên thông lên
        }
    }

    cout << count << endl;     // In ra số lượng thành phần liên thông

    return 0;
}
