syms x y
f0 = symfun(1, [x,y]);
f1 = symfun(x.*y, [x,y]);
f2 = symfun(x.^2.*y, [x,y]);
f3 = symfun(x.^17, [x,y]);
f4 = symfun((x.^19)-(10*x.^10)+x-7, [x,y]);
f5 = symfun(exp(x), [x,y]);
f6 = symfun(exp(x.^2), [x,y]);

a=0;
b=1;
c=0;
d=1;
n=20;

val=zeros(7,n+1);
for i = 0:n
   val(:,i+1) = QuadraturR(i,[a b],[c d],f0,f1,f2,f3,f4,f5,f6);
end

val

