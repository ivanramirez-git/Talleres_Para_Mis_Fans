#1- te logeas para ingresar al sistema 
#2- al logearte mediante el cargo que tengas algo así como administrador y vendedor (el administrador podrá ingresa,actualizar y eliminar productos y el vendedor solo realizar la venta)
#3- cuando ingresas podrás ver los productos 
#4- seleccionas los productos a comprar y realizas la venta
#5- se deben poder guardar los datos en archivos JSON

import json

#clase empleado
class Empleado:
    def __init__(self,nombre,apellido,cargo,correo,contraseña):
        self.nombre = nombre
        self.apellido = apellido
        self.cargo = cargo
        self.correo = correo
        self.contraseña = contraseña

    def __str__(self):
        return '{} {} {} {} {}'.format(self.nombre,self.apellido,self.cargo,self.correo,self.contraseña)

#clase producto
class Producto:
    def __init__(self,nombre,precio,cantidad):
        self.nombre = nombre
        self.precio = precio
        self.cantidad = cantidad

    def __str__(self):
        return '{} {} {}'.format(self.nombre,self.precio,self.cantidad)

#json
def guardar_producto(producto):
    nombreimput = producto.get('nombre')
    precioimput = producto.get('precio')
    cantidadimput = producto.get('cantidad')
    #crear objeto producto en formato serializado
    producto['nombre'] = str(f'{nombreimput}')
    producto['precio'] = str(f'${precioimput}')
    producto['cantidad'] = str(f'{cantidadimput}')
    producto = {'nombre':producto['nombre'],'precio':producto['precio'],'cantidad':producto['cantidad']}

    #Verificar si el producto ya existe
    with open('productos.json','r') as archivo:
        productos = json.load(archivo)
    for producto_existente in productos:
        if producto_existente['nombre'] == producto['nombre']:
            #actualizar producto
            producto_existente['nombre'] = producto['nombre']
            producto_existente['precio'] = producto['precio']
            producto_existente['cantidad'] = producto['cantidad']
            with open('productos.json','w') as archivo:
                json.dump(productos,archivo)
            print('Producto actualizado')
            break
    else:
        #agregar producto
        anadir_productos_archivo(producto)
        print('Producto agregado')

def guardar_empleado(empleado):
    nombreimput = empleado.get('nombre')
    apellidoimput = empleado.get('apellido')
    cargoimput = empleado.get('cargo')
    correoimput = empleado.get('correo')
    contraseñaimput = empleado.get('contraseña')
    #crear objeto empleado en formato serializado
    empleado['nombre'] = str(f'{nombreimput}')
    empleado['apellido'] = str(f'{apellidoimput}')
    empleado['cargo'] = str(f'{cargoimput}')
    empleado['correo'] = str(f'{correoimput}')
    empleado['contraseña'] = str(f'{contraseñaimput}')
    empleado = {'nombre':empleado['nombre'],'apellido':empleado['apellido'],'cargo':empleado['cargo'],'correo':empleado['correo'],'contraseña':empleado['contraseña']}

    #Verificar si el empleado ya existe
    with open('empleados.json','r') as archivo:
        empleados = json.load(archivo)
    for empleado_existente in empleados:
        if empleado_existente['correo'] == empleado['correo']:
            #actualizar empleado
            empleado_existente['nombre'] = empleado['nombre']
            empleado_existente['apellido'] = empleado['apellido']
            empleado_existente['cargo'] = empleado['cargo']
            empleado_existente['correo'] = empleado['correo']
            empleado_existente['contraseña'] = empleado['contraseña']
            with open('empleados.json','w') as archivo:
                json.dump(empleados,archivo)
            print('Empleado actualizado')
            break
    else:
        #agregar empleado
        anadir_empleados_archivo(empleado)
        print('Empleado agregado')

#funcion que guarda una lista de objetos en un archivo json
def guardar_lista_productos(lista_productos):
    with open('productos.json','w') as archivo:
        json.dump(lista_productos,archivo)

