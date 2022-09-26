Ejercicio 1 (0.8P) Ordenar las siguientes funciones:
f(n) = n^2 ∗ log(8n^3), g(n) = Sumatoria desde i=1 hasta n de i^2

    1. Pasar la sumatoria a una función recursiva

    g(n) = n^2 + g(n-1)

    2. Pasar la sumatoria a una función iterativa

    g(1) = 1
    g(2) = 1 + 2^2 = 5
    g(3) = 5 + 3^2 = 14
    g(4) = 14 + 4^2 = 30
    g(5) = 30 + 5^2 = 55

    3. Funcion normal en notación matemática

    g(n) = n(n+1)(2n+1)/6

    3. Evaluar si f(n) es Alfa(g(n)), Omega(g(n)) o Theta(g(n))

    f(n) es Alfa(g(n)) cuando el limite de f(n)/g(n) tiende a infinito, cuando n tiende a infinito
    f(n) es Omega(g(n)) cuando el limite de f(n)/g(n) tiende a 0, cuando n tiende a infinito
    f(n) es Theta(g(n)) cuando el limite de f(n)/g(n) tiende a k, cuando n tiende a infinito

    4. Como el limite de f(n)/g(n) tiende a 0, cuando n tiende a infinito, entonces f(n) es Omega(g(n))

Ejercicio 2 (0.8 P)
Se desea dividir a 2n recintos electorales en dos distritos de n recintos cada uno. Cada recinto tiene
asociado un indice pi que representa el numero de electores, es decir, pi < αn. La entidad electoral sugiere crer distritos de
la manera mas injusta posible, es decir, construir distritos A y B con el mayor desequilibrio respecto a numero de electores.
Mostrar como se puede hacer el trabajo en tiempo O(n).

    recintos = [1, 7, 9, 5, 3, 2, 4, 6, 8, 10]
    n = 5
    distritoA = []
    distritoB = []
    electores = sumatoria(pi)
    MID = electores/2

    // Ordenar con tiempos o(n)
    i = 0
    j = 0
    tam = len(recintos) - 1
    while (j <= n) {
        if (recintos[j] < MID) {
            aux = recintos[i]
            recintos[i] = recintos[j]
            recintos[j] = aux
            i++
            j++
        } else  if (recintos[j] > MID) {
            aux = recintos[tam]
            recintos[tam] = recintos[j]
            recintos[j] = aux
            tam--
        } else {
            j++
        }
    }
    distritoA = recintos[0:n] //agregamos desde 0 hasta la mitad
    distritoB = recintos[n:len(recintos)] //agregamos desde la mitad hasta el final

Ejercicio 3 (0.8P) Sea T un arbol binario de busqueda con numeros reales. Escribir un algoritmo para los siguientes casos:
• Encontrar el nodo x ∈ T tal que der(x), izq(x) != NULL y key[der(x)] − key[izq(x)] sea maximo.
• Encontrar el nodo x ∈ T tal que x sea una hoja, x != raiz(T) y |x − PADRE[x]| sea minimo.

    1. Encontrar el nodo x ∈ T tal que der(x), izq(x) != NULL y key[der(x)] − key[izq(x)] sea maximo.

    def maximo(arbol):
        while (arbol.der != NULL) {
            arbol = arbol.der
        }
        arbol = arbol.padre
        if (arbol.der != NULL && arbol.izq != NULL) {
            return arbol
        } else {
            arbol = arbol.padre
            arbol = arbol.izq
            return maximo(arbol)
        }

    2. Encontrar el nodo x ∈ T tal que x sea una hoja, x != raiz(T) y |x − PADRE[x]| sea minimo.

    def minimo(arbol):
        while (arbol.izq != NULL) {
            arbol = arbol.izq
        }
        arbol = arbol.padre
        if (arbol.padre != NULL) {
            return arbol
        } else {
            arbol = arbol.der
            return minimo(arbol)
        }
