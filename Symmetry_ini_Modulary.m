% Symmetriser power model initialization
clear all;
close all;

% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=0.2;                                           %[s]
sample=10e-5;                                       %[s/sample]
t=0:sample:tfin;                                    %[tick]
%Load paramters
R_ref=50;
C_ref=20e-3;

R=100;
C=10e-3;
main_IO=1;
IO=[1,1,1];

Switching_Speed=0.01;
if (1/t(2))>=(tfin/2) 
    R=50;
    C=20e-3;
    IO(3)=0;
end

% Simulation
paramNameValStruct.AbsTol         = '1e-9';
paramNameValStruct.RelTol         = '1e-9';
sim('Modulary_loads');

figure
subplot(2,1,1)
plot(V)
grid on
title(' Voltage')
xlabel('t')
ylabel('Voltage')
subplot(2,1,2)
plot(V_RMS)
grid on
title('RMS Voltage')
xlabel('t')
ylabel('RMS Voltage')

figure
subplot(2,1,1)
plot(I)
grid on
title(' I')
xlabel('t')
ylabel('I')
subplot(2,1,2)
plot(Irms)
grid on
title('RMS I')
xlabel('t')
ylabel('RMS I')

figure
subplot(2,1,1)
plot(I_ref)
grid on
title(' I ref')
xlabel('t')
ylabel('I ref')
subplot(2,1,2)
plot(Irms_ref)
grid on
title('RMS I ref')
xlabel('t')
ylabel('RMS I ref')

