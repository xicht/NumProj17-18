syms x;
f = symfun(1/(1+x^2), x);
a = -20;
b = 20;
line = linspace(a,b);
f1 = f(line);
n = 30;

[samplePts1, forget] = GaussLegendre(1);
[samplePts1, forget] = Transformation(samplePts1, forget, [a b]);
[samplePts2, forget] = GaussLegendre(2);
[samplePts2, forget] = Transformation(samplePts2, forget, [a b]);
[samplePts5, forget] = GaussLegendre(5);
[samplePts5, forget] = Transformation(samplePts5, forget, [a b]);
[samplePts10, forget] = GaussLegendre(10);
[samplePts10, forget] = Transformation(samplePts10, forget, [a b]);
[samplePts20, forget] = GaussLegendre(20);
[samplePts20, forget] = Transformation(samplePts20, forget, [a b]);
[samplePts30, forget] = GaussLegendre(30);
[samplePts30, forget] = Transformation(samplePts30, forget, [a b]);

p1 = polyfit(samplePts1, double(f(samplePts1)),1);
p2 = polyfit(samplePts2, double(f(samplePts2)),2);
p5 = polyfit(samplePts5, double(f(samplePts5)),5);
p10 = polyfit(samplePts10, double(f(samplePts10)),10);
p20 = polyfit(samplePts20, double(f(samplePts20)),20);
p30 = polyfit(samplePts30, double(f(samplePts30)),30);

for i = 1:n
    integral(i) = Quadratur(i, [a b], f); 
end

figure
plot(line,f1)
hold on
plot(line,polyval(p5, line), '--')
plot(line,polyval(p10, line), '--')
plot(line,polyval(p20, line), '--')
plot(line,polyval(p30, line), '--')
hold off
legend('Runge-Funktion','P5','P10','P20','P30')

figure
bar(integral)
hold on
plot(0:n+1,ones(1,n+2)*double(3.041675862145907715642630809209813121214615238528091472153))
axis([0 n+1 -inf inf])
hold off