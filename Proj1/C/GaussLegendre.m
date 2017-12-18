function [ zero, weights ] = GaussLegendre(n)
%GAUSSLEGENDRE berechnet Nullstellen und Gewichte von n+1-ten
%Legendre-Polynom nach Satz 4.23 über Eigenwertproblem
%n = gewünschte Anzahl der Abtastpunkte-1
%zero = Stützstellen
%weights = Gewichte für die Quadratur

assert(n == floor(n));
assert(n >= 0);

gamma = (1:n)./sqrt(4*((1:n).^2) -1);
T = diag(gamma,1) + diag(gamma,-1);  %baue Matrix

[eigvect, zeromatrix] = eig(T);
e = sum(eigvect.^2,1);              %vektorweise norm²
f = eigvect(1,:).^2;                %vektor erster komponenten der eigenvektoren
weights = 2*f./e;                   %annahme gewichtsfkt == 1
zero = diag(zeromatrix);            %Nullstellen liegen in der Diagonale

weights = reshape(weights, [length(weights),1]);

end

