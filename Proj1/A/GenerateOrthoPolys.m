function [ polys, gamma ] = GenerateOrthoPolys( n)
%GenerateOrthoPolys generiert Orthogonalpolynome auf dem Intervall [-1,1]
%bis Grad n+1 nach der Vorschrift aus Satz 4.23 
%Weiters wird ein Vektor beta[1:n+1], der beta0 bis betan aus dem Satz
%beinhaltet
%Weiters wird ein Vektor gamma[1:n], der gamma1 bis betan aus dem Satz
%beinhaltet


polys = zeros(n+2,n+2);
gamma = zeros(1, n+1);

x(1) = 1;
x(2) = 0;

polys(1,end) = 1;
polys(2,end-1) = 1;

r = polyint(conv(polys(1,:),polys(1,:)));   %skalarprodukt poly0,poly0
r = diff(polyval(r,[-1 1]));

polys(2,end) = 0;%beta = 0 für [-1,1]

for i = 2:n+1
    rold = r;                                   %skalarprodukt polyi-1,polyi-1
    r = polyint(conv(polys(i,:),polys(i,:)));   %skalarprodukt polyi,polyi
    r = diff(polyval(r,[-1 1]));
    
    gamma(i) = r/rold;                          %use gamma² internally
    tmp = conv(x, polys(i, :));                 %tmp longer than poly-length => truncate in next line
    polys(i+1,:) = tmp(2:end) - gamma(i)*polys(i-1, :); % calculate as per recursion def
end

gamma = sqrt(gamma(2:end));

end

