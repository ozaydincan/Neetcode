from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                high = mid - 1
            else:
                low = mid + 1
        return -1


def main():
    nums_1 = [-1, 0, 2, 4, 6, 8]
    target_1 = 4
    target_2 = 3
    sol = Solution()
    answer_1 = sol.search(nums_1, target_1)
    answer_2 = sol.search(nums_1, target_2)
    print(f"Answer 1: {answer_1}\nAnswer 2: {answer_2}")
    assert answer_1 == 3
    assert answer_2 == -1


if __name__ == "__main__":
    main()
