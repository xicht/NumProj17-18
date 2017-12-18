function [ samplePts, Weights ] = GaussLegendre( n)
%GAUSSLEGENDRE ruft GenerateOrthoPolys und GetZeroesAndWeights auf um die
%Ergebnisse von Satz 4.23 zurück zu geben
%Intervall ist [-1,1]
%n = gewünschte Anzahl der Abtastpunkte-1
%samplePts = Stützstellen
%Weights = Gewichte für die Quadratur

assert(n == floor(n));
assert(n >= 0);

%[polys, gamma] = GenerateOrthoPolys(n);
[samplePts, Weights] = GetZeroesAndWeights(n);

end

