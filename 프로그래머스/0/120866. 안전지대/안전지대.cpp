#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int cnt = 1, n = board.size(), dx[] = {0,0,1,-1,1,1,-1,-1}, dy[] = {-1,1,0,0,-1,1,-1,1};

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j] == 1)
                cnt = 0;
            else
            for (int k = 0; k < 8; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    if (board[nx][ny] == 1)
                    {
                        cnt = 0;
                        break;
                    }
                }
            }
            answer += cnt;
            cnt = 1;
        }
    }

    return answer;
}