def moore(a):
	count=1
	maj_index=0
	for i,j in enumerate(a):
		if a[maj_index]==j:
			count+=1
		else:
			count-=1
		if count==0:
			count=1
			maj_index=i
	return a[maj_index]

a=[3,3,4,2,4,4,2,4]
n=int(len(a))/2
#print n
count=0
maj_elem=moore(a)
#print maj_elem
for i in a:
	if maj_elem==i:
		count+=1
#print count
if count>n:
	print "Majority Element is: ",maj_elem
else:
	print "No majority element exists."