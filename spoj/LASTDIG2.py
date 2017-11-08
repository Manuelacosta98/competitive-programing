# your code goes here
import sys
 
def modPow(base,exp,mod):
 
	if exp == 0:
		return 1;
 
	elif exp == 1:
		return base;
 
	elif exp%2 == 0:
		return modPow(base*base%mod, exp/2, mod)
 
	else:
		return base*modPow(base, exp-1, mod)%mod 
 
 
 
n= int( raw_input())
 
for i in range(0, n):
	x =  raw_input()
	x = x.split()
	rest = str (modPow(int(x[0]), int(x[1]),10))
	print rest[len(rest)-1] 
