function [ retval ] = Quadratur(n, Interval, varargin)
%QUADRATUR führt Quadratur mit n+1 Stützstellen auf Intervall [a,b] durch.
%Es kann eine beliebige Anzahl Funktionen oder symbolischen Funktionen
%übergeben werden.
%Gibt Ergebnisse als Vektor zurück.

m = 2;
a=Interval(1);
b=Interval(2);
assert(a<b);
assert(nargin > 2);

[ samplePts, weights ] = GaussLegendre(n);
[ samplePts, weights ] = Transformation(samplePts, weights, [a b]);

retval = zeros(nargin-m,1);

for i = m+1:nargin
    retval(i-m) = sum(double(varargin{i-m}(samplePts)).* weights);
end

end
