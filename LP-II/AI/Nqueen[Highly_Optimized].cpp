#include<iostream>
#include<cstring>
#define N 4

using namespace std;


void printPuzzle(int board[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

bool isSafe(int row, int col, int slash[N][N],
            int backSlash[N][N], bool rowLookup[],
      bool slashLookUp[], bool backSlashLookUp[] ){
          if(slashLookUp[slash[row][col]] || 
          backSlashLookUp[backSlash[row][col]] || rowLookup[row]) 
          return false;

          return true;
      }

bool solveNqueenUtil(int board[N][N], int col, int slash[N][N], int backSlash[N][N], bool rowLookUp[N], bool slashLookUp[N], bool backSlashLookUp[N]){
    if(col >= N) return true;
    for(int i = 0; i < N; i++){
        if(isSafe(i, col, slash, backSlash, rowLookUp, slashLookUp, backSlashLookUp))
        {
            board[i][col] = 1;
            rowLookUp[i] = true;
            slashLookUp[slash[i][col]] = true;
            backSlashLookUp[backSlash[i][col]] = true;
            if (solveNqueenUtil(board, col + 1,
                                  slash, backSlash,
             rowLookUp, slashLookUp, backSlashLookUp))
                return true;

            board[i][col] = 0;
            rowLookUp[i] = false;
            slashLookUp[slash[i][col]] = false;            
            backSlashLookUp[backSlash[i][col]] = false;
        }
    }
    return false;
}

void solveNqueen(){
    int board[N][N];
    memset(board, 0, sizeof(board)); // 0 intialize
    int backSlash[N][N];
    int slash[N][N];

    bool rowLookUp[N] = {false};

    bool backSlashLookUp[2*N - 1] = {false};
    bool slashLookUp[2*N - 1] = {false};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            backSlash[i][j] = (i - j) + (N - 1);
            slash[i][j] = i + j;
        }
    }


    if(solveNqueenUtil(board, 0, slash, backSlash, rowLookUp, slashLookUp, backSlashLookUp) == false){
        cout << "Solution does not exist!!\n";
        printPuzzle(board);
    }
    else{
        printPuzzle(board);
    }
}

int main(){
    solveNqueen();
    return 0;
}
