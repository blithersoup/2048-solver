from functools import reduce
from typing import List
from numpy import transpose

class Game:

    def __init__(self):
        self.board: List[List[int]] = [[0] * 4] * 4
        self.funclist = [self.left, self.up, self.down, self.right]

    def left(self, board):
        new, j = [[0] * 4] * 4, 0
        for x in board:
            i = 0
            while i < 3:
                if x[i] == x[i+1] and x[i] != 0:
                    new[j][i] = x[i] * 2
                    i += 2
                else:
                    new[j][i] = x[i]
                    i += 1
            j += 1
        return new

    def right(self, board):
        new = [[0] * 4] * 4
        for x in range(3,-1,-1):
            i = 3
            while i > 0:
                if board[x][i] == board[x][i-1] and board[x][i]:
                    new[x][i] = board[x][i] * 2
                    i -= 2
                else:
                    new[x][i] = board[x][i]
                    i -= 1
        return new

    def up(self):
        self.board = self.moveRight(transpose(self.board))

    def down(self):
        self.board = self.moveLeft(transpose(self.board))

    def move(self, move):
        self.board = self.funclist[move](self.board)
    
    def availableMoves(self):
        return map(lambda x: x(self.board) == self.board, self.funclist)

    def canMove(self) -> bool:
        return reduce(lambda x, y: x + y, self.availableMoves())

x = Game()
x.board = [[2,2,4,0],[0,2,0,0],[0,0,0,4]]
x.move(0)
print(x.board)
'''
class Game:

    def __init__(self):
        return

    def possibleMoves(self):
        return

    def move(self, move):
        if move in self.possibleMoves():
            return

    def state(self):
        return
'''