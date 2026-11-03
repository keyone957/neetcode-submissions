class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int answer = 0;
        int dy[4] = { -1, 1, 0, 0 };
        int dx[4] = { 0, 0, -1, 1 };

        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (grid[y][x] == 0) {
                    continue;
                }

                queue<pair<int, int>> q;
                q.push({ y, x });

                int sum = grid[y][x];
                grid[y][x] = 0;

                while (!q.empty()) {
                    int curY = q.front().first;
                    int curX = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int nextY = curY + dy[i];
                        int nextX = curX + dx[i];

                        if (nextY < 0 || nextY >= rows ||
                            nextX < 0 || nextX >= cols) {
                            continue;
                        }

                        if (grid[nextY][nextX] == 0) {
                            continue;
                        }

                        sum += grid[nextY][nextX];
                        grid[nextY][nextX] = 0;
                        q.push({ nextY, nextX });
                    }
                }

                answer = max(answer, sum);
            }
        }

        return answer;
    }
};