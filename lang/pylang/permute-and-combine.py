from itertools import permutations
 
# Get all permutations of [1, 2, 3]
perm = permutations([1, 2, 3])
 
# Print the obtained permutations
for i in list(perm):
    print i

perm = permutations([1, 2, 3], 2)
 
# Print the obtained permutations
for i in list(perm):
    print i

from itertools import combinations
 
# Get all combinations of [1, 2, 3]
# and length 2
comb = combinations([1, 2, 3], 2)
  
# Print the obtained combinations
for i in list(comb):
    print i
