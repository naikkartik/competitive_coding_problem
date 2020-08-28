def solution(n):
    count =0
    ans = 0
    while(n>0):
        count+=1
        if(n&1):
            temp = 1<<(32-count)
            ans+=temp 
        n = n>>1
    return ans

n  = int(input())
ans = solution(n)
print(ans,end="\n")
