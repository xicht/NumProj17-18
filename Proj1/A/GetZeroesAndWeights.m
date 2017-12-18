function [ zero, weights ] = GetZeroesAndWeights( beta, gamma, a, b )
%GetZeroesAndWeights 
%berechnet Nullstellen von Orthogonalpolynomen entsprechend Satz 4.23
%Erwartet beta[1:n+1](dh 0:n) und gamma[1:n] lt Satz 4.23 und
%entsprechendes intervall [a,b]

assert(a < b);
assert(isvector(beta));
assert(isvector(gamma));
assert(length(beta) >= length(gamma), 'gamma > beta');
assert(length(beta)-1 <= length(gamma), 'gamma < beta-1');

n = length(beta);
T = diag(beta) + diag(gamma(1:n-1),1) + diag(gamma(1:n-1),-1);  %baue Matrix

[eigvect, zeromatrix] = eig(T);
e = sum(eigvect.^2,1);              %vektorweise norm²
f = eigvect(1,:).^2;                %vektor erster komponenten der eigenvektoren
weights = (b-a) *f ./ e;            %annahme gewichtsfkt == 1
zero = diag(zeromatrix);            %Nullstellen liegen in der Diagonale

weights = reshape(weights, [length(weights),1]);

end

