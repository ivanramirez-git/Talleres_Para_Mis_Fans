from abc import ABC, abstractmethod
from enum import Enum
from collections import defaultdict


class EventType(Enum):
    CLICK = 1
    TEXT_CHANGED = 2
    ...


class Event:
    def __init__(self, data, event_type):
        self.data = data
        self.event_type = event_type


class Dispatcher:
    def __init__(self):
        self.callbacks = defaultdict(list)  # a.k.a. observers, handlers

    def bind(self, handler, event_type):
        self.callbacks[event_type].append(handler)

    def onClick(self, handler):
        self.bind(handler, EventType.CLICK)

    def onTextChanged(self, handler):
        self.bind(handler, EventType.TEXT_CHANGED)

    def notify_all(self, event):
        for handler in self.callbacks[event.event_type]:
            handler(event)


#################
# Callbacks


def my_click_callback(event):
    print("my_click_callback está manejando el evento de click: ", event.data)


def my_text_changed_callback(event):
    print(
        "my_text_changed_callback está manejando el evento de texto actualizado: ",
        event.data,
    )


#################

dispatcher = Dispatcher()

dispatcher.onClick(my_click_callback)
dispatcher.onTextChanged(my_text_changed_callback)

dispatcher.onClick(
    lambda event: print("Lambda 1 está manejando evento click: ", event.data)
)
dispatcher.onTextChanged(
    lambda event: print("Lambda 2 está manejando evento text changed: ", event.data)
)

event_queue = [
    Event("Evento de click en coordenadas (140, 433)", EventType.CLICK),
    Event("Evento de click en coordenadas (50, 200)", EventType.CLICK),
    Event("Evento de click en coordenadas (768, 1024)", EventType.CLICK),
    Event(
        "Evento de cambio de texto. ´Hola mundo´ --> ´Hello World´",
        EventType.TEXT_CHANGED,
    ),
]

while True:
    if len(event_queue) == 0:
        break
    event = event_queue.pop(0)
    dispatcher.notify_all(event)
