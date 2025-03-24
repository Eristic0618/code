# https://www.acwing.com/problem/content/description/847/
from queue import Queue

def bfs(start):
    q = Queue() # 队列
    d = dict() # 到初状态的距离
    
    q.put(start) # 初状态入队列
    d[start] = 0 
    end = "12345678x"
    
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    while q.qsize():
        f = q.get() # 取出队头元素
        dist = d[f]
        
        if f == end:
            return dist
        
        index = f.find("x") # 查找x在字符串中的位置
        x = index // 3 # 将位置转换为坐标
        y = index % 3
        for i in range(4): # 四个方位
            a = x + dx[i]
            b = y + dy[i]
            if a >= 0 and a < 3 and b >= 0 and b < 3:
                new_index = a * 3 + b # 将坐标还原为字符串中的位置
                l = list(f)
                temp = l[index]
                l[index] = l[new_index]
                l[new_index] = temp
                st = ""
                for c in l:
                    st += c
                if st not in d:
                    q.put(st)
                    d[st] = dist + 1
    return -1

start = input()
start = start.replace(" ", "") # 去掉所有空格

ret = bfs(start)

print(ret)