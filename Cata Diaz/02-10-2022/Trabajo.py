import numpy as np
import matplotlib.pyplot as plt

# Constante K = 2
K = 2

'''

Ejercicio 1- operaciones básicas en señales continuas
(Desplazamiento, reflexión y amplificación): estudiando en
el libro de (Ambardar), para la señal x(t) de la figura 1, obtenga
las siguientes señales de forma teórica, y posteriormente
verifique sus respuestas realizando el ejercicio 1 de la guía de
componente práctico de la tarea 4.
a. y(t) = x(-at - a)
b. z(t) = -ax(t/a + a)

'''
# Solución paso a paso de la parte teórica: 
# a. y(t) = x(-at - a)
# b. z(t) = -ax(t/a + a)




'''
• Ejercicio 2 - operaciones básicas en señales discretas
(Desplazamiento, reflexión y amplificación): estudiando el
libro de (Ambardar), sea x[n] = {1,2,3,1,-3,-2}, dibuje las
siguientes señales y determine su energía. Posteriormente
verifique sus respuestas realizando el ejercicio 2 de la guía de
componente práctico de la tarea 4.
a. y[n] = -x[2n+a]
b. z[n] = x[-n/2 + a] 

'''


'''
Ejercicio 3 - Respuesta al impulso de los sistemas LTI:
Usando como guía los ejemplos 4.9 de las páginas 83 del
libro guía Ambardar y la tabla 4.1 que caracteriza los tipos
de salida de los sistemas LTI analógicos, determine la
respuesta al impulso del siguiente sistema:
y''(t) + 4by'(t) + by(t) = x(t)

Nota: Los pasos para determinar la respuesta impulso son:
• Obtener la ecuación característica del sistema
• Hallar las raíces
• Encontrar la respuesta natural (ver tabla 4.1 del libro
guía, Ambardar)
• Derivar la respuesta natural
• Encontrar los valores de las constantes
• Obtener la respuesta al impulso.
'''