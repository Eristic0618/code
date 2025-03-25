# https://www.acwing.com/problem/content/844/
def dfs(n):
    if len(l1) == n:
        for ele in l1:
            print(ele, end=" ")
        print()
        return None
    for i in range(1, n+1):
        if i in l1:
            continue
        l1.append(i)
        dfs(n)
        l1.pop()

n = int(input())
l1 = []
dfs(n)