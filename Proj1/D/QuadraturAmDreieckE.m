function [ retval ] = QuadraturAmDreieckE( varargin )
%QUADRATURAMDREIECKE 
%Quadratur am Einheitsdreieck, St�tzstellen an den Ecken
retval = zeros(nargin,1);
for i = 1:nargin
    retval(i) = (varargin{i}(0,0) + varargin{i}(1,0) + varargin{i}(0,1))/6;   
end

end

