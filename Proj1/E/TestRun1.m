syms x y;

clearvars a;
f0 = symfun(1,[x y]);
f1 = symfun(x+y,[x y]);
f2 = symfun(x.^2 * y.^10,[x y]);
f3 = symfun(x.^17,[x y]);
f4 = symfun((x.^19)-(10*x.^10)+x-7,[x y]);
f5 = symfun(exp(x),[x y]);
f6 = symfun(exp(x.^2),[x y]);
f7 = symfun(sin(x)/(x-2),[x y]);


for i = 0:10
   a(:,i+1) = QuadraturDuffy(i,[0 1],[0 1],f0,f1,f2,f3,f4,f5,f6,f7);
end

a
