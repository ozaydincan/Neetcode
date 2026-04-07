from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        MAX_PILE = max(piles)
        low, high = 1, MAX_PILE
        min_speed = MAX_PILE
        while low <= high:
            tmp_speed = (low + high) // 2
            total_time = 0
            for banana in piles:
                total_time += (banana + tmp_speed - 1) // tmp_speed
            if total_time <= h:
                min_speed = tmp_speed
                high = tmp_speed - 1
            else:
                low = tmp_speed + 1
        return min_speed


def main():
    sol = Solution()
    piles = [1, 4, 3, 2]
    h_1 = 9
    piles_2 = [25, 10, 23, 4]
    h_2 = 4
    assert sol.minEatingSpeed(piles, h_1) == 2
    print(
        f"The min speed for piles {piles} == 2 is {sol.minEatingSpeed(piles, h_1) == 2}"
    )
    assert sol.minEatingSpeed(piles_2, h_2) == 25
    print(
        f"The min speed for piles {piles_2} == 25 is {sol.minEatingSpeed(piles_2, h_2) == 25}"
    )


if __name__ == "__main__":
    main()
