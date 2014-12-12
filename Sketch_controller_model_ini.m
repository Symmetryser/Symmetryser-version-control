% Symmetriser power model initialization
clear all;
close all;

%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=0.1;                                           %[s]
sample=10e-5;                                       %[s/sample]
t=0:sample:tfin;                                    %[tick]

%% Loads

R=100;
L=0;
%L=0.1125;
R_l=0.5;
C=0;
%C=5e-3;
R_c=0.005;

%% Transformator Station parameters
Urms_Source=[230,230,230];                          %[Vrms]
Source_Frequency=[50,50,50];                        %[Hz]
Phase_Source=[0,2/3*pi,4/3*pi];                     %[rad]
R_Source=[0.4, 0.4, 0.4];                           %[Ohm]
L_Source=[3.185e-3, 3.185e-3, 3.185e-3];            %[H]

%% Controller_ini
Butterworth_filter_order=8;
Butterworth_passband_frequency=5000;
R_paralell=1e5;


%% Simulation
        paramNameValStruct.AbsTol         = '1e-9';
        paramNameValStruct.RelTol         = '1e-9';
        sim('Sketch_controller_model');

%% Plotting
figure
plot(V.time,V.signals.values(:,1),...
     V.time,V.signals.values(:,2),...
     V.time,V.signals.values(:,3))
grid on
title('Voltage')
xlabel('t')
ylabel('V')

figure
plot(A_Cont.time,A_Cont.signals.values(:,1),...
     A_Cont.time,A_Cont.signals.values(:,2),...
     A_Cont.time,A_Cont.signals.values(:,3))
grid on
title('Control Current')
xlabel('t')
ylabel('A')

figure
plot(Angle.time,Angle.signals.values(:,1),...
     Angle.time,Angle.signals.values(:,2),...
     Angle.time,Angle.signals.values(:,3))
grid on
title('Voltage Angles')
xlabel('t')
ylabel('degree')