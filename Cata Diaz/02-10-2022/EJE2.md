
# Ejercicio 2 - operaciones básicas en señales discretas (Desplazamiento, reflexión y amplificación)

estudiando el libro de (Ambardar), sea 𝑥[𝑛] = ;1,2, 3,1> ,−3,−2?, dibuje las siguientes señales y determine su energía. Posteriormente verifique sus respuestas realizando el ejercicio 2 de la guía de componente práctico de la tarea 4.

K = 2

a. y[n]=-x[2n+a]
b. z[n]=x[-n/2+a]

## Punto a

y[n]=-x[2n+a]

y[n]=-x[2n+2]

Desplazamiento a la izquierda n_0=-2 con un escalamiento en  compresión n/2 y una reflexión en el eje de amplitud –

Sea x[n]={1,2,3,1 ̌├ -3,-2}

={1,2 ,3 ,1 ̌  ├ -3 ,-2}

eje x={-3,-2,-1,0 ̌├  ,1,2}

Para encontrar la energía de cada señal  tenemos que aplicar el punto a  y[n]=-x[2n+2]

donde tenemos que aplicar el desplazamiento en este caso el +2

Como no tenemos reflexión seguimos con la amplificación en este caso dividimos la anterior grafica en 2 y solo tomamos la señal de los números enteros

y[n]=-x[2n+2]

0/2=0

1/2=0.5

2/2=1

3/2=1.5

4/2=2

5/2=2.5

Después de encontrar el escalamiento debemos encontrar el eje de amplitud

y[n]=-x[2n+2]

(-)*1=-1

(-)*3=-3

(-)*-3=3

∑_(k=-∞)^∞▒|x[n]|^2

(-1)^2+(-3)^2+(3)^2=19

=19J

## Punto b

={1,2 ,3 ,1 ̌  ├ -3 ,-2}

eje x={-3,-2,-1,0 ̌├  ,1,2}

z[n]=x[-n/2+a]

Remplazamos

z[n]=x[-n/2+2]

Desplazamiento a la izquierda n_0=-2 con una reflexión –y un escalamiento multiplicado por 2

Después de tener el desplazamiento encontramos la reflexión multiplicamos el signo – por el número que nos dio en la señal

z[n]=x[-n/2+2]

(-)*0=0

(-)*1=-1

(-)*2=-2

(-)*3=-3

(-)*4=-4

(-)*5=-5

Ahora vamos a multiplicar en 2 para encontrar el escalamiento

z[n]=x[-n/2+2]

-5*2=-10

-4*2=-8

-3*2=-6

-2*2=-4

-1*2=-2

0*2=0

Después de encontrar el escalamiento debemos encontrar el eje de amplitud

Como tenemos que x es positivo no se hace y nos quedaría la gráfica igual

∑_(k=-∞)^∞▒|x[n]|^2

(-2)^2+(-3)^2+(1)^2+(3)^2+(2)^2+(0)^2=27

=27J
