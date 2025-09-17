#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int n, m;
int board[MAX][MAX];
int bestBoard[MAX][MAX];
int maxPlaced = 0;
int startRow = -1, startCol = -1;


bool isSafe(int row, int col) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 1) {
                if (r == row && c == col) continue;     
                if (r == row) return false;             
                if (c == col) return false;             
                if ((r + c) == (row + col)) return false; 
                if ((r - c) == (row - col)) return false; 
            }
        }
    }
    return true;
}

void storeBoard() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            bestBoard[i][j] = board[i][j];
}


void solve(int row, int placed) {
    if (placed > maxPlaced) {
        maxPlaced = placed;
        storeBoard();
    }
    if (placed == m) return; 
    if (row >= n) return;

    
    if (row == startRow) {
        solve(row + 1, placed);
        return;
    }

    
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solve(row + 1, placed + 1);
            board[row][col] = 0; 
        }
    }

    
    solve(row + 1, placed);
}

void printBoard(int arr[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(arr[i][j] ? "C " : ". ");
        }
        printf("\n");
    }
}

int main() {
    printf("Enter board size (n): ");
    if (scanf("%d", &n) != 1) return 0;
    if (n > MAX) {
        printf("Increase MAX (%d) and recompile for larger n.\n", MAX);
        return 0;
    }

    printf("Enter number of candidates (m): ");
    if (scanf("%d", &m) != 1) return 0;

    printf("Enter starting candidate position (row col) [1-based]: ");
    if (scanf("%d %d", &startRow, &startCol) != 2) return 0;

    
    startRow--; startCol--;
    if (startRow < 0 || startRow >= n || startCol < 0 || startCol >= n) {
        printf("Invalid starting position.\n");
        return 0;
    }

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = bestBoard[i][j] = 0;

   
    board[startRow][startCol] = 1;

    
    solve(0, 1);

    printf("Maximum candidates placed: %d\n", maxPlaced);
    printf("One valid arrangement (Q = candidate):\n");
    printBoard(bestBoard);

    return 0;
}
