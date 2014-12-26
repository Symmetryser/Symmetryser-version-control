% Symmetriser power model initialization
clear all;
close all;

%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=0.1;                                           %[s]
sample=10e-5;                                       %[s/sample]
t=0:sample:tfin;                                    %[tick]

%% Source parameters
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

%% Control_Current 
Butterworth_filter_order=8;
Butterworth_passband_frequency=5000;
% Control_Current_frequency=[20,     30,     40];       %[Hz]
% Control_Current_Amplitude=[0,     0,     0];       %[A]
% Control_Current_Phase=    [0,      2/3*pi, 4/3*pi];   %[rad]
% Control_Current_DC=       [0,      0,      0];        %[A]

%Input dialog
        prompt = {'Enter the 3 phase Control current frequencies:','Enter the 3 phase Control current amplitudes:','Enter the 3 phase Control current phases:','Enter the 3 phase Control current DC components:'};
        dlg_title = 'Control current parameters';
        num_lines = 1;
        defAns = {'50 50 50','0 0 0','0 2/3*pi 4/3*pi','0 0 0'};
        options = 'off';
        answer = inputdlg(prompt,dlg_title,num_lines,defAns,options);
        % Error handling
        for i=1:4
            if(max(size(str2num(answer{i})))~=3)
                errordlg('The control Current elements must consist of three scalars separated by space!')
            end
        end
        Control_Current_frequency = str2num(answer{1});       %[Hz]
        Control_Current_Amplitude = str2num(answer{2});       %[A]
        Control_Current_Phase = str2num(answer{3});   %[rad]
        Control_Current_DC = str2num(answer{4});        %[A]
        %%%Create parameter matrx%%%
        CC_mtx=[Control_Current_Amplitude', Control_Current_frequency',...
                Control_Current_Phase', Control_Current_DC'];
        %%% Generate Control_Current function %%%
        t=t';
        T=100;
        size_t=size(t);
        Control_Current.time=t;
        CC=[(CC_mtx(1,1)*sin(2*pi*CC_mtx(1,2)*t+CC_mtx(1,3))+CC_mtx(1,4)).*(1-exp(-t/T)),...
            (CC_mtx(2,1)*sin(2*pi*CC_mtx(2,2)*t+CC_mtx(2,3))+CC_mtx(2,4)).*(1-exp(-t/T)),...
            (CC_mtx(3,1)*sin(2*pi*CC_mtx(3,2)*t+CC_mtx(3,3))+CC_mtx(3,4)).*(1-exp(-t/T))];
        Control_Current.signals.values=CC;
%% Loads
R=100;
%L=0;
L=0.01125;
R_l=0.1;
%C=0;
C=5e-3;
R_c=0.005;
%% simulation parameters
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
