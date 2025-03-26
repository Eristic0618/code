# https://www.acwing.com/activity/content/problem/content/819/
def quick_sort(a, l, r):
    if l == r:
        return
    i = l-1
    j = r+1
    k = a[l + r >> 1]
    while i < j:
        i += 1
        while a[i] < k:
            i += 1
        j -= 1
        while a[j] > k:
            j -= 1
        if i < j:
            temp = a[i]
            a[i] = a[j]
            a[j] = temp
    quick_sort(a, l, j)
    quick_sort(a, j+1, r)
            
n = int(input())
a = []
s = input()
s = s.strip()
l = s.split(" ")
for i in l:
    a.append(int(i))
quick_sort(a, 0, n-1)
for i in a:
    print(i, end=" ")