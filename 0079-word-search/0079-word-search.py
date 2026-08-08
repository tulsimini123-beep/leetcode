class Solution:
    def exist(self, board, word):
        rows = len(board)
        cols = len(board[0])

        def dfs(r, c, index):

            # We found the complete word
            if index == len(word):
                return True

            # Check boundaries
            if r < 0 or r >= rows or c < 0 or c >= cols:
                return False

            # Character does not match
            if board[r][c] != word[index]:
                return False

            # Store the original character
            temp = board[r][c]

            # Mark cell as visited
            board[r][c] = '#'

            # Search in 4 directions
            found = (
                dfs(r + 1, c, index + 1) or  # down
                dfs(r - 1, c, index + 1) or  # up
                dfs(r, c + 1, index + 1) or  # right
                dfs(r, c - 1, index + 1)     # left
            )

            # Restore the cell
            board[r][c] = temp

            return found

        # Try every cell as the starting point
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == word[0]:
                    if dfs(r, c, 0):
                        return True

        return False  