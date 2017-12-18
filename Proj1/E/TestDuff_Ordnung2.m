a=0;
b=1;
c=0;
d=5;
n=20;
m=3;
l=0;

steps = floor(n/m);

relError = zeros(steps,n+2);
approxIntegral = zeros(1,n+2);
h=(1:n+2);
for i = 1:steps-1
    coeffx = ones(1,2*i*m+2);
    coeffy = ones(1,(2*n+2)-(2*i*m+2));
    p = @(x,y) polyval(coeffx,x)*polyval(coeffy,y);

    integral = diff(polyval(polyint(coeffx),[a,b]))*diff(polyval(polyint(coeffy),[c,d]));
    for k=1:n+2
        approxIntegral(k) = QuadraturR(k,[a b], [c,d],p);
    end
    relError(i,:) = abs(integral-approxIntegral)/abs(integral);
end


integral
approxIntegral
relError


figure(1)
semilogy(h,relError(1,:),'x-','MarkerSize',3,'LineWidth',1,'MarkerSize',9)
hold on
for i = 2:steps 
    semilogy(h,relError(i,:),'x-','MarkerSize',3,'LineWidth',1,'MarkerSize',9)
end
hold off
legend('Grad 8x34','Grad 14x28','Grad 20x22','Grad 26x16','Grad 32x10')
axis([0 23 -inf inf])
xlabel({'Anzahl Quadraturknoten'})
ylabel({'Relativer Fehler'})

