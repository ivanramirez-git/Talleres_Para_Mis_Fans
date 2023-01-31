% Limpieza de variables
clear all;

%TAREA
%Encuentre el segundo polinomio de Taylor P2(x) para la función f (x) = e^xcos(x) alrededor de x0 = 0. 
%Use P2(0.5) para aproximar f(0.5). 
%Encuentre un límite superior para el error | f (0.5) − P2(0.5)| por medio de la fórmula de error y compárela con el error real.
%Aproxime /int f(x)dx entre [0,0.1] por medio de int P2(x)dx.

% Solución:
% definir x como variable simbolica
syms x;
% definir la funcion
f=@(x) exp(x).*cos(x); 
% encontrar el polinomio de taylor de orden 3 alrededor de x=0
T2=taylor(f(x),'Order',4,'ExpansionPoint',0); 
% evaluar el la funcion en x=0.5
y1=exp(0.5)*cos(0.5);
% evaluar el polinomio de taylor en x=0.5
y2=vpa(subs(T2,x,0.5));
% encontrar el error
error=abs(y1-y2);

% graficar la funcion
fplot(f,[0,1]);
hold on; % para que no se borre la grafica anterior
% graficar la serie de taylor
fplot(T2,[0,1]);