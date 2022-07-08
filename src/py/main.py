from crypt import methods
from functools import reduce, wraps
from typing import Callable
from numpy import transpose, fliplr

def Flip(func: Callable[[list[list[int]]], list[list[int]]]) -> Callable[[list[list[int]]], list[list[int]]]:
	"""Left to write flip before and after function"""
	@wraps(func)
	def newFunc(*args: tuple, **kwargs: dict):
		s, val = args
		value: list[list[int]] = fliplr(val)
		value = func(s, value)
		return fliplr(value)
	return newFunc

def Transpose(func: Callable[[list[list[int]]], list[list[int]]]) -> Callable[[list[list[int]]], list[list[int]]]:
	"""Transposes before and after function"""
	@wraps(func)
	def newFunc(*args: tuple, **kwargs: dict):
		s, val = args
		value: list[list[int]] = transpose(val)
		value = func(s, value)
		return transpose(value)
	return newFunc

def FillLeft(func: Callable[[list[list[int]]], list[list[int]]]) -> Callable[[list[list[int]]], list[list[int]]]:
	"""Fills values to the left before and after function"""
	@wraps(func)
	def newFunc(*args: tuple):
		s, val = args
		value: list[list[int]] = [sorted(x, key=bool, reverse=True) for x in val]
		value = func(s, value)
		return [sorted(x, key=bool, reverse=True) for x in value]
	return newFunc

def combine(board: list[list[int]]) -> list[list[int]]:
	"""Combines left neighbors and sets next to right equal to zero for matrix"""
	for x in range(4):
		for y in range(3):
			if board[x][y] == board[x][y+1]:
				board[x][y] *= 2
				board[x][y+1] = 0
	return board

class Game:
	"""2048 python implementation"""
	def __init__(self):
		self.board: list[list[int]] = [[0] * 4] * 4
		self.funclist: list[Callable] = [self.left, self.right, self.up, self.down]

	@FillLeft
	def left(self, matrix: list[list[int]]):
		"""Move left"""
		return combine(matrix)
	
	@Flip
	@FillLeft
	def right(self, matrix: list[list[int]]):
		"""Move right"""
		return combine(matrix)
	
	@Transpose
	@FillLeft
	def up(self, matrix: list[list[int]]):
		"""Move up"""
		return combine(matrix)
	
	@Transpose
	@Flip
	@FillLeft
	def down(self, matrix: list[list[int]]):
		"""Move down"""
		return combine(matrix)

	def move(self, move):
		"""Moves board - 0-3 as L-R-Up-Down"""
		self.board = self.funclist[move](self.board)

	def availableMoves(self) -> list[bool]:
		"""Returns true for all possible moves on current board"""
		return list(map(lambda x: x(self.board) == self.board, self.funclist))

	def canMove(self) -> bool:
		"""Returns true if can move"""
		return reduce(lambda x, y: x + y, self.availableMoves())