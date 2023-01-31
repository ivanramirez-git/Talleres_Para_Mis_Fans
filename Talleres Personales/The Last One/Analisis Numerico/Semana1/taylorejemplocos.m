%%%% TAYLOR %%%%%
syms x;
f=@(x) cos(x);
T2=taylor(cos(x),'Order',3); % Calcular la serie de Taylor de orden 3
fplot(f,[-pi,pi]); % Graficar la función
hold on;
fplot(T2,[-pi,pi]); % Graficar la serie de Taylor

y1=f(0.01);
y2=vpa(subs(T2,x,0.01));


error=abs(y1-y2);

% Imprimir el error
fprintf('El error es: %f ',error);