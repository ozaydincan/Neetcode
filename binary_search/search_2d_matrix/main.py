from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ROWS, COLS = len(matrix), len(matrix[0])

        left = 0
        right = ROWS * COLS - 1

        while left <= right:
            mid = (left + right) // 2

            row = mid // COLS
            col = mid % COLS

            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                right = mid - 1
            else:
                left = mid + 1

        return False


def main():
    sol = Solution()
    matrix = [[1, 2, 4, 8], [10, 11, 12, 13], [14, 20, 30, 40]]
    target_1, target_2 = 10, 15

    ans_1 = sol.searchMatrix(matrix, target_1)
    ans_2 = sol.searchMatrix(matrix, target_2)

    print(f"Answer 1: {ans_1}\nAnswer 2: {ans_2}")
    assert ans_1
    assert not ans_2

    ...


if __name__ == "__main__":
    main()
