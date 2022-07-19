struct Complex{
   float realp, imagp;
};

struct ComplexList{
    int Exp;
    struct Complex val;
    struct ComplexList *sig;
};

struct Complex MaxCom(struct ComplexList *L);
struct Complex InitComplex(float r, float i);
struct Complex AddComplex(struct Complex a, struct Complex b);
struct Complex SubComplex(struct Complex a, struct Complex b);
struct Complex MulComplex(struct Complex a, struct Complex b);
struct Complex DivComplex(struct Complex a, struct Complex b);

void ShowComplex(struct Complex a);

struct ComplexList* CopyList(struct ComplexList *L);
struct ComplexList* DivList(struct ComplexList *Ld1, struct ComplexList *Ld2);
struct ComplexList* DivListComplex(struct ComplexList *Ld1, struct Complex C);
struct ComplexList* MulListComplex(struct ComplexList *Ld1, struct Complex C);
struct ComplexList* MultList(struct ComplexList *Ld1, struct Complex *Ld2);
struct ComplexList* SumList(struct ComplexList *Ld1, struct Complex *Ld2);
struct ComplexList* SubList(struct ComplexList *Ld1, struct Complex *Ld2);
struct ComplexList* InitList(struct ComplexList *N);
struct ComplexList* AddList(struct ComplexList *L, struct Complex a, int Pot);
struct ComplexList* Organize(struct ComplexList *L);
struct ComplexList* NoCeros(struct ComplexList *L);

void ShowComplexList(struct ComplexList *L);

int MaxExp(struct ComplexList *L);


struct Complex InitComplex(float r, float i){
    struct Complex N;
    N.realp = r;
    N.imagp = i;
    return N;
}

struct Complex AddComplex(struct Complex a, struct Complex b){
    struct Complex c;

    c.realp = a.realp + b.realp;
    c.imagp = a.imagp + b.imagp;

    return c;
}

struct Complex SubComplex(struct Complex a, struct Complex b){
    struct Complex c;

    c.realp = a.realp - b.realp;
    c.imagp = a.imagp - b.imagp;

    return c;
}

struct Complex MulComplex(struct Complex a, struct Complex b){
    struct Complex c;

    c.realp = a.realp*b.realp - a.imagp*b.imagp;
    c.imagp = a.realp*b.imagp + a.imagp*b.realp;

    return c;
}

struct Complex DivComplex(struct Complex a, struct Complex b){
    struct Complex c;

    c.realp = (a.realp*b.realp + a.imagp*b.imagp) / (b.imagp*b.imagp+b.realp*b.realp);
    c.imagp = (a.imagp*b.realp - a.realp*b.imagp) / (b.imagp*b.imagp+b.realp*b.realp);

    return c;
}

void ShowComplex(struct Complex a){
    printf("%f + %fi", a.realp, a.imagp);
}

struct ComplexList* InitList(struct ComplexList *N){
    N = NULL;
    return N;
}

struct ComplexList* AddList(struct ComplexList *L, struct Complex a, int Pot){
    struct ComplexList *N;
    N = calloc(1, sizeof(struct ComplexList));
    N->val = a;
    N->Exp = Pot;
    N->sig = L;
    if (N->sig){
        N = Organize(N);
    }
    N = NoCeros(N);
    return N;
}

struct ComplexList* CopyList(struct ComplexList *L){
    struct ComplexList *D, *t, *d;
    D = calloc(1, sizeof(struct ComplexList));
    d = D;
    t = L;
    while (t){
        d->Exp = t->Exp;
        d->val.realp = t->val.realp;
        d->val.imagp = t->val.imagp;
        d->sig = NULL;
        if (t->sig){
            d->sig = calloc(1, sizeof(struct ComplexList));
        }
        t = t->sig;
        d = d->sig;
    }
    return D;
}

int MaxExp(struct ComplexList *L){
    struct ComplexList *t = L;
    while (t->sig){
        t = t->sig;
    }
    return t->Exp;
}

struct Complex MaxCom(struct ComplexList *L){
    struct ComplexList *t = L;
    while (t->sig){
        t = t->sig;
    }
    return t->val;
}

