syms x;
f = symfun(1/(1+x^2), x);

line = linspace(-5,5);
f1 = f(line);

[samplePts1, forget] = GaussLegendre(1);
[samplePts1, forget] = Transformation(samplePts1, forget, [-5 5]);
[samplePts2, forget] = GaussLegendre(2);
[samplePts2, forget] = Transformation(samplePts2, forget, [-5 5]);
[samplePts5, forget] = GaussLegendre(5);
[samplePts5, forget] = Transformation(samplePts5, forget, [-5 5]);
[samplePts10, forget] = GaussLegendre(10);
[samplePts10, forget] = Transformation(samplePts10, forget, [-5 5]);

p1 = polyfit(samplePts1, double(f(samplePts1)),1);
p2 = polyfit(samplePts2, double(f(samplePts2)),2);
p5 = polyfit(samplePts5, double(f(samplePts5)),5);
p10 = polyfit(samplePts10, double(f(samplePts10)),10);

for i = 1:10
    integral(i) = Quadratur(i, [-5 5], f); 
end

figure
plot(line,f1)
hold on
plot(line,polyval(p1, line), '--')
plot(line,polyval(p2, line), '--')
plot(line,polyval(p5, line), '--')
plot(line,polyval(p10, line), '--')
hold off
legend('Runge-Funktion','P1','P2','P5','P10')

figure
bar(integral)
hold on
plot(0:11,ones(1,12)*double(2.746801533890031721722543852889922297301999191799401617939))
hold off