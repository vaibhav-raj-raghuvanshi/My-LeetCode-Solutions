class Solution:
    def shiftingLetters(self, s: str, shifts: list[int]) -> str:
        prev = 0
        for i in range (len(s) - 1, -1, -1):
            prev = shifts[i] = (prev + shifts[i]) % 26
        sol = ""
        for i in range(len(s)):
            sol += (chr((ord(s[i]) - ord('a') + shifts[i]) % 26 + ord('a')))
        return sol