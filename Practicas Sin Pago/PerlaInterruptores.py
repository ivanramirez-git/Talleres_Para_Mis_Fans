# 3 Interruptores

a=input("Ingrese el valor del primer interruptor (s/n): ")
b=input("Ingrese el valor del segundo interruptor (s/n): ")
c=input("Ingrese el valor del tercer interruptor (s/n): ")

# Si dos interruptores estan activos, el bombillo se encendera
# Condiciones: 2 de los interruptores estan activos
if a=="s" and b=="s":
    print("El bombillo se encendera")
elif a=="s" and c=="s":
    print("El bombillo se encendera")
elif b=="s" and c=="s":
    print("El bombillo se encendera")
else:
    print("El bombillo no se encendera")
