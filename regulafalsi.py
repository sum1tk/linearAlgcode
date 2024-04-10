import math
def regulafalsi(f,a,b,tol):
    i = 1
    while True:
        c = (b*f(a) - f(b)*a)/(f(a) - f(b))
        initially = str(f"iter {i}:- a:{a}  b:{b} c:{c} f(c):")
        if f(c) == 0:
            return c
        elif f(c)*f(a)<0:
            if abs(c-b)<tol:
                return c
            b=c
        elif f(c)*f(b)<0:
            if abs(a-b)<tol:
                return c
            a=c
        elif f(c)*f(a)>0 and f(c)*f(b)>0:
            print("error: no root found")
        print(initially,f(c))
        i = i +1

print(regulafalsi(lambda x:math.cos(x) - x, 0, 1, 0.0001))