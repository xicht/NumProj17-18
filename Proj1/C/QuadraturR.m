function [ retval ] = QuadraturR(n ,Interval1, Interval2, varargin )
%QUADRATUR führt Quadratur mit n+1 x n+1 Stützstellen auf Intervall [a,b]x[c,d] durch.
%Es kann eine beliebige Anzahl Funktionen oder symbolischen Funktionen
%übergeben werden.
%Gibt Ergebnisse als Vektor zurück.

m = 3;
assert(isvector(Interval1));
assert(isvector(Interval2));
a = Interval1(1);
b = Interval1(2);
c = Interval2(1);
d = Interval2(2);

assert(a<b);
assert(c<d);
assert(nargin > 3);

[ samplePts, weights ] = GaussLegendre(n);
[ samplePtsx, weightsx ] = Transformation(samplePts,weights, [a b]);  %Stützstellentransformation für x
[ samplePtsy, weightsy ] = Transformation(samplePts,weights, [c d]);  %Stützstellentransformation für y


retval = zeros(nargin-m,1);
for i = m+1:nargin
    retval(i-m) = 0;
    for k = 1:n+1
        retval(i-m) = retval(i-m) + sum(double(varargin{i-m}(samplePtsx, samplePtsy(k))).* weightsx)*weightsy(k);
    end
end

end

