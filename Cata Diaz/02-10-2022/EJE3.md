
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

