function [ retval ] = samplePtTransformation( samplePts, interval )
%Transformiert Stützstellen von Intervall [-1, 1] auf [a b]

assert(isvector(interval));
assert(interval(1) < interval(2));
a = interval(1);
b = interval(2);
retval = (b+a + samplePts*(b-a)) /2;

end

