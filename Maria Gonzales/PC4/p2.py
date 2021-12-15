# S(n, m) = 1*(m+n−1) + 2*(m+n−2) + ... + (n−2)*(m+2) + (n−1)*(m+1) + n*m
# S(1,1) = 1*1 = 1
# S(2,1) = 1*(1 + 2-1) + 2*(1 + 2-2) = 2 + 2 = 4
# S(3,1) = 1*(1 + 3-1) + 2*(1 + 3-2) + 3*(1 + 3-3) = 3 + 4 + 3 = 10

# S(3,1) = 1*(1 + 2-1) + 2*(1 + 2-2) + 3*1 = 10
# S(3,5) = 1*(5+2) + 2*(5+1) + 3*5 = 7 + 12 + 15 = 34 
# S(5,3) = 1*(3+4) + 2*(3+3) + 3*(3+2) + 4*(3+1) + 5*3 = 7 + 12 + 15 + 16 + 15 = 65
# S(10,6) = 1*(6+9) + 2*(6+8) + 3*(6+7) + 4*(6+6) + 5*(6+5) + 6*(6+4) + 7*(6+3) + 8*(6+2) + 9*(6+1) + 10*6 = 15 + 28 + 27 + 48 + 55 ... + 60 = 495

def S(n, m):
    # Si n es 0, entonces retornar 0
    if n == 0:
        return 0
    # Si n es 1, entonces retornar m
    elif n == 1:
        return m
    


"""
Ingrese n : 1
Ingrese m : 1
1

Ingrese n : 3
Ingrese m : 5
34

Ingrese n : 5
Ingrese m : 3
65

Ingrese n : 10
Ingrese m : 6
495
"""

# Funcion S(n, m) recursiva

n = int(input("Ingrese n : "))
m = int(input("Ingrese m : "))
print(S(n, m))
