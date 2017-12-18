function [ samplePts, Weights ] = GaussLegendre( n, a, b )
%GAUSSLEGENDRE ruft GenerateOrthoPolys und GetZeroesAndWeights auf um die
%Ergebnisse von Satz 4.23 zurück zu geben
%n = gewünschte Anzahl der Abtastpunkte-1
%a,b = Intervall auf dem gearbeitet wird, default -1,1
%samplePts = Stützstellen
%Weights = Gewichte für die Quadratur

assert(n == floor(n));
assert(n >= 0);
if nargin < 3
    a = -1;
    b = 1;
end
assert(b > a);

[polys, beta, gamma] = GenerateOrthoPolys(n, a, b);
[samplePts, Weights] = GetZeroesAndWeights(beta, gamma, a, b);

end

