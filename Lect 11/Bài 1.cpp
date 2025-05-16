#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

// Sử dụng giá trị vô cực để biểu thị "không có đường đi"
const int INF = INT_MAX;

int main() {
    // Mở file đầu vào (chứa thông tin bản đồ các thành phố và độ bẩn của đường đi)
    ifstream fin("dirty.txt");

    // Mở file đầu ra để ghi kết quả
    ofstream fout("dirty.out");

    int n, m, s, e; // n: số thành phố, m: số đường, s: điểm xuất phát, e: điểm đích
    fin >> n >> m >> s >> e;

    // Tạo ma trận khoảng cách (dist), ban đầu gán INF cho mọi cặp (i, j)
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Ma trận next lưu đỉnh tiếp theo trên đường đi ngắn nhất từ i đến j
    // Giúp truy vết đường đi sau khi chạy Floyd-Warshall
    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));

    // Đọc m cạnh từ file (mỗi cạnh có: u v d nghĩa là đường từ u đến v có độ bẩn d)
    for (int i = 0; i < m; i++) {
        int u, v, d;
        fin >> u >> v >> d;

        // Gán độ bẩn từ u đến v là d
        dist[u][v] = d;

        // Ghi nhớ rằng đi từ u đến v thì bước tiếp theo là v
        next[u][v] = v;
    }

    // Đặt độ bẩn từ 1 đỉnh đến chính nó là 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    // ---------- Thuật toán Floyd-Warshall bắt đầu ----------
    // Duyệt qua mọi đỉnh trung gian k
    for (int k = 1; k <= n; k++) {
        // Duyệt qua mọi cặp đỉnh i, j
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // Nếu i → k và k → j đều có đường đi
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    // Nếu đường đi i → k → j tốt hơn đường hiện tại i → j
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];     // Cập nhật độ bẩn
                        next[i][j] = next[i][k];                 // Ghi lại bước tiếp theo
                    }
                }
            }
        }
    }
    // ---------- Kết thúc Floyd-Warshall ----------

    // --- Ghi kết quả đường đi từ s đến e ---
    if (dist[s][e] == INF) {
        fout << "INF" << endl;        // Không có đường đi
    } else {
        fout << dist[s][e] << endl;   // Độ bẩn nhỏ nhất từ s đến e
    }

    // --- Truy vết và ghi đường đi từ s đến e ---
    if (next[s][e] == -1) {
        fout << "No path" << endl;    // Không có đường
    } else {
        vector<int> path;             // Lưu các đỉnh trên đường đi
        int current = s;

        // Từ s, đi theo đỉnh tiếp theo được lưu trong ma trận next
        while (current != e) {
            path.push_back(current); // Thêm đỉnh hiện tại vào danh sách đường đi
            current = next[current][e];
            if (current == -1) break; // Không có đường tiếp theo
        }

        path.push_back(e); // Thêm đỉnh đích

        // Ghi các đỉnh trên đường đi ra file
        for (int i = 0; i < path.size(); i++) {
            fout << path[i];
            if (i != path.size() - 1) fout << " ";
        }
        fout << endl;
    }

    // --- Ghi ma trận khoảng cách ngắn nhất giữa mọi cặp đỉnh ---
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF)
                fout << "INF"; // Không có đường đi
            else
                fout << dist[i][j]; // Độ bẩn nhỏ nhất từ i đến j

            if (j != n) fout << " ";
        }
        fout << endl;
    }

    return 0;
}
