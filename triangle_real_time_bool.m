%%Inicialisation
close all;

n=size(V.signals.values(:,1),1); 
ErrorSpace=zeros(1,n);
% V0,1,2=A*Va,b,c
 A=(1/3)*[1,                1,                  1;...
          1,      exp(1i*120/360*2*pi),        exp(1i*240/360*2*pi);...
          1,      exp(1i*240/360*2*pi),       exp(1i*120/360*2*pi)];
 Vrms_c = complex(Vrms.signals.values);
 N = zeros(1,n)';
 V_real = zeros(3,n)';
 V_012  = zeros(3,n)';
 Ax_    = zeros(1,n)';
 Ax     = zeros(1,n)';
 A0x    = zeros(3,n)';
 alpha  = zeros(1,n)';
 beta   = zeros(1,n)';
 U1     = zeros(1,n)';
 U2     = zeros(1,n)';
 

 
% By geometry

for i=1 : n
   tStart1=tic;     
        % Ideal parameters
        Amplitude_1=[230,230,230];                     %[V]
        Phase_1=[0,2/3*pi,4/3*pi];                     %[rad]
%        Frequency_1=[50,50,50];                       %[Hz]

        % Real parameters
        Amplitude_2=[Vrms.signals.values(i,:)];
        Phase_2=[degtorad(szogt(i,:))];

        %Extension of the vectors with the first element to get closed triangles on
        %plots and for use as polygons
        Amplitude_1_ex=[Amplitude_1 Amplitude_1(1)];
        Phase_1_ex=[Phase_1 Phase_1(1)];
        Amplitude_2_ex=[Amplitude_2 Amplitude_2(1)];
        Phase_2_ex=[Phase_2 Phase_2(1)];
        %Transforming to Cartesian coordinates
        [x1,y1] = pol2cart(Phase_1_ex,Amplitude_1_ex);
        [x2,y2] = pol2cart(Phase_2_ex,Amplitude_2_ex);
        [xa, ya] = polybool('union', x1, y1, x2, y2);
        [xb, yb] = polybool('intersection', x1, y1, x2, y2);
        ErrorSpace(i)=polyarea(xa,ya)-polyarea(xb,yb);
        
        
     tElapsed_Geom(i)=toc(tStart1); 
end

% By regulation

for s=1 : n
tStart2=tic;
%% 1#
      V_real(s,1)=Vrms_c(s,1).*exp(1i*szogt(s,1)/360*2*pi);
      V_real(s,2)=Vrms_c(s,2).*exp(1i*szogt(s,2)/360*2*pi);
      V_real(s,3)=Vrms_c(s,3).*exp(1i*szogt(s,3)/360*2*pi); 
    V_012(s,:)=A*V_real(s,:)';
    Ax(s,1)=(abs(V_012(s,3))/abs(V_012(s,2)))*100;
    A0x(s,1)=V_012(s,1)/V_012(s,2);
%% 2#
% U1(s,1)=(V_line.signals.values(s,1)+V_line.signals.values(s,2)*exp(1i*120)+V_line.signals.values(s,3)*exp(1i*-120))/3;
% U2(s,1)=(V_line.signals.values(s,1)+V_line.signals.values(s,2)*exp(1i*-120)+V_line.signals.values(s,3)*exp(1i*120))/3;

%% 3#
%     alpha(s,1)=acos((V.signals.values(s,1)^2+V.signals.values(s,2)^2+V_line.signals.values(s,1)^2)/...
%                (2*V.signals.values(s,1)*V.signals.values(s,2)));
%     beta(s,1)=acos((V.signals.values(s,2)^2+V.signals.values(s,3)^2+V_line.signals.values(s,2)^2)/...
%                    (2*V.signals.values(s,2)*V.signals.values(s,3)));

%     U1(s,1)=(1/3)*sqrt(V.signals.values(s,1)^2+V.signals.values(s,2)^2+V.signals.values(s,3)^2-...
%                   2*V.signals.values(s,1)*V.signals.values(s,2)*cos(alpha(s,1)+pi/3)-...
%                   2*V.signals.values(s,2)*V.signals.values(s,3)*cos(beta(s,1)+pi/3)-...
%                   2*V.signals.values(s,1)*V.signals.values(s,3)*cos(alpha(s,1)+beta(s,1)-pi/3));
%     U2(s,1)=(1/3)*sqrt(V.signals.values(s,1)^2+V.signals.values(s,2)^2+V.signals.values(s,3)^2-...
%                   2*V.signals.values(s,1)*V.signals.values(s,2)*cos(alpha(s,1)-pi/3)-...
%                   2*V.signals.values(s,2)*V.signals.values(s,3)*cos(beta(s,1)-pi/3)-...
%                   2*V.signals.values(s,1)*V.signals.values(s,3)*cos(alpha(s,1)+beta(s,1)+pi/3));
              
%     Ax_(s,1)=(abs(U2(s,1))/abs(U1(s,1)))*100;
%     Ax=Ax_;
    tElapsed_Regul(s)=toc(tStart2);
end



for p=1 : n
   tStart3=tic;
   
    R_error=230*exp(1j*0/360*2*pi)  -Vrms.signals.values*exp(1i*szogt(p,1)/360*2*pi);
    S_error=230*exp(1j*120/360*2*pi)-Vrms.signals.values*exp(1i*szogt(p,2)/360*2*pi);
    T_error=230*exp(1j*240/360*2*pi)-Vrms.signals.values*exp(1i*szogt(p,3)/360*2*pi);
   
    N(p)=R_error(p)*S_error(p)+R_error(p)*T_error(p)+S_error(p)*T_error(p);
    absN=abs(N);
    
    tElapsed_Vect(p)=toc(tStart3);
end


figure
plot(Vrms.time,ErrorSpace), grid on

figure
        subplot(4,1,1)
        %Connection Voltage RMS
        plot(Vrms.time,Ax),grid on
        title('Regulated asymmetry norm')
        xlabel('t')
        ylabel('A_x')
        subplot(4,1,2)
        %Connection Current RMS
        plot(Vrms.time,A0x(:,1)),grid on
        title('Regulated zero asymmetry norm')
        xlabel('t')
        ylabel('A_{0x}')
        subplot(4,1,3)
        %Connection Current RMS
        plot(Vrms.time,ErrorSpace), grid on
        title('Geometry asymmetry norm')
        xlabel('t')
        ylabel('Error aera')
        subplot(4,1,4)
        %Connection Current RMS
        plot(Vrms.time,absN),grid on
        title('Vector subtraction asymmetry norm')
        xlabel('t')
        ylabel('N')

figure
plot(Vrms.time,ErrorSpace*1e-3,Vrms.time,Ax,Vrms.time,absN*1e-2), grid on
xlabel('t')
legend('Geometry*1e-3','A_x','N*1e-2')

figure
subplot(2,1,1)
plot(ErrorSpace*1e-3,Ax,'x')
xlabel('ErrorSpace*1e-3')
ylabel('Ax')
subplot(2,1,2)
plot(absN*1e-2,Ax,'x')
xlabel('N*1e-2')
ylabel('Ax')


figure
plot(Vrms.time,tElapsed_Geom,Vrms.time,tElapsed_Regul,Vrms.time,tElapsed_Vect), grid on
title('Runtime')
xlabel('t(s)')
ylabel('runtime(s)')
legend('Geometry','Regulated','Vectorial')

%% Save

 prompt = {'Enter the START time of data log','Enter the END time of data log'};
        dlg_title = 'Logging parameters';
        num_lines = 1;
        defAns = {'0.8','1'};
        options = 'off';
        answer = inputdlg(prompt,dlg_title,num_lines,defAns,options);
        % Error handling
        if str2num(answer{2})>max(Vrms.time) 
                errordlg('Time out of time range!')
        end
        if str2num(answer{1})>=str2num(answer{2})
                errordlg('No valid range of data!')
        end
        
        logstart = str2num(answer{1})/sample;
        logend =  str2num(answer{2})/sample;

ErrorSpace_=[t(logstart:logend),ErrorSpace(logstart:logend)'*1e-4];
Ax_=[t(logstart:logend),Ax(logstart:logend)];
absN_=[t(logstart:logend),absN(logstart:logend)*1e-6];

save('Measurements/ErrorSpace.dat','ErrorSpace_','-ascii');
save('Measurements/Ax.dat','Ax_','-ascii');
save('Measurements/N.dat','absN_','-ascii');