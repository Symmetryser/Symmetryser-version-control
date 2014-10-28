%% Szabv�nyos�tott norma sz�m�t�sa

% V0,1,2=A*Va,b,c
 A=(1/3)*[1,                1,                  1;...
          1,      exp(1i*120),        exp(1i*240);...
          1,      exp(1i*240),       exp(1i*120)];
 
 n=size(V.signals.values(:,1),1); 
 
 Vrms_c = complex(Vrms.signals.values);
 V_real = zeros(3,n)';
 V_012  = zeros(3,n)';
 Ax     = zeros(1,n)';
 A0x    = zeros(3,n)';
 
for s=1 : n
    
    V_real(s,1)=exp(1i*szogt(s,1));
    V_real(s,2)=exp(1i*szogt(s,2));
    V_real(s,3)=exp(1i*szogt(s,3));
    
end

for s=1 : n
      V_real(s,1)=V_real(s,1).*Vrms_c(s,1);
      V_real(s,2)=V_real(s,2).*Vrms_c(s,2);
      V_real(s,3)=V_real(s,3).*Vrms_c(s,3);
end   

for s=1 : n
    V_012(s,:)=A*V_real(s,:)';
    
    Ax(s,1)=abs(V_012(s,3))/abs(V_012(s,2));
    A0x(s,1)=V_012(s,1)/V_012(s,2);
end

figure
        subplot(3,1,1)
        %Connection Voltage RMS
        plot(Vrms.time,Ax),grid on
        title('Regulated asymmetry norm')
        xlabel('t')
        ylabel('A_x')
        subplot(3,1,2)
        %Connection Current RMS
        plot(Vrms.time,A0x(:,1)),grid on
        title('Regulated zero asymmetry norm')
        xlabel('t')
        ylabel('A_{0x}')
        subplot(3,1,3)
        %Connection Current RMS
        plot(Vrms.time,Error_Space), grid on
        title('Geomerty asymmetry norm')
        xlabel('t')
        ylabel('A_g')
        
        figure
        plot(Vrms.time,(Ax-min(Ax))*200,Vrms.time,(Error_Space-min(Error_Space))),grid on
        title('Asymmetry norm')
        xlabel('t')
        ylabel('Norm')