a=-10;
b=100;
n=20;
m=4;
l=0;

steps = floor(n/m);

relError = zeros(steps,n+2);
approxIntegral = zeros(1,n+2);
h=(1:n+2);
for i = 1:steps
    coeff = ones(1,2*i*m+2);
    p = @(x) polyval(coeff,x);

    integral = diff(polyval(polyint(coeff),[a,b]));
    for k=1:n+2
        approxIntegral(k) = Quadratur(k,[a b],p);
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
legend('Grad 10','Grad 18','Grad 26','Grad 34','Grad 42')
axis([0 23 -inf inf])
xlabel({'Anzahl Quadraturknoten'})
ylabel({'Relativer Fehler'})