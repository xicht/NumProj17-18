function [ polys, beta, gamma ] = GenerateOrthoPolys( n, a, b )
%GenerateOrthoPolys generiert Orthogonalpolynome auf dem Intervall [a,b] (dflt [-1,1])
%bis Grad n+1 nach der Vorschrift aus Satz 4.23 
%Weiters wird ein Vektor beta[1:n+1], der beta0 bis betan aus dem Satz
%beinhaltet
%Weiters wird ein Vektor gamma[1:n], der gamma1 bis betan aus dem Satz
%beinhaltet

if nargin < 3
    a = -1;
    b = 1;
end

polys = zeros(n+2,n+2);
beta = zeros(1, n+1);
gamma = zeros(1, n+1);

x(1) = 1;
x(2) = 0;

polys(1,end) = 1;
polys(2,end-1) = 1;
q = conv(conv(x,polys(1,:)),polys(1,:));    %skalarprodukt x*poly0,poly0
q = polyint(q);                             %skalarprodukt x*poly0,poly0
q = diff(polyval(q,[a b]));
r = polyint(conv(polys(1,:),polys(1,:)));   %skalarprodukt poly0,poly0
r = diff(polyval(r,[a b]));
beta(1) = q/r;

polys(2,end) = -beta(1);

for i = 2:n+1
    q = conv(conv(x,polys(i,:)),polys(i,:));    %skalarprodukt x*polyi,polyi
    q = polyint(q);                             %skalarprodukt x*polyi,polyi
    q = diff(polyval(q,[a b]));
    rold = r;                                   %skalarprodukt polyi-1,polyi-1
    r = polyint(conv(polys(i,:),polys(i,:)));   %skalarprodukt polyi,polyi
    r = diff(polyval(r,[a b]));
    
    beta(i) = q/r;
    gamma(i) = r/rold;                          %use gamma² internally
    tmp = conv(x, polys(i, :));
    polys(i+1,:) = tmp(2:end) - beta(i)*polys(i, :) - gamma(i)*polys(i-1, :); % calculate as per recursion def
end

gamma = sqrt(gamma(2:end));

end

