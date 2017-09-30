import copy

li1 = [1, 2, [3,5], 4]
 
# using deepcopy to deep copy 
li2 = copy.deepcopy(li1)
li3 = copy.copy(li1)
# original elements of list
print ("The original elements before deep copying")
for i in range(0,len(li1)):
    print (li1[i],end=" ")
 
print("\r")
 
# adding and element to new list
li2[2][0] = 7
 
# Change is reflected in l2 
print ("after changing li2[2][0] ")
print("li1=", li1)
print("li2=", li2) 
print("li3=", li3) 
print("\r")
 
li3[2][0]=100
print ("after changing li3[2][0] ")
print("li1=", li1)
print("li2=", li2) 
print("li3=", li3) 
