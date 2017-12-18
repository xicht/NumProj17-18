function [ retval ] = Quadratur( n, a, b, varargin )
%QUADRATUR führt Quadratur mit n+1 Stützstellen auf Intervall [a,b] durch.
%Es kann eine beliebige Anzahl Funktionen oder symbolischen Funktionen
%übergeben werden.
%Gibt Ergebnisse als Vektor zurück.

assert(nargin > 3);
[ samplePts, Weights ] = GaussLegendre(n, a, b);
retval = zeros(nargin-3,1);
for i = 4:nargin
%    a=double(varargin{i-3}(samplePts));
%    b = a.*Weights;
    retval(i-3) = sum(double(varargin{i-3}(samplePts)) .* Weights);
end

end

