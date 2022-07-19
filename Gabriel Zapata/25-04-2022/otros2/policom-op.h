/******************************************************************************
 *
 * policom-op.h: Definicion de las operaciones suma, resta, multiplicacio,
 * division euclidiana, evaluacion en polinomios complejos ademas de las
 * operaciones aritmeticas que permitan leer, manipular e imprimir polinomios
 *
 * Programmer: Cristobal Guzman Poblete, Cesar Sandoval Mondaca
 *
 * Santiago de Chile, 28/04/2022
 *
 ******************************************************************************/
 
#include "policom-def.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 

/*Funcion que permite definir un polinomio existe
 *
 */
 
struct politerm *Iniciarpol(struct politerm *q) {

    q = NULL;
    return q;
}

/*Funcion que permite agregar un termino al polinomio al comienzo de este
 *
 */

struct politerm *Insercomienzo(float a, float b, unsigned int c, struct politerm *p) {

    struct politerm *q;
   
    q = calloc(1,sizeof(struct politerm));
    q->coef.r = a;
    q->coef.i = b;
    q->exp= c;
    q->next = p;
    return q;
}


/*Funcion que permite agregar un termino al polinomio al final de este
 *
 */
 
struct politerm *Inserfin(float a, float b, unsigned int c, struct politerm *p) {

    struct politerm *q, *r;
   
    q = calloc(1,sizeof(struct politerm));
    q->coef.r = a;
    q->coef.i = b;
    q->exp = c;
    q->next = NULL;
    r = p;
    while (r->next != NULL) {
        r = r->next;
        r->next = q;
    }
    return p;
}


/*Funcion que permite eliminar un termino en el polinomio al comienzo de este
 *
 */
 
struct politerm *Deletecomienzo(struct politerm *p) {

    struct politerm *q;
   
    if (p == NULL)
        return p;
    q = p;
    p = p->next;
    free(q);
    return p;
}


/*Funcion que permite eliminar un termino en el polinomio al final de este
 *
 */
 
struct politerm *Deletfin(struct politerm *p) {

    struct politerm *q;

    if (p == NULL)
        return p;
    if (p->next == NULL) {
        free(p);
        return NULL;
    }
    q = p;
    while (q->next->next != NULL){
	    q = q->next;
    }
    free(q->next);
    q->next = NULL;
    return p;
}  

/*Funcion que permite leer un polinomio
 *
 */

struct politerm *leerpol(){
	struct politerm *z;
	unsigned e;
	float r;
	float i;
	z = Iniciarpol ( z ) ;
	printf ("Escriba los termino de su polinomio de forma que los exponentes sean acendente, de forma real espacio imaginario espacio exponente del termino, para terminar poner 0 0 0\n");
	scanf ("%f %f %d", &r, &i, &e);
	while (r != 0.0 || i != 0.0){
	    z = Insercomienzo(r, i, e, (z));
	    scanf ("%f %f %d", &r, &i, &e);
	}
	return z;
}

/*Funcion que permite escribir un polinomio
 *
 */

void escribirpol(struct politerm *s) {

    struct politerm *g;
    g = s;
   
    while  (g != NULL){
    	if (g->next == NULL)
    	    if (g->exp == 0){
    	        if (g->coef.i < 0)
					printf("(%f  %fi)\n", g->coef.r, g->coef.i);
				else
					printf("(%f + %fi)\n", g->coef.r, g->coef.i);
    		}
    	    else{
    	    	if (g->coef.i < 0)
    	    		printf("(%f  %fi)X^%d\n", g->coef.r, g->coef.i, g->exp); 
				else
			    	printf("(%f + %fi)X^%d\n", g->coef.r, g->coef.i, g->exp);  
			}
		else{
			if (g->coef.i < 0)
				printf("(%f  %fi)X^%d + ", g->coef.r, g->coef.i, g->exp);
			else
		    	printf("(%f + %fi)X^%d + ", g->coef.r, g->coef.i, g->exp);
		}
	g = g->next;
	}
    
}  

/*Funcion que permite evaluar un polinomio dandole un complejo escribiendo el resultado en la pantalla
 *
 */

