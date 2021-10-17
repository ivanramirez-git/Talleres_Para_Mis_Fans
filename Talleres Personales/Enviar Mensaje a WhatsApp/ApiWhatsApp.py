# Importamos el modulo de tiempo

from datetime import datetime

# Importamos el ModuMódulo
import pywhatkit

# Asignamos el tiempo a una variable

now = datetime.now()

# Usamos Un try-except
try:

    # Enviamos el mensaje

    pywhatkit.sendwhatmsg("+573138049319",
                          "Oliver Tree - Life Goes On [Music Video] \n",
                          now.hour, now.minute+1)

    print("Mensaje Enviado")



except:

    print("Ocurrio Un Error")