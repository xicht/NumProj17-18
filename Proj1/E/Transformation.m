function [ newSamplePts, newWeights ] = Transformation( samplePts, weights, interval )
%Transformiert Stützstellen von Intervall [-1, 1] auf [a b]

assert(isvector(interval));
assert(interval(1) < interval(2));
a = interval(1);
b = interval(2);

newSamplePts = (b+a + samplePts*(b-a)) /2;
newWeights = (b-a)/2*weights;

end

