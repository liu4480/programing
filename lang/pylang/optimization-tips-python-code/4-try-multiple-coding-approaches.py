print somelist, end - start
n program to illustrate trying
# multiple coding approaches 
# for getting faster result
# slower
mydict = {'g':1,'e':1,'e':1,'k':1}
word = 'geeksforgeeks'
for w in word:
    if w not in mydict:
        mydict[w] = 0
    mydict[w] += 1
print mydict
 
# faster
mydict = {'g':1,'e':1,'e':1,'k':1}
word = 'geeksforgeeks'
for w in word:
    try:
        mydict[w] += 1
    except KeyError:
        mydict[w] = 1
print mydict

