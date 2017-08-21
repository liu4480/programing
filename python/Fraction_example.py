
from fractions import Fraction
  
print Fraction(11, 35)
# returns Fraction(11, 35)
    
print Fraction(10, 18)
# returns Fraction(5, 9)
     
print Fraction()
# returns Fraction(0, 1)

print Fraction(1.13)
print Fraction('1.13')

print Fraction('3.14159265358979323846')
# returns Fraction(157079632679489661923, 50000000000000000000)
  
print Fraction('3.14159265358979323846').limit_denominator(10000)
# returns Fraction(355, 113)
  
print Fraction('3.14159265358979323846').limit_denominator(100)
# returns Fraction(311, 99)
  
print Fraction('3.14159265358979323846').limit_denominator(10)

print Fraction(113, 100) + Fraction(25, 18)
# returns Fraction(2267, 900)
  
print Fraction(18, 5) / Fraction(18, 10)
# returns Fraction(2, 1)
  
print Fraction(18, 5) * Fraction(16, 19)
# returns Fraction(288, 95)
  
print Fraction(18, 5) * Fraction(15, 36)
# returns Fraction(3, 2)
  
print Fraction(12, 5) ** Fraction(12, 10)
