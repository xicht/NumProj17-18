function [ zero, weights ] = GetZeroesAndWeights(n)
%GetZeroesAndWeights 
%berechnet Nullstellen von Orthogonalpolynomen entsprechend Satz 4.23
%Erwartet Anzahl der samplepoints
%entsprechendes intervall [-1,1]

gamma = (1:n)./sqrt(4*((1:n).^2) -1);
T = diag(gamma,1) + diag(gamma,-1);  %baue Matrix

[eigvect, zeromatrix] = eig(T);
e = sum(eigvect.^2,1);              %vektorweise norm�
f = eigvect(1,:).^2;                %vektor erster komponenten der eigenvektoren
weights = 2 *f ./ e;            %annahme gewichtsfkt == 1
zero = diag(zeromatrix);            %Nullstellen liegen in der Diagonale

weights = reshape(weights, [length(weights),1]);

end