void evpc(struct politerm *p){
	struct politerm *q;
    float auxi, auxr, r, i, ci, cr;
    unsigned int s;
	printf("Escriba el complejo que quiere evaluar en el polinomio de forma parte real espacio parte imaginaria\n");
    scanf ("%f %f", &r, &i);
    q = p;
    ci = 0;
    cr = 0;
    auxi = i;
    auxr = r;
    s = 1;
    
    if (r != 0 || i != 0){
    	while (q != NULL ){
    	    if	(q->exp > 2){
    	    	for (s < q->exp ; s = s+1;){
    	    		auxr = auxr * r - auxi * i;
    	    		auxi = auxi * r + auxr * i;
				}
		        ci = q->coef.i * auxr + auxi * q->coef.r + ci;
		        cr = q->coef.r * auxr - auxi * q->coef.i + cr;
		        auxr = r;
		        auxi = i;
			}
			else{
				if (q->exp == 0){
					ci = ci + q->coef.i;
					cr = cr + q->coef.r;
			    }	
			    else{
			    	ci = q->coef.i * r + i * q->coef.r + ci;
		            cr = q->coef.r * r - i * q->coef.i + cr;
				}
			}
		q = q->next;
        }
    }
    printf ("El polinomio evaluado en (%f + %fi) es (%f + %fi)\n", r, i , cr, ci);
}

 /*Funcion que permite sumar dos complejos
 *
 */

struct politerm *sumpol(struct politerm *p, struct politerm *q) {
    struct politerm *z, *x, *y, *w, *e;
    float r,i;
    x = p;
    y = q;
    z = Iniciarpol (z);
    
    if (x == NULL && y == NULL) {
        printf("Ambos polinomios son 0 o vacio");
        return z;
    }
    
    while(x != NULL ||  y != NULL){
    	if (x->exp > y->exp || y == NULL){
    		r = x->coef.r;
    		i = x->coef.i;
			z = Insercomienzo(r, i, x->exp, (z));
			x = x->next;
		}
		else {
			if (y->exp > x->exp || x == NULL){
				r = y->coef.r + 0;
    			i = y->coef.i + 0;
				z = Insercomienzo(r, i, y->exp, (z));
				y = y->next;
			}
			else{
				if (x->exp == y->exp){
    				if (x->coef.r + y->coef.r != 0 || x->coef.i + y->coef.i != 0){
    					r = x->coef.r + y->coef.r;
    					i = x->coef.i + y->coef.i;
    					z = Insercomienzo(r, i, x->exp, (z));
					}	
				x = x->next;
				y = y->next;
				}
		   	}
		}
	}
	
	w = Iniciarpol (w);
	w = z;
		e = Iniciarpol (e);
	while (w != NULL){
			e = Insercomienzo(w->coef.r, w->coef.i, w->exp, (e));
			w = w->next;
	}
	return e;
}

/*Funcion que permite restar dos complejos
 *
 */

struct politerm *respol(struct politerm *p, struct politerm *q) {
    struct politerm *z, *x, *y, *w, *e;
    float r,i;
    x = p;
    y = q;
    z = Iniciarpol (z);
    
    if (x == NULL && y == NULL) {
        printf("Ambos polinomios son 0 o vacio");
        return z;
    }
    
    while(x != NULL ||  y != NULL){
    	if (x->exp == y->exp){
    		if (x->coef.r - y->coef.r != 0 || x->coef.i - y->coef.i != 0){
    			r = x->coef.r - y->coef.r;
    			i = x->coef.i - y->coef.i;
    			z = Insercomienzo(r, i, x->exp, (z));
				}
			x = x->next;
			y = y->next;
		}
		else {
			if (x->exp > y->exp || y == NULL){
				z = Insercomienzo(x->coef.r, x->coef.i, x->exp, (z));
				x = x->next;
			}
			else{
				if (y->exp > x->exp || x == NULL){
				z = Insercomienzo(-y->coef.r, -y->coef.i, y->exp, (z));
				y = y->next;
		   		}
			}
		}
	}
	w = Iniciarpol (w);
	w = z;
	e = Iniciarpol (e);
	while (w != NULL){
			e = Insercomienzo(w->coef.r, w->coef.i, w->exp, (e));
			w = w->next;
	}
	return e;
}

/*Funcion que permite multiplicar dos complejos
 *
 */

struct politerm *mulpol(struct politerm *p, struct politerm *q) {
	struct politerm *z, *x, *y, *w, *e;
	float r, i;
	unsigned int ex;
	y = Iniciarpol(y);
	z = p;
	x = q;
	while (x ==NULL){
		while (z==p){
			ex = z->exp*x->exp;
			r = x->coef.r * z->coef.r - x->coef.i * z->coef.i;
    		i = x->coef.i * z->coef.r + z->coef.i * x->coef.r;
    		y = Insercomienzo(r, i, ex, (y));
    		z=z->next;
		}
		z = p;
		x = x->next;
	}
	w = Iniciarpol (w);
	w = z;
	e = Iniciarpol (e);
	while (w != NULL){
			e = Insercomienzo(w->coef.r, w->coef.i, w->exp, (e));
			w = w->next;
	}
	return e;
}
