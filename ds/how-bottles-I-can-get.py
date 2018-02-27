import os

bottleForBeer = 2
coverForBeer = 4

def calccover(bottles, bottle, cover):
     while cover >= coverForBeer:
         print "calccover", bottles, bottle, cover
         bottles = bottles + cover/coverForBeer
         bottle = bottle + cover/coverForBeer
         cover = cover%coverForBeer + cover/coverForBeer
     if bottle > 1:
         return calcbottles(bottles, bottle, cover)
     return bottles


def calcbottles(bottles, bottle, cover):
     while bottle >= bottleForBeer:
         print "calcbottles", bottles, bottle, cover
         bottles = bottles + bottle/bottleForBeer
         cover = cover + bottle/bottleForBeer
         bottle = bottle/bottleForBeer + bottle%bottleForBeer
     if cover > coverForBeer:
         return calccover(bottles, bottle, cover)
     return bottles

def calc(money, price):
     bottles = money/price
     bottle = bottles
     cover = bottles
     return calcbottles(bottles,bottle,cover)

print calc(10,2)
