class Solution {
public:
    
    bool visited[10][10] = {false};
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int m,n;
    bool isRange(int x, int y) {
        if(y < 0 || x < 0 || x >= m || y >= n) return false;
        return true;
    }
    bool func(vector<vector<char>>& board, string word, int wordIndex, int x, int y) {
        if(wordIndex == word.size() - 1) {
            return true;
        }
                
        for(int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(!isRange(nextX, nextY)) {
                continue;
            }
            if(visited[nextX][nextY]) continue;

            if(board[nextX][nextY] != word[wordIndex + 1]) continue;
            
            visited[nextX][nextY] = true;
            if(func(board, word, wordIndex + 1, nextX, nextY)) return true;
            visited[nextX][nextY] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] != word[0]) continue;
                visited[i][j] = true;
                if(func(board, word, 0, i, j)) return true;
                visited[i][j] = false;
            }
        }
        
        return false;
    }
};