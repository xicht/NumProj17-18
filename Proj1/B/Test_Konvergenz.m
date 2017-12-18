f = @(x) exp(x);

a=-5;
b=20;
n=30;

h=(1:n);
approxIntegral = zeros(n,1);
relError = zeros(n,1);

for i=1:n
    approxIntegral(i) = Quadratur(i,[a b],f);
end

integral = f(b)-f(a);

aprioriError1 = zeros(n,1);
aprioriError2 = zeros(n,1);

for i=1:n
    aprioriError1(i) = f(b)/factorial(2*i+2)*(b-a)^(2*i+3);
end

for i=1:n
    [samplePts, weights] = GaussLegendre(i);
    [samplePts, weights] = Transformation(samplePts,weights,[a b]);
    
    k = floor((i+1)/2);
    alphak = weights(k);
    xk = samplePts(k);
    aprioriError2(i) = f(b)/factorial(2*i+2)*(b-a)^2*alphak*prod((samplePts(xk~=abs(samplePts))-xk).^2);
end

relError = abs(integral-approxIntegral)/abs(integral);

integral
approxIntegral
relError
aprioriError1
aprioriError2

figure(1)
semilogy(h,relError,'rx-','LineWidth',2,'MarkerSize',9)
hold on
semilogy(h,aprioriError1,'b:','LineWidth',2,'MarkerSize',9)
semilogy(h,aprioriError2,'b--','LineWidth',2,'MarkerSize',9)
hold off
legend('Relativer Fehler Quadratur','Fehlerabschätzung 1','Fehlerabschätzung 2')
xlabel({'Anzahl Quadraturknoten'})
ylabel({'Relativer Fehler'})





