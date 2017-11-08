def fact(n):
	factorial=1
	for i in range (1,n+1):
		factorial= factorial*i
		
	return factorial
 
 
tc= int(input())
 
for i in range(0,tc):
	num= int(input())
	num= fact(num)
	print(num) 
