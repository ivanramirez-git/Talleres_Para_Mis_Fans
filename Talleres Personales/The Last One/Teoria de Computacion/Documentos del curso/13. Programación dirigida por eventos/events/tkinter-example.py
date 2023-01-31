import tkinter as tk
window = tk.Tk()
greeting = tk.Label(text="Hello, Tkinter")

entry = tk.Entry(width=50)

button = tk.Button(
    text="Click me!",
    width=25,
    height=5,
   
)

greeting.pack()
button.pack()
entry.pack()



# Multiple dispatchers
window.bind("<Button-1>", lambda e: print("Window received: ", e))
button.bind("<Button-1>", lambda e: print("Button received: ", e))
entry.bind("<Key>", lambda e: print("Entry received: ", e))

# Event codes 
# https://stackoverflow.com/a/32289245
# http://www.tcl.tk/man/tcl8.4/TkCmd/keysyms.htm 




window.mainloop()
