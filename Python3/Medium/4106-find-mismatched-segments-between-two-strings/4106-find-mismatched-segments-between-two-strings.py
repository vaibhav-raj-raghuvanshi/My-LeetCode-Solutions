class Solution:
    def findMismatchedSegments(self, s1: str, s2: str) -> list[list[str]]:
        s1 = s1 + " "
        s2 = s2 + " "
        sol = []
        temp1 = ""
        temp2 = ""
        for i in range (len(s1)):
            if s1[i] == s2[i]:
                if(len(temp1) > 0):
                    sol.append([temp1, temp2])
                temp1 = ""
                temp2 = ""
            else:
                temp1 = temp1 + s1[i]
                temp2 = temp2 + s2[i]
        return sol