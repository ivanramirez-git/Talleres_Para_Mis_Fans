#Clase Producto
class Producto:
    def _init_(self, Id, producto):
        self.__Id_producto = Id
        self.__producto = producto
        self.__reg_prov = 0
        self.__registro = []

    def agregar_provedores(self, provedor, pu):
        self._reg_prov = self._reg_prov + 1
        datos = {
            'registro': self.__reg_prov,
            'provedor': provedor,
            'precio_unitario': pu
        }
        self.__provedores.append(datos)

    def quitar_provedores(self, reg_prov):
        for provedor in self.__registro:
            for dato, valor in provedor.items():
                if dato == 'registro' and valor == reg_prov:
                    self.__registro.remove(provedor)  # para remover

    def consultar_provedor(self):
        texto = f"Id producto: {self.__Id_producto}\n" \
                + f"Descripcion de producto :{self.__producto}\n" \
                + f"*******************************\n"
        for provedor in self.__registro:
            for dato, valor in provedor.items():
                texto = texto + f'{dato}: {valor}\n'
            texto = texto + f"-------------------------------------------------------------------------------\n"
        return texto


#Clase Cliente
class Cliente:
    # - Id_Cliente
    # - Nom_Cliente
    # - Dir_Cliente
    # - Ciu_Cliente
    # - Tel_Cliente
    # - 1 Factura
    # - * Pedido
    # + Leer _Cliente()
    # + Modificar_Cliente()

    def _init_(self, Id, nom, dir, ciu, tel):
        self.__Id_Cliente = Id
        self.__Nom_Cliente = nom
        self.__Dir_Cliente = dir
        self.__Ciu_Cliente = ciu
        self.__Tel_Cliente = tel
        self.__Factura = []
        self.__Pedido = []

    def leer_cliente(self):
        texto = f"Id Cliente: {self.__Id_Cliente}\n" \
                + f"Nombre Cliente: {self.__Nom_Cliente}\n" \
                + f"Direccion Cliente: {self.__Dir_Cliente}\n" \
                + f"Ciudad Cliente: {self.__Ciu_Cliente}\n" \
                + f"Telefono Cliente: {self.__Tel_Cliente}\n"
        return texto

    def modificar_cliente(self, nom, dir, ciu, tel):
        self.__Nom_Cliente = nom
        self.__Dir_Cliente = dir
        self.__Ciu_Cliente = ciu
        self.__Tel_Cliente = tel

#Clase Provedor
class Provedor:
    # - Nit_provedor
    # - Nom_provedor
    # - Dir_provedor
    # - Ciu_provedor
    # - Tel_provedor
    # - * Inventario
    # - * Compras
    # - * Producto
    # + Agregar_Producto(...)
    # + Quitar_Producto(...)
    # + Consultar_Producto(...)
    # + Registrar_Productos_Vendidos(...)

    def _init_(self, Nit, nom, dir, ciu, tel):
        self.__Nit_provedor = Nit
        self.__Nom_provedor = nom
        self.__Dir_provedor = dir
        self.__Ciu_provedor = ciu
        self.__Tel_provedor = tel
        self.__Inventario = []
        self.__Compras = []
        self.__Producto = []

    def agregar_producto(self, Id, producto):
        self.__Producto = Producto(Id, producto)
        self.__Inventario.append(self.__Producto)

    def quitar_producto(self, Id):
        for producto in self.__Inventario:
            for dato, valor in producto.items():
                if dato == 'Id_producto' and valor == Id:
                    self.__Inventario.remove(producto)  # para remover

    def consultar_producto(self):
        texto = f"Nit provedor: {self.__Nit_provedor}\n" \
                + f"Nombre provedor: {self.__Nom_provedor}\n" \
                + f"Direccion provedor: {self.__Dir_provedor}\n" \
                + f"Ciudad provedor: {self.__Ciu_provedor}\n" \
                + f"Telefono provedor: {self.__Tel_provedor}\n" \
                + f"*******************************\n"
        for producto in self.__Inventario:
            for dato, valor in producto.items():
                texto = texto + f'{dato}: {valor}\n'

            texto = texto + f"-------------------------------------------------------------------------------\n"

        return texto

    def registrar_productos_vendidos(self, Id, cantidad):
        for producto in self.__Inventario:
            for dato, valor in producto.items():
                if dato == 'Id_producto' and valor == Id:
                    self.__Inventario.remove(producto)  # para remover
                    self.__Producto.append(producto)
                    self.__Compras.append(cantidad)
                    break
