coeff = [1,1,1,1];

p00 = @(x,y) polyval(coeff(1:1),x)*polyval(coeff(1:1),y);
p10 = @(x,y) polyval(coeff(1:2),x)*polyval(coeff(1:1),y);
p01 = @(x,y) polyval(coeff(1:1),x)*polyval(coeff(1:2),y);
p11 = @(x,y) polyval(coeff(1:2),x)*polyval(coeff(1:2),y);
p21 = @(x,y) polyval(coeff(1:3),x)*polyval(coeff(1:2),y);
p22 = @(x,y) polyval(coeff(1:3),x)*polyval(coeff(1:3),y);
p31 = @(x,y) polyval(coeff(1:4),x)*polyval(coeff(1:2),y);
p32 = @(x,y) polyval(coeff(1:4),x)*polyval(coeff(1:3),y);
p33 = @(x,y) polyval(coeff(1:4),x)*polyval(coeff(1:4),y);

integral = [1/2; 2/3; 2/3; 7/8; 39/40; 389/360; 31/30; 719/630; 2425/2016];

approxIntegral = zeros(9,2);
approxIntegral(:,1) = QuadraturAmDreieckE(p00,p10,p01,p11,p21,p22,p31,p32,p33);
approxIntegral(:,2) = QuadraturAmDreieckK(p00,p10,p01,p11,p21,p22,p31,p32,p33);

relError1 = abs(integral-approxIntegral(:,1))./abs(integral);
relError2 = abs(integral-approxIntegral(:,2))./abs(integral);


integral
approxIntegral
relError1
relError2