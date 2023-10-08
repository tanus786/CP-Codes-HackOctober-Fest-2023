
from typing import List

class Solution:
    def uniqueRow(self, row: int, col: int, matrix: List[List[int]]) -> List[List[int]]:
        unique_rows = []
        unique_set = set()

        for i in range(row):
            curr_row = tuple(matrix[i])
            if curr_row not in unique_set:
                unique_rows.append(matrix[i])
                unique_set.add(curr_row)

        return unique_rows
