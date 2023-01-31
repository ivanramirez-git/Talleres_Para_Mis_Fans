% %  Capítulo 1.1
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%MÁXIMOS Y MÍNIMOS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% 
% %Ejemplo: Encontrar el máximo y el mínimo para la función
% %f(x)=5cos(2x)-2xsen(2x) en el intervalo [1,2]
% %  Definimos una función f(x) anonima, es decir una función que se almacena como datos.@x se usa para definir una variable independiente o argumento de entrada de la función.
% 
% f=@(x)5*cos(2*x)-2*x*sin(2*x);
% 
% 
% %  Graficamos la función en el intervalo [0.5,2]
% 
% figure %  Graficamos la función en el intervalo [0.5,2]. figure crea un espacio u objeto.
% figure(1)
% fplot(f,[0.5,2])
% 
% g=@(x)-12*sin(2*x)-4*x*cos(2*x); %  Definimos la derivada de función.
% 
% p=fzero(g,[1,2]) %  El comando fzero permite encontrar los valores donde f'(x)=0 o g(x)=0 en el intervalo [1,2]
% 
% % Para incrementar el número de digitos de 5 a 16 usamos:
% format long
% p
% 
% % El máximo y mínimo absoluto de la función f(x) en el intervalo [1,2] debe
% % ocurrir en los extremos o en los puntos donde la primera de la función
% % =0, es decir en x=1, x=p, or x=2. Evaluamos la función en dichos puntos.
% f(1)
% f(p)
% f(2)
% 
% %  Mínimo absoluto de f(x) en [1,2] is -5.675301337592883.
% %  El máximo absoluto de f(x) on [1,2] es -0.241008123086347

%%%%%%%%%%%%%%%%%%%%%%%%%% POLINOMIOS DE TAYLOR%%%%%%%%%%%%%%%%%%%%%%%
%The default expansion point is 0 (x0=0). To specify a different expansion point, use ExpansionPoint.


% Si f(x)=cos x y x0 = 0. Determiar el segundo polinomio de Taylor para f
% alrededor de x0; y el tercer polinomio de Taylor para f alrededor de x0.

%definimos la función f(x)=cos(x)
syms x;

% f=@(x)cos(x);
% T2=taylor(cos(x),'Order',3); %Calculamor el polinomio de Taylos haciendo uso de 'order' n-1, orden 2
% T3=taylor(cos(x),'Order',4); %Calculamor el polinomio de Taylos haciendo uso de 'order' n-1, orden 3
% fplot(f, [-pi,pi]) %Grafica la función entre -pi y pi
% hold on;           %Mantiene el objeto figura para superponer las graficas
% fplot(T2, [-pi,pi])%Grafica el segundo polinomio de taylor
% hold on;
% fplot(T3, [-pi,pi])%Grafica el tercer polinomio de taylor
% 
% 
% %  Calculamos el valor para x=0.01 en f(x) y en el polinomio de taylor
% 
% y1=f(0.01);          
% y2=vpa(subs(T2,x,0.01)); %Variable precision arithmetic.
% 
% err=abs(y1-y2)

%%%%%%%%%%%%%CALCULO DEL ERRO MEDIANTE MATLAB%%%%%%%%%%%%%%%%%

% f1=cos(x)
% T=taylor(cos(x),'Order',3);
% 
% syms c;
% 
% fn(c)=subs(diff(cos(x),4),x,c);
% Rupper=x^4/factorial(4);
% 
% Rmax=vpa(subs(Rupper,x,0.01)); %Error máximo.
% 
% err2=abs(y1-Rmax)

%%%%%%%%%%%%%%%%%%CALCULO DE LA INTEGRAL MEDIANTE APROXIMACION%%%%%%%%%%%%%

% %  Podemos calcular la integral mediante el comando quad 
% q1 = quad('cos(x)',0.0,0.1)
% q2 = quad('1-x.^2/2',0.0,0.1)
% 
% %  Calculando el error:
% errin = abs(q1-q2)



%TAREA
%Encuentre el segundo polinomio de Taylor P2(x) para la función f (x) = e^xcos(x) alrededor de x0 = 0. 
%Use P2(0.5) para aproximar f(0.5). 
%Encuentre un límite superior para el error | f (0.5) − P2(0.5)| por medio de la fórmula de error y compárela con el error real.
%Aproxime /int f(x)dx entre [0,0.1] por medio de int P2(x)dx.

% Solución:

% 1. Definimos la función f(x)=e^xcos(x)

f=@(x)exp(x)*cos(x);

% 2. Calculamos el polinomio de Taylor de orden 2 alrededor de x0=0

T2=taylor(f(x),'Order',3);

% 3. Calculamos el valor de P2(0.5)

P2=vpa(subs(T2,x,0.5));

% 4. Calculamos el error real

err=abs(f(0.5)-P2);

% 5. Calculamos el error máximo

syms c;

fn(c)=subs(diff(exp(x)*cos(x),4),x,c);

Rupper=x^4/factorial(4);

Rmax=vpa(subs(Rupper,x,0.5));

% 6. Calculamos el error por medio de la fórmula de error

err2=abs(Rmax/24);

% 7. Calculamos la integral de f(x)dx entre [0,0.1]

q1 = quad('exp(x)*cos(x)',0.0,0.1);

% 8. Calculamos la integral de P2(x)dx entre [0,0.1]

q2 = quad('exp(x)*cos(x)',0.0,0.1);

% 9. Calculamos el error de la integral

errin = abs(q1-q2);

% 10. Imprimimos los resultados

fprintf('El valor de P2(0.5) es: %f y el error real es: %f y el error máximo es: %f y el error por medio de la fórmula de error es: %f y el error de la integral es: %f',P2,err,Rmax,err2,errin)



