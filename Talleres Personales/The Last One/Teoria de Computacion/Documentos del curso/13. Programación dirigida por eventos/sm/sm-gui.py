import tkinter as tk
from tkinter.ttk import *


window = tk.Tk()
# w.withdraw()


pregunta1 = Label(window, text="Es la primera vez que participa en este encuentro?")

respuesta1 = Combobox(window, values=["Sí", "No"])

enviar = Button(text="Enviar")
enviar2 = Button(text="Enviar")
enviar.bind("<Button-1>", lambda evt: respuesta1.grid_remove())
enviar2.bind("<Button-1>", lambda evt: respuesta1.grid())


pregunta1.grid(row=0,column=0)
respuesta1.grid(row=0,column=1)
enviar.grid(row=1)
enviar2.grid(row=2)

window.mainloop()
