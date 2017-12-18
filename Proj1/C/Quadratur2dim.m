function [ retval ] = Quadratur2dim(n ,Interval1, Interval2, varargin )
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

[ samplePts, Weights ] = GaussLegendre(n);
samplePtsx = samplePtTransformation(samplePts, [a b]);  %Stützstellentransformation für x
samplePtsy = samplePtTransformation(samplePts, [c d]);  %Stützstellentransformation für y
Weightsx = WeightTransformation(Weights, [a b]); %Gewichte transformieren
Weightsy = WeightTransformation(Weights, [c d]); %Gewichte transformieren
retval = zeros(nargin-m,1);
for i = m+1:nargin
    %a=double(varargin{i-m}(samplePts));
    %b = a.*Weights;
    retval(i-m) = 0;
    for k = 1:n+1
        retval(i-m) = retval(i-m) + sum(double(varargin{i-m}(samplePtsx, samplePtsy(k))) .* Weightsx * Weightsy(k));
    end
end

end

