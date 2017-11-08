# your code goes here
import sys
 
def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)
 
 
n= int(input())
 
for i in range(0, n):
	x, y =  [int(x) for x in input().split()]
	rest = str (gcd(x, y))
	print (rest)
