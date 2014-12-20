% Symmetriser power model initialization
clear all;
close all;

% parameters
Urms_Source=[230,230,230];
Phase_Source=[0,-2/3*pi,-4/3*pi];
%% FFT
s=zeros(1,128);
s(2)=1;
% s(4)=1;
% s(6)=1;
% s(8)=1;
% s(10)=1;
% s(12)=1;

%% Loads

R=100;
%L=0;
L=0.01125;
R_l=0.1;
%C=0;
C=5e-3;
R_c=0.005;


%% simulation parameters
CLK=1000;
tfin=0.5;
sample=10e-5;
paramNameValStruct.AbsTol         = '1e-9';
paramNameValStruct.RelTol         = '1e-9';
sim('Symmetry_REAL_TIME');

%% plotting

figure
%Voltage Source 
plot(V_conn.time,V_conn.signals.values(:,1),...
    V_conn.time,V_conn.signals.values(:,2),...
    V_conn.time,V_conn.signals.values(:,3))
grid on
title('Source Voltage')
xlabel('t')
ylabel('V')

figure
%Voltage Source 
plot(angle.time,angle.signals.values(:,1),...
    angle.time,angle.signals.values(:,2),...
    angle.time,angle.signals.values(:,3))
grid on
title('angle')
xlabel('t')
ylabel('rad')

figure
%Voltage Source 
plot(amplitude.time,amplitude.signals.values(:,1),...
    amplitude.time,amplitude.signals.values(:,2),...
    amplitude.time,amplitude.signals.values(:,3))
grid on
title('amplitude')
xlabel('t')
ylabel('V')

%Indicator norms
figure
plot(REG.time,REG.signals.values(:,1),...
     VEC.time,VEC.signals.values(:,1)*1e-3,...
     GEO.time,GEO.signals.values(:,1)*1e-3), grid on
xlabel('t')
legend('A_x','VEC*1e-2','GEO*1e-3')

% figure
% plot(REG.time,REG.signals.values(:,1)),grid on
% title('Regular norm')
% xlabel('t')
% ylabel('[%]')
% 
% figure 
% plot(VEC.time,VEC.signals.values(:,1)),grid on
% title('Vectorial norm')
% xlabel('t')
% ylabel('[%]')
% 
% figure
% plot(GEO.time,GEO.signals.values(:,1)),grid on
% title('Geometrial norm')
% xlabel('t')
% ylabel('[%]')
