from Crypto.Util import number
import os

A = 3
while (A - 1) % 4 != 0:
    A = number.getPrime(64, os.urandom)

B = number.getPrime(64, os.urandom)

n = 100000000
# n = number.getRandomRange(100, 10000000, os.urandom)
L = number.getRandomRange(0, n, os.urandom) + 1
s0 = number.getRandomInteger(64)

print("{} {} {} {} {}".format(A, B, L, n, s0))