def guardar_lista_empleados(lista_empleados):
    with open('empleados.json','w') as archivo:
        json.dump(lista_empleados,archivo)

#funcion que agrega un objeto a la lista json de objetos
def anadir_empleados_archivo(empleado):
    with open('empleados.json','r') as archivo:
        empleados = json.load(archivo)
    empleados.append(empleado)
    with open('empleados.json','w') as archivo:
        json.dump(empleados,archivo)

def anadir_productos_archivo(producto):
    with open('productos.json','r') as archivo:
        productos = json.load(archivo)
    productos.append(producto)
    with open('productos.json','w') as archivo:
        json.dump(productos,archivo)

#funciones
def login():
    correo = input('Ingrese su correo: ')
    contraseña = input('Ingrese su contraseña: ')
    with open('empleados.json','r') as archivo:
        empleados = json.load(archivo)
    for empleado in empleados:
        if correo == empleado['correo'] and contraseña == empleado['contraseña']:
            print('Bienvenido {} {}'.format(empleado['nombre'],empleado['apellido']))
            if empleado['cargo'] == 'Administrador':
                menu_administrador(empleado)
            elif empleado['cargo'] == 'Vendedor':
                menu_vendedor(empleado)
            break
    else:
        print('Correo o contraseña incorrectos')
        return False
    print('Fin de la Sesion')
    return True

def menu_administrador(empleado):
    opcion = 0
    while opcion != 7:
        print('1- Ver productos')
        print('2- Realizar venta')
        print('3- Actualizar productos')
        print('4- Anadir productos')
        print('5- Eliminar productos')
        print('6- Manejo de empleados')
        print('7- Salir')
        opcion = int(input('Ingrese una opcion: '))
        if opcion == 1:
            ver_productos()
        elif opcion == 2:
            realizar_venta()
        elif opcion == 3:
            actualizar_productos()
        elif opcion == 4:
            anadir_productos()
        elif opcion == 5:
            eliminar_producto()
        elif opcion == 6:
            menu_manejo_empleados()
        elif opcion == 7:
            print('Gracias por utilizar nuestro sistema')
            break
        else:
            print('Opcion incorrecta')
            
def menu_vendedor(empleado):
    opcion = 0
    while opcion != 3:
        print('1- Ver productos')
        print('2- Realizar venta')
        print('3- Salir')
        opcion = int(input('Ingrese una opcion: '))
        if opcion == 1:
            ver_productos()
        elif opcion == 2:
            realizar_venta()
        elif opcion == 3:
            print('Gracias por utilizar nuestro sistema')
            break
        else:
            print('Opcion incorrecta')

def ver_productos():
    with open('productos.json','r') as archivo:
        productos = json.load(archivo)
    for producto in productos:
        print(producto)

def realizar_venta():
    with open('productos.json','r') as archivo:
        productos = json.load(archivo)
    #Imprimir con indices
    for i,producto in enumerate(productos):
        print('{}- {}'.format(i,producto))
    #Seleccionar producto
    opcion = int(input('Ingrese el numero del producto: '))
    producto = productos[opcion]
    #Verificar si hay stock
    if int(producto['cantidad']) > 0:
        #Disminuir stock
        producto['cantidad'] = int(producto['cantidad']) - 1
        producto['cantidad'] = str(producto['cantidad'])
        #Guardar cambios
        with open('productos.json','w') as archivo:
            json.dump(productos,archivo)
        print('Gracias por su compra')
    else:
        print('No hay stock')

#funcion para anadir productos en el json
def anadir_productos():
    nombreimput = input('Ingrese el nombre del producto: ')
    precioimput = input('Ingrese el precio del producto: ')
    cantidadimput = input('Ingrese la cantidad del producto: ')
    producto = {
        'nombre': nombreimput,
        'precio': precioimput,
        'cantidad': cantidadimput
    }
    #Verificar si el producto ya existe
    with open('productos.json','r') as archivo:
        productos = json.load(archivo)
    for productoactual in productos:
        if productoactual['nombre'] == producto.get('nombre'):
            print('El producto ya existe')
            return        
    guardar_producto(producto)

