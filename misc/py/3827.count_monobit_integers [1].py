class Solution:
    # T.C.=O(log(n)), S.C.=O(1)
    # Math
    def countMonobit(self, n: int) -> int:
        return 1 + math.floor(math.log2(n+1))

# every monobit int is of the form (2^n - 1), n=0,1,2,...