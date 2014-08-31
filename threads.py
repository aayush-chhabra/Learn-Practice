from thread import start_new_thread
import time

count=0

def func(delay):
	global count
	while 1:
		#print "a"
		if count%2 == 0:	
			print("even : %d" % count)
			count+=1
			time.sleep(delay)

def func1(delay):
	global count
	while 1:	
		#print "a"
		if count%2 != 0:	
			print("odd : %d" % count)
			count+=1
			time.sleep(delay)


start_new_thread(func, (2,))
start_new_thread(func1, (3,))

while 1:
	pass