struct ComplexList* DivList(struct ComplexList *Ld1, struct ComplexList *Ld2){
    struct ComplexList *Op1, *Op2, *R, *r, *m;
    if (MaxExp(Ld1) >= MaxExp(Ld2)){
        Op1 = CopyList(Ld1);
        Op2 = CopyList(Ld2);
        Op2 = DivListComplex(Ld2, MaxCom(Ld2));
        R = InitList(R);

        r = calloc(1, sizeof(struct ComplexList));
        r->sig = NULL;

        while (MaxExp(Op1) >= MaxExp(Op2)){
            r->val = MaxCom(Op1);
            r->Exp = MaxExp(Op1) - MaxExp(Op2);
            R = AddList(R, r->val, r->Exp);
            m = MultList(Op2, r);
            Op1 = SubList(Op1, m);
        }

        R = MulListComplex(R, MaxCom(Ld2));

        printf("Resto = ");
        ShowComplexList(Op1);

        return R;
    }else{
        printf("El exponente maximo del divisor debe ser menor que el del dividendo\n");
        return NULL;
    }
}

struct ComplexList* DivListComplex(struct ComplexList *Ld1, struct Complex C){
    struct ComplexList *R, *d;
    R = CopyList(Ld1);
    d = R;
    while (d){
        d->val = DivComplex(d->val, C);
        d = d->sig;
    }
    return R;
}

struct ComplexList* MulListComplex(struct ComplexList *Ld1, struct Complex C){
    struct ComplexList *R, *d;
    R = CopyList(Ld1);
    d = R;
    while (d){
        d->val = MulComplex(d->val, C);
        d = d->sig;
    }
    return R;
}

struct ComplexList* MultList(struct ComplexList *Ld1, struct Complex *Ld2){
    struct ComplexList *R, *L1, *L2;
    R = InitList(R);
    L1 = Ld1;
    while(L1){
        L2 = Ld2;
        while(L2){
            R = AddList(R, MulComplex(L1->val, L2->val), L1->Exp+L2->Exp);
            L2 = L2->sig;
        }
        L1 = L1->sig;
    }
    return R;
}

struct ComplexList* SumList(struct ComplexList *Ld1, struct Complex *Ld2){
    struct ComplexList *R, *L1, *L2;
    R = InitList(R);
    L1 = Ld1;
    while(L1){
        R = AddList(R, L1->val, L1->Exp);
        L1 = L1->sig;
    }
    L2 = Ld2;
    while(L2){
        R = AddList(R, L2->val, L2->Exp);
        L2 = L2->sig;
    }
    return R;
}

struct ComplexList* SubList(struct ComplexList *Ld1, struct Complex *Ld2){
    struct ComplexList *R, *L1, *L2;
    struct Complex T;

    R = InitList(R);

    L1 = Ld1;
    while(L1){
        R = AddList(R, L1->val, L1->Exp);
        L1 = L1->sig;
    }

    L2 = Ld2;
    while(L2){
        T.imagp = -1 * L2->val.imagp;
        T.realp = -1 * L2->val.realp;
        R = AddList(R, T, L2->Exp);
        L2 = L2->sig;
    }
    return R;
}

struct ComplexList* Organize(struct ComplexList *L){
    struct ComplexList *N, *t;
    if (L->Exp < L->sig->Exp){
        return L;
    }else if (L->Exp == L->sig->Exp){
        L->sig->val = AddComplex(L->val, L->sig->val);
        return L->sig;
    }else{
        t = L->sig;
        N = L->sig;
        while (N->sig && N->sig->Exp < L->Exp){
            N = N->sig;
        }

        if (N->sig && N->sig->Exp == L->Exp){
            N->sig->val = AddComplex(L->val, N->sig->val);
        }else{
            L->sig = N->sig;
            N->sig = L;
        }

        return t;
    }
}

struct ComplexList* NoCeros(struct ComplexList *L){
    struct ComplexList *N, *L1, *L2;

    while(L && L->val.imagp == 0 && L->val.realp == 0){
        L = L->sig;
    }
    N = L;
    if (N && N->sig){
        L1 = N;
        L2 = N->sig;
        while (L1->sig){
            if (L1->sig->val.imagp == 0 && L1->sig->val.realp == 0){
                L1->sig = L1->sig->sig;
            }else{
                L1 = L1->sig;
            }
        }
    }

    return N;
}

void ShowComplexList(struct ComplexList *L){
    struct ComplexList *t = L;

    while(t){
        printf("(");
        ShowComplex(t->val);
        printf(")x^(%i) ", t->Exp);
        if (t->sig){
            printf("+ ");
        }
        t = t->sig;
    }
    printf("\n");
}
