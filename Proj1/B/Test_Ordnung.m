a=-10;
b=100;
n=10;
l=0;

coeff = ones(1,2*n+2);
p = @(x) polyval(coeff,x);

h=(1:n+2);
approxIntegral = zeros(n,1);
relError = zeros(n,1);

integral = diff(polyval(polyint(coeff),[a,b]));

for i=1:n+2
    approxIntegral(i) = Quadratur(i,[a b],p);
end


relError = abs(integral-approxIntegral)/abs(integral);

integral
approxIntegral
relError


figure(1)
semilogy(h,relError,'ro-','LineWidth',2,'MarkerSize',9)
hold on
semilogy(h,exp(-h.^1.5)*relError(1),'r:','LineWidth',2,'MarkerSize',9)
hold off