
amplitude_R=100;
amplitude_S=100;
amplitude_T=100;
phase_R=-1.586;
phase_S=0.5089;
phase_T=2.603;

  A=(1/3)*[1,                1,                  1;...
          1,      exp(1i*120/360*2*pi),        exp(1i*240/360*2*pi);...
          1,      exp(1i*240/360*2*pi),       exp(1i*120/360*2*pi)];
   
   V_real=complex([0,0,0]');
   V_012=complex([0,0,0]');
   V_real(1)=amplitude_R.*exp(1i*phase_R);
   V_real(2)=amplitude_S.*exp(1i*phase_S);
   V_real(3)=amplitude_T.*exp(1i*phase_T); 
   V_012=A*V_real;
   REG_norm=(abs(V_012(3))/abs(V_012(2)))*100;