function [ retval ] = WeightTransformation( Weights, interval )
%Transformiert Gewichte für die Quadratur von Intervall [-1, 1] auf [a b]

assert(isvector(interval));
assert(interval(1) < interval(2));
a = interval(1);
b = interval(2);
retval = (Weights*(b-a)) /2;

end

