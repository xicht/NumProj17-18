f = @(x,y) exp(x+y);

a=0;
b=10;
c=0;
d=20;
n=30;

h=(1:n);
approxIntegral = zeros(n,1);

for i=1:n
    approxIntegral(i) = QuadraturR(i,[a b],[c d],f);
end

integral = (f(b,0)-f(a,0))*(f(0,d)-f(0,c));

relError = abs(integral-approxIntegral)/abs(integral);

integral
approxIntegral
relError


figure(1)
semilogy(h,relError,'ro-','LineWidth',2,'MarkerSize',9)
hold on
semilogy(h,exp(-h.^1.4)*relError(1),'r:','LineWidth',2,'MarkerSize',9)
hold off



