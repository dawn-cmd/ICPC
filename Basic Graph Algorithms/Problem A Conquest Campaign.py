from collections import deque


def main():
    r, c, n = map(int, input().split())
    q = deque()
    h = set()
    for i in range(n):
        x, y = map(int, input().split())
        q.append((x, y, 1))
        h.add((x, y))
    ans = 0
    while q:
        x, y, days = q.popleft()
        ans = ans if ans > days else days
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for d in directions:
            x1 = x + d[0]
            y1 = y + d[0]
            if 1 <= x1 <= r and 1 <= y1 <= c and (x1, y1) not in h:
                q.append((x1, y1, days + 1))
                h.add((x1, y1))
    print(ans)


if __name__ == '__main__':
    main()
