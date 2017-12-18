f = @(x,y) exp(x-y);

integral = -1+(1/2)*exp(-1)+(1/2)*exp(1);
n=20;

h=(1:n);
approxIntegral = zeros(n,1);

for i=1:n
    approxIntegral(i) = QuadraturDuffy(i,[0 1],[0 1],f);
end

relError = abs(integral-approxIntegral)/abs(integral);

integral
approxIntegral
relError


figure(1)
semilogy(h,relError,'ro-','LineWidth',2,'MarkerSize',9)
hold on
semilogy(h,exp(-h.^1.8)*relError(1),'r:','LineWidth',2,'MarkerSize',9)
hold off