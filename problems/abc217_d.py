from bisect import bisect_left
L, Q = map(int, input().split())

segments = [L]

for q in range(Q):
    c, x = map(int, input().split())
    index = bisect_left(segments, x)

    def get_segment_length():
        global segments
        if index == 0:
            return segments[index]
        return segments[index] - segments[index - 1]

    def add_segment():
        global segments
        segments = segments[:index] + [x] + segments[index:]
        pass

    if c == 1:
        add_segment()
    elif c == 2:
        print(get_segment_length())
