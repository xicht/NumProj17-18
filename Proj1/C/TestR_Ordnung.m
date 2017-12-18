a=0;
b=1;
c=0;
d=5;
n=20;
l=10;

coeff1 = (1:2:2*n+3-l);
coeff2 = 3*(1:2:2*n+3-l);
p = @(x,y) polyval(coeff1,x)*polyval(coeff2,y);

h=(1:n);
approxIntegral = zeros(n,1);

integral = diff(polyval(polyint(coeff1),[a,b]))*diff(polyval(polyint(coeff2),[c,d]));

for i=1:n
    approxIntegral(i) = QuadraturR(i,[a b],[c d],p);
end


relError = abs(integral-approxIntegral)/abs(integral);


integral
approxIntegral
relError


figure(1)
semilogy(h,relError,'ro-','LineWidth',2,'MarkerSize',9)
hold on
semilogy(h,exp(-h.^1.3)*relError(1),'r:','LineWidth',2,'MarkerSize',9)
hold off