class Solution {
public:
    int m,n;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m=board.size();
        n=board[0].size();
        int r=click[0],c=click[1];
        if(board[r][c]=='M'){
            board[r][c]='X';
            return board;
        }
        dfs(board,r,c);
        return board;
    }
    void dfs(vector<vector<char>>&board,int r,int c){
        if(r<0 || r>=m || c<0 || c>=n || board[r][c]!='E')
        return;
        vector<int>dr={1,-1,0,0,1,1,-1,-1};
        vector<int>dc={0,0,1,-1,1,-1,1,-1};
        int minecount=0;
        for(int i=0;i<8;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr>=0 && nr <m && nc >=0 && nc<n && board[nr][nc]=='M')
            minecount++;
        }
        if(minecount > 0){
            board[r][c]=minecount+'0';
            return;
        }
        board[r][c]='B';
        for(int i=0;i<8;i++){
            int nr=r+dr[i],nc=c+dc[i];
            dfs(board,nr,nc);
        }

    }
};