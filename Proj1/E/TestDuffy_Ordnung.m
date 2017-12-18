coeff = ones(1,27);
n=10;
h=(0:n);
m=13;

p00 = @(x,y) polyval(coeff(1:1),x)*polyval(coeff(1:1),y);
p10 = @(x,y) polyval(coeff(1:2),x)*polyval(coeff(1:1),y);
p01 = @(x,y) polyval(coeff(1:1),x)*polyval(coeff(1:2),y);
p11 = @(x,y) polyval(coeff(1:2),x)*polyval(coeff(1:2),y);
p21 = @(x,y) polyval(coeff(1:3),x)*polyval(coeff(1:2),y);
p22 = @(x,y) polyval(coeff(1:3),x)*polyval(coeff(1:3),y);
p31 = @(x,y) polyval(coeff(1:4),x)*polyval(coeff(1:2),y);
p32 = @(x,y) polyval(coeff(1:4),x)*polyval(coeff(1:3),y);
p33 = @(x,y) polyval(coeff(1:4),x)*polyval(coeff(1:4),y);
p55 = @(x,y) polyval(coeff(1:6),x)*polyval(coeff(1:6),y);
p77 = @(x,y) polyval(coeff(1:8),x)*polyval(coeff(1:8),y);
p99 = @(x,y) polyval(coeff(1:10),x)*polyval(coeff(1:10),y);
p2626 = @(x,y) polyval(coeff,x)*polyval(coeff,y);

integral = [1/2; 2/3; 2/3; 7/8; 39/40; 389/360; 31/30; 719/630; 2425/2016; 105959/79200; 284522297/201801600; 77574853697/53330659200; 2962823054383518074848008949865611/1884489985729451794412064265920000];

approxIntegral = zeros(m,n+1);
for i=1:n+1
    approxIntegral(:,i) = QuadraturDuffy(i-1,[0,1],[0,1],p00,p10,p01,p11,p21,p22,p31,p32,p33,p55,p77,p99,p2626);
end

relError = zeros(m,n+1);
for i=1:n+1
    relError(:,i) = abs(integral(:)-approxIntegral(:,i))./abs(integral);
end


integral
approxIntegral
relError

figure(1)
semilogy(h,relError(1,:),'x-','MarkerSize',3,'LineWidth',1,'MarkerSize',9)
hold on
for i = 2:2:13 
    semilogy(h,relError(i,:),'x-','MarkerSize',3,'LineWidth',1,'MarkerSize',9)
end
hold off
legend('Grad 0x0','Grad 0x1','Grad 2x1','Grad 3x1','Grad 3x3','Grad 7x7','Grad 26x26')
%axis([0 23 -inf inf])
xlabel({'Anzahl Quadraturknoten'})
ylabel({'Relativer Fehler'})