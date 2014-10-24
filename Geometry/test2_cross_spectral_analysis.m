tfin=0.1;                                           %[s]
sample=10e-5;                                       %[s/sample]
t=0:sample:tfin; 

%t = 1 : 1000;
x=V.signals.values(:,1);
y=V.signals.values(:,2);
%x = sin(2*pi*t/15) + 0.5*sin(2*pi*t/5);
%y = 2*sin(2*pi*t/50) + 0.5*sin(2*pi*t/5+2*pi/5);
[Pxy,f] = cpsd(x,y,[],0,1024,1);
phase = angle(Pxy);
plot(f,phase), grid