from abc import ABC, abstractmethod


class Observable(ABC):
    def __init__(self):
        self.observers = []

    def bind(self, observer):
        self.observers.append(observer)

    def notify_all(self):
        for observer in self.observers:
            observer.notify(self)


class Observer(ABC):
    @abstractmethod
    def notify(self, observable):
        ...


######################


class CajaDeTexto(Observer):
    def notify(self, observable):
        print("Caja de texto recibió actualización desde el elemento", observable)


class Grafico(Observer):
    def notify(self, observable):
        print("El gráfico recibió actualización desde el elemento", observable)


######################


class DatoNumerico(Observable):
    def __init__(self, num: int):
        super().__init__()
        self.num = num


######################

datoNum = DatoNumerico(5)

cajaTexto = CajaDeTexto()
grafico = Grafico()

datoNum.bind(cajaTexto)
datoNum.bind(grafico)

...

datoNum.num = 5
datoNum.notify_all()
