
 
# Tarea 1 Operaciones básicas de señales continuas y discretas

# Ejercicio 1 - Operaciones básicas en señales continuas (Desplazamiento, reflexión y amplificación)

## a. y(t) = x(-at - a)

## b. z(t) = -ax(t/a + a)

remplazamos

K = 2

y(t) = x(-2t - 2)

〖x(t-t_0 ) t〗_o=2 es la inversa de -2

Vamos a hacer lo que está en el eje temporal

Hacemos el desplazamiento

Luego hacemos la reflexión sobre la imagen que nos dio del desplazamiento, y la iniciamos en (0) por que este no tiene negativo ni positivo

y(t) = x(-2t - 2)

Ahora vamos a dividir en 2 para encontrar el escalamiento

y(t) = x(-2t - 2)

0/2 = 0

(-1)/2 = -0.5

(-2)/2 = -1

(-3)/2 = -1.5

(-4)/2 = -2

(-5)/2 = -2.5

(-6)/2 = -3

Ahora vamos a hacer el eje de amplitud

y(t) = x(-2t - 2)

Como tenemos que x es positivo no se hace y nos quedaría la gráfica igual

Punto b

z(t) = -ax(t/a + a)

Remplazamos

K = 2

z(t) = -2x(t/2 + 2)

Vamos a hacer lo que está en el eje temporal

Hacemos el desplazamiento

z(t) = -2x(t/2 + 2)

Como tenemos +2 y la inversa es -2 se suma al -2 de la gráfica y quedaría -4

Luego hacemos la reflexión sobre la imagen que nos dio del desplazamiento la iniciamos en (-4)

Pero como no tenemos signo negativo en t/2 no se hace la reflexión

z(t) = -2x( t/2 + 2)

Ahora vamos a multiplicamos en 2 para encontrar el escalamiento, se, multiplica ya que en el momento está dividiendo

z(t) = -2x(t/2 + 2)

2*2 = 4

-1*2 = -2

-2*2 = -4

-3*2 = -6

-4*2 = -8

-5*2 = -10

-6*2 = -12

Ahora vamos a hacer el eje de amplitud

(t) = -2x(t/2 + 2)

-2*-2 = 4

3*-2 = -6




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



## Ejercicio 3 - Respuesta al impulso de los sistemas LTI
Usando como guía los ejemplos 4.9 de las páginas 83 del libro guía Ambardar y la tabla 4.1 que caracteriza los tipos de salida de los sistemas LTI analógicos, determine la respuesta al impulso del siguiente sistema:
K = 2

$$y''(t) + 4by'(t) + by(t) = x(t)$$

Ecuación característica ya que nuestro valor es 2
$$s^2 + 8s + 2 = 0$$
Se utiliza la ecuación cuadrática ya que tenemos que $s^2$
$$r = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$
$$a = 1$$
$$b = 8$$
$$c = 2$$
Remplazamos
$$r = \frac{-8 \pm \sqrt{8^2 - 4*1*2}}{2*1}$$
$$r_1 = -4$$
$$r_2 = -0.5$$

Respuesta natural
Seria real y distinta
$$h(t) = e^{r_1t} + e^{r_2t}$$
$$h'(t) = r_1e^{r_1t} + r_2e^{r_2t}$$
$$h'(0) = r_1e^{r_1(0)} + r_2e^{r_2(0)} = 1$$
$$h'(0) = r_1 + r_2 = 1$$
$$r_1 + r_2 = 1$$
$$r_1 = 1 - r_2$$
$$r_1 = 1 - (-0.5)$$
$$r_1 = 1.5$$
Remplazamos y Obtenemos la respuesta al impulso
$$h(t) = e^{1.5t} + e^{-0.5t}$$

