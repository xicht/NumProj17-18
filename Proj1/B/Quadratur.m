function [ retval ] = Quadratur( n,a,b, varargin )
%QUADRATUR f�hrt Quadratur mit n+1 St�tzstellen auf Intervall [-1, 1] durch.
%Es kann eine beliebige Anzahl Funktionen oder symbolischen Funktionen
%�bergeben werden.
%Gibt Ergebnisse als Vektor zur�ck.

m = 3;
assert(a<b);
assert(nargin > 3);
[ samplePts, Weights ] = GaussLegendre(n);
samplePts = samplePtTransformation(samplePts, [a b]);
Weights = WeightTransformation(Weights, [a b]);
retval = zeros(nargin-m,1);
for i = m+1:nargin
%    a=double(varargin{i-m}(samplePts));
%    b = a.*Weights;
    retval(i-m) = sum(double(varargin{i-m}(samplePts)) .* Weights);
end

end

