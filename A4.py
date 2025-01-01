class NQueens:
    
    def __init__(self, n):
        self.n = n
        self.solutions = []

    def solve(self):
        board = [-1] * self.n
        self.place_queens(board, 0)
        return self.solutions

    def place_queens(self, board, row):
        if row == self.n:
            self.solutions.append(list(board))
            return

        for col in range(self.n):
            if self.is_valid_move(board, row, col):
                board[row] = col
                self.place_queens(board, row+1)
                board[row] = -1

    def is_valid_move(self, board, row, col):
        for i in range(row):
            if board[i] == col or abs(board[i] - col) == abs(i - row):
                return False
        return True

n = 4
solver = NQueens(n)
solutions = solver.solve()
print(solutions)