def actualizar_productos():
    #Imprimir con indices
    with open('productos.json','r') as archivo:
        productos = json.load(archivo)
    for i,producto in enumerate(productos):
        print('{}- {}'.format(i,producto))
    #Seleccionar producto
    opcion = int(input('Ingrese el numero del producto: '))
    producto = productos[opcion]
    #Verificar si existe el indice es correcto
    if opcion < len(productos):
        #Pedir datos para actualizar
        nombreimput = input('Ingrese el nombre del producto: ')
        precioimput = input('Ingrese el precio del producto: ')
        cantidadimput = input('Ingrese la cantidad del producto: ')
        #Actualizar datos
        producto = {
            'nombre': nombreimput,
            'precio': precioimput,
            'cantidad': cantidadimput
        }
        #Guardar cambios
        guardar_producto(producto)
    
def menu_manejo_empleados():
    opcion = 0
    while opcion != 5:
        print('1- Ver empleados')
        print('2- Crear empleados')
        print('3- Actualizar empleados')
        print('4- Eliminar empleados')
        print('5- Salir')
        opcion = int(input('Ingrese una opcion: '))
        if opcion == 1:
            ver_empleados()
        elif opcion == 2:
            crear_empleados()
        elif opcion == 3:
            actualizar_empleados()
        elif opcion == 4:
            eliminar_empleados()
        elif opcion == 5:
            print('Gracias por utilizar nuestro sistema')
            break
        else:
            print('Opcion incorrecta')

def ver_empleados():
    with open('empleados.json','r') as archivo:
        empleados = json.load(archivo)
    for empleado in empleados:
        print(empleado)

def crear_empleados():
    nombre = input('Ingrese su nombre: ')
    apellido = input('Ingrese su apellido: ')
    cargo = input('Ingrese su cargo: ')
    correo = input('Ingrese su correo: ')
    contraseña = input('Ingrese su contraseña: ')    
    empleado = {
        'nombre':nombre,
        'apellido':apellido,
        'cargo':cargo,
        'correo':correo,
        'contraseña':contraseña
    }
    guardar_empleado(empleado)

def actualizar_empleados():
    with open('empleados.json','r') as archivo:
        empleados = json.load(archivo)
    for empleado in empleados:
        print(empleado)
    correo = input('Ingrese su correo: ')
    for empleado in empleados:
        if empleado['correo'] == correo:
            nombre = input('Ingrese su nombre: ')
            apellido = input('Ingrese su apellido: ')
            cargo = input('Ingrese su cargo: ')
            contraseña = input('Ingrese su contraseña: ')
            empleado = {
                'nombre':nombre,
                'apellido':apellido,
                'cargo':cargo,
                'correo':correo,
                'contraseña':contraseña
            }
            guardar_empleado(empleado)
            print('Se actualizo el empleado')
            return
    print('Empleado no encontrado')

def eliminar_empleados():
    with open('empleados.json','r') as archivo:
        empleados = json.load(archivo)
    for empleado in empleados:
        print(empleado)
    correo = input('Ingrese su correo: ')
    for empleado in empleados:
        if empleado['correo'] == correo:
            empleados.remove(empleado)
            guardar_lista_empleados(empleados)
            print('Empleado eliminado')
            break
    else:
        print('Empleado no encontrado')

def eliminar_producto():
    with open('productos.json','r') as archivo:
        productos = json.load(archivo)
    #Imprimir con indices
    for i,producto in enumerate(productos):
        print('{}- {}'.format(i,producto))
    #Seleccionar producto
    opcion = int(input('Ingrese el numero del producto: '))
    producto = productos[opcion]
    #Verificar si existe el indice es correcto
    if opcion < len(productos):
        #Eliminar producto
        productos.remove(producto)
        guardar_lista_productos(productos)
    else:
        print('El producto no existe')

def menu_principal():
    logint = False
    while not logint:
        logint = login()

#Programa principal
menu_principal()

#Fin del programa
