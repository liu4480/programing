import getpass
#NO PROMPT
try:
    p = getpass.getpass()
except Exception as error:
    print('ERROR', error)
else:
    print('Password entered:', p)

#SECURITY QUESTION
p = getpass.getpass(prompt='Your favorite flower? ')
if p.lower() == 'rose':
    print('Welcome..!!!')
else:
    print('The answer entered by you is incorrect..!!!')
 
user = getpass.getuser()
 
#getuser
while True:
    pwd = getpass.getpass("User Name : %s" % user)
 
    if pwd == 'abcd':
        print "Welcome!!!"
        break
    else:
        print "The password you entered is incorrect."
