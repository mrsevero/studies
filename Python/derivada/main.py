from sympy import *
import math

def deriva_fx(f: Add) -> Add:
    x = Symbol("x")
    return Derivative(f, x).doit()
x = Symbol("x")
f = x**3 + 4*x**2 - 10
fa = (2**-x)

print(Derivative(f,x).doit())
print(Derivative(fa,x).doit())