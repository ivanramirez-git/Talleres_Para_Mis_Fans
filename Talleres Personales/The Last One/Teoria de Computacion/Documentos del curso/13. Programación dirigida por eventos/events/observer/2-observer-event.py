from abc import ABC, abstractmethod
from enum import Enum


class EventType(Enum):
    CLICK = 1
    TEXT_CHANGED = 2
    ...


class Event:
    def __init__(self, data, event_type):
        self.data = data
        self.event_type = event_type


class Dispatcher:  # Observable
    def __init__(self):
        self.handlers = []  # Observers

    def bind(self, handler, event_type):
        self.handlers.append([handler, event_type])

    def notify_all(self, event):
        # This can be optimized
        for handler, event_type in self.handlers:
            if event.event_type == event_type:
                handler.notify(event)


class Handler(ABC):  # Observer
    @abstractmethod
    def notify(self, event):
        ...


######################


class MyClickHandler(Handler):
    def notify(self, event):
        print("MyClickHandler está manejando el evento de click: ", event.data)


class MyTextChangedHandler(Handler):
    def notify(self, event):
        print("MyTextChangedHandler está manejando el evento de texto actualizado: ", event.data)


######################

dispatcher = Dispatcher()

dispatcher.bind(MyClickHandler(), EventType.CLICK)
dispatcher.bind(MyTextChangedHandler(), EventType.TEXT_CHANGED)


######################
dispatcher.notify_all(Event("Evento de click en coordenadas (140, 433)", EventType.CLICK))
dispatcher.notify_all(Event("Evento de click en coordenadas (50, 200)", EventType.CLICK))
dispatcher.notify_all(Event("Evento de click en coordenadas (768, 1024)", EventType.CLICK))
dispatcher.notify_all(Event("Evento de cambio de texto. 'Hola mundo' --> 'Hello World'", EventType.TEXT_CHANGED))