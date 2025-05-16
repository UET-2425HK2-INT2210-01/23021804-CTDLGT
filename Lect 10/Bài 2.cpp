#include <iostream>     // Thư viện nhập xuất chuẩn
#include <vector>       // Sử dụng vector cho danh sách kề
#include <queue>        // Sử dụng hàng đợi cho BFS

using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;  // Nhập số đỉnh, số cạnh, đỉnh bắt đầu và đỉnh kết thúc

    // Khởi tạo danh sách kề với n+1 phần tử (vì đỉnh bắt đầu từ 1 đến n)
    vector<vector<int>> adj(n + 1);

    // Mảng đánh dấu đỉnh đã được thăm hay chưa, khởi tạo tất cả là false
    vector<bool> visited(n + 1, false);

    // Mảng lưu khoảng cách ngắn nhất từ đỉnh X đến các đỉnh khác, khởi tạo là -1
    vector<int> distance(n + 1, -1);

    // Nhập m cạnh có hướng
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Thêm cạnh có hướng từ u đến v
    }

    // Khởi tạo BFS từ đỉnh X
    queue<int> q;
    q.push(X);              // Đưa đỉnh X vào hàng đợi
    visited[X] = true;      // Đánh dấu đã thăm đỉnh X
    distance[X] = 0;        // Khoảng cách từ X đến X là 0

    // Bắt đầu thuật toán BFS
    while (!q.empty()) {
        int u = q.front();  // Lấy đỉnh đầu hàng đợi
        q.pop();            // Loại bỏ đỉnh đầu khỏi hàng đợi

        // Duyệt các đỉnh kề với đỉnh u
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;             // Đánh dấu đã thăm đỉnh v
                distance[v] = distance[u] + 1; // Cập nhật khoảng cách từ X đến v
                q.push(v);                     // Đưa đỉnh v vào hàng đợi để duyệt tiếp
            }
        }
    }

    // In ra số cạnh của đường đi ngắn nhất từ X đến Y
    // Nếu không tìm được đường đi, distance[Y] sẽ vẫn là -1
    cout << distance[Y] << endl;

    return 0;
}
