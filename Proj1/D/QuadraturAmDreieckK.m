function [ retval ] = QuadraturAmDreieckK( varargin )
%QUADRATURAMDREIECKE 
%Quadratur am Einheitsdreieck, Stützstellen an den Kanten
retval = zeros(nargin,1);
for i = 1:nargin
    retval(i) = (varargin{i}(0.5,0) + varargin{i}(0.5,0.5) + varargin{i}(0,0.5))/6;   
end

end

