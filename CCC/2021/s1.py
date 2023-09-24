n = int(input())
h = list( map( int, input().split(" ") ) )
w = list( map( int, input().split(" ") ) )

area = 0

for i in range(n):
	area += w[i] * (h[i]+h[i+1])/2

print(area)