#This code inputs a string and searches for that string in a text file.
#If the string is already present then it gives a message depicting that,otherwise it adds that string to that file.


new_question=raw_input("Enter your new question:")+'\n'#Put your question title here
flag=0
f=open('LinkedList.txt','a+')
for line in f:
	#print line
	if new_question==line:
		print "The question is already present in the list."
		flag=1
if flag==0:
	f.write(new_question)
	print "New entry successfully added."
f.close()
wait=raw_input("Press to exit")