%%Inicialisation

n=size(V.signals.values(:,1),1); 
ErrorSpace=zeros(1,n);
% V0,1,2=A*Va,b,c
 A=(1/3)*[1,                1,                  1;...
          1,      exp(1i*120),        exp(1i*240);...
          1,      exp(1i*240),       exp(1i*120)];
 Vrms_c = complex(Vrms.signals.values);
 V_real = zeros(3,n)';
 V_012  = zeros(3,n)';
 Ax     = zeros(1,n)';
 A0x    = zeros(3,n)';
 
%% By geometry
for i=1 : n
        
        % Ideal parameters
        Amplitude_1=[230,230,230];                     %[V]
        Phase_1=[0,2/3*pi,4/3*pi];                     %[rad]
%        Frequency_1=[50,50,50];                       %[Hz]

        % Real parameters
        Amplitude_2=[Vrms.signals.values(i,1),...
                     Vrms.signals.values(i,2),...
                     Vrms.signals.values(i,3)];        %[V]
        Phase_2=[degtorad(szogt(i,1)),...
                 degtorad(szogt(i,3)),...
                 degtorad(szogt(i,3))];                %[rad]
%        Frequency_2=[50,50,50];                       %[Hz]

        %Extension of the vectors with the first element to get closed triangles on
        %plots and for use as polygons
        Amplitude_1_ex=[Amplitude_1 Amplitude_1(1)];
        Phase_1_ex=[Phase_1 Phase_1(1)];
        Amplitude_2_ex=[Amplitude_2 Amplitude_2(1)];
        Phase_2_ex=[Phase_2 Phase_2(1)];
        %Transforming to Cartesian coordinates
        [x1,y1] = pol2cart(Phase_1_ex,Amplitude_1_ex);
        [x2,y2] = pol2cart(Phase_2_ex,Amplitude_2_ex);

        [xb, yb] = polybool('intersection', x1, y1, x2, y2);
        ErrorSpace(i)=polyarea(xb,yb);
      
end
%% By regulation
for s=1 : n
    
    V_real(s,1)=exp(1i*szogt(s,1));
    V_real(s,2)=exp(1i*szogt(s,2));
    V_real(s,3)=exp(1i*szogt(s,3));
    

      V_real(s,1)=V_real(s,1).*Vrms_c(s,1);
      V_real(s,2)=V_real(s,2).*Vrms_c(s,2);
      V_real(s,3)=V_real(s,3).*Vrms_c(s,3);

    V_012(s,:)=A*V_real(s,:)';
    
    Ax(s,1)=abs(V_012(s,3))/abs(V_012(s,2));
    A0x(s,1)=V_012(s,1)/V_012(s,2);
end

figure
plot(Vrms.time,ErrorSpace), grid on

figure
        subplot(2,1,1)
        %Connection Voltage RMS
        plot(Vrms.time,Ax),grid on
        title('Regulated asymmetry norm')
        xlabel('t')
        ylabel('A_x')
        subplot(2,1,2)
        %Connection Current RMS
        plot(Vrms.time,A0x(:,1)),grid on
        title('Regulated zero asymmetry norm')
        xlabel('t')
        ylabel('A_{0x}')

figure
plot(Vrms.time,ErrorSpace,Vrms.time,Ax*250,Vrms.time,A0x*250), grid on
xlabel('t')
legend('Geometry','A_x*250','A_{0x}*250')