syms x
f0 = symfun(1,x);
f1 = symfun(x,x);
f2 = symfun(x.^2,x);
f3 = symfun(x.^17,x);
f4 = symfun((x.^19)-(10*x.^10)+x-7,x);
f5 = symfun(exp(x),x);
f6 = symfun(exp(x.^2),x);

a=0;
b=1;
n=30;

val=zeros(7,n+1);
for i = 0:n
   val(:,i+1) = Quadratur(i,[a b],f0,f1,f2,f3,f4,f5,f6);
end

val
