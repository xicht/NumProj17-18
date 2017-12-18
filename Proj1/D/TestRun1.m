syms x y;

clearvars e k diff;
f0 = symfun(1,[x y]);
f1 = symfun(x+y,[x y]);
f2 = symfun(x*y,[x y]);
f3 = symfun(x^.2*y^.2,[x y]);
f4 = symfun(x^.2*y^.2 + x,[x y]);
f5 = symfun(exp(x),[x y]);
f6 = symfun(exp(x+y),[x y]);

e = QuadraturAmDreieckE(f0,f1,f2,f3,f4,f5,f6);
k = QuadraturAmDreieckK(f0,f1,f2,f3,f4,f5,f6);


e
k
diff = e-k
