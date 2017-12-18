syms x;

f0 = symfun(1,[x]);
f1 = symfun(x,[x]);
f2 = symfun(x.^2,[x]);
f3 = symfun(x.^17,[x]);
f4 = symfun((x.^19)-(10*x.^10)+x-7,[x]);
f5 = symfun(exp(x),[x]);
f6 = symfun(exp(x.^2),[x]);
f7 = symfun(sin(x)/(x-2),[x]);


for i = 0:20
   a(:,i+1) = Quadratur(i,-1,1,f0,f1,f2,f3,f4,f5,f6,f7);
end

a
