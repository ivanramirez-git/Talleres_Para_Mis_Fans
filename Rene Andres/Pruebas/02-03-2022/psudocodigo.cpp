/*

funcion validarExpresion(listaDobleEnlace<char> expresion) {
    if (expresion.getSize() == 0) {
        return false;
    }
    else {
        if (expresion.getSize() == 1) {
            if (expresion.getFirst() == '(' || expresion.getFirst() == ')') {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            if (expresion.getFirst() == '(') {
                return validarExpresion(expresion.getSubList(1, expresion.getSize() - 1));
            }
            else {
                if (expresion.getLast() == ')') {
                    return validarExpresion(expresion.getSubList(0, expresion.getSize() - 2));
                }
                else {
                    return false;
                }
            }
        }
    }
}

Ahora en PSUDOCODIGO:

Algorithm 2.1 Algoritmo de validacion de una expresion (expresion)
-------------------------------------------------------
if expresion.getSize() == 0 then
    return false
else
    if expresion.getSize() == 1 then
        if expresion.getFirst() == '(' or expresion.getFirst() == ')' then
            return false
        else
            return true
    else
        if expresion.getFirst() == '(' then
            return validarExpresion(expresion.getSubList(1, expresion.getSize() - 1))
        else
            if expresion.getLast() == ')' then
                return validarExpresion(expresion.getSubList(0, expresion.getSize() - 2))
            else
                return false
-------------------------------------------------------


funcion retornarCadenaMasInterna(listaDobleEnlace<char> expresion) {
    if (expresion.getSize() == 0) {
        return "";
    }
    else {
        if (expresion.getSize() == 1) {
            return expresion.getFirst();
        }
        else {
            if (expresion.getFirst() == '(') {
                return retornarCadenaMasInterna(expresion.getSubList(1, expresion.getSize() - 1));
            }
            else {
                if (expresion.getLast() == ')') {
                    return retornarCadenaMasInterna(expresion.getSubList(0, expresion.getSize() - 2));
                }
                else {
                    // Buscar '(' o ')'
                    int posicion = 0;
                    for (int i = 0; i < expresion.getSize(); i++) {
                        if (expresion.get(i) == '(' ) {
                            posicion = i;
                            return retornarCadenaMasInterna(expresion.getSubList(posicion + 1, expresion.getSize() - posicion - 2));
                        }
                        else {
                            if (expresion.get(i) == ')') {
                                posicion = i;
                                return retornarCadenaMasInterna(expresion.getSubList(0, posicion));
                            }
                        }
                        else {
                            return expresion;
                        }
                    }
                }
            }
        }
    }
}

Ahora en PSUDOCODIGO:


Algorithm 2.2 Algoritmo de retornar la cadena mas interna (expresion)
-------------------------------------------------------
expresionAux = ""
for i = 0 hasta expresion.getSize() - 1 do

    if expresion.get(i) == '(' then
        expresionAux = ""
    else    
        expresionAux = expresionAux+expresion[i]

    if expresion.get(i) == ')' then
        return expresionAux.getSubList(0, expresionAux.getSize() - 1)
-------------------------------------------------------

Complejidad de tiempo:
-------------------------------------------------------
expresionAux = ""           // O(1)
for i = 0 to expresion.getSize() - 1 do // O(n)
    if expresion.get(i) == '(' then // O(1)
        expresionAux = "" // O(1)
    else    
        expresionAux = expresionAux+expresion[i] // O(1)

    if expresion.get(i) == ')' then // O(1)
        return expresionAux.getSubList(0, expresionAux.getSize() - 1) // O(1)
-------------------------------------------------------

Sumando todas las operaciones, la complejidad de tiempo es:
-------------------------------------------------------
O(n) = T(n)
-------------------------------------------------------
    

