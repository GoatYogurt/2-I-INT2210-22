#include <iostream>

using namespace std;

int main() {
    int W, N;
    cin >> W >> N;
    int w[N], v[N];
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    int dp[N + 1][W + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (w[i - 1] <= j) { // trường hợp đồ vât thứ i có khối lượng nhỏ hơn j, lựa chọn phương án tốt nhất bằng cách lấy max
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];  // đồ vật thứ i có khối lượng lớn hơn j, không thể chọn đồ vật này
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}
