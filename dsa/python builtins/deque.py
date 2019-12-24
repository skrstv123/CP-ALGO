#deque has characteristics of both stack and queue
from collections import deque
a = list(range(1,11))
d = deque(a)
print(d.pop(),d.popleft()) #10 1