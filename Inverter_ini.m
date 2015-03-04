% Symmetriser power model initialization
clear all;
close all;

%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=0.02;                                           %[s]
sample=10e-5;                                       %[s/sample]
t=0:sample:tfin;                                    %[tick]

%% Inverter
Bridge_Inductances=4e-3;
Current_Comparator_Frequencys=1e-6;
Buffer_Capacitance=10e-3;
Buffer_Initial_Voltage=600;

IGBT_Ron=1e-6;
IGBT_Rs=1e5;
IGBT_Cs=inf;



%% Simulation
        paramNameValStruct.AbsTol         = '1e-9';
        paramNameValStruct.RelTol         = '1e-9';
        sim('Inverter');


%h = msgbox('Operation Completed','Success');

figure
plot(Inv_Currents.time,Inv_Currents.signals.values), grid on, legend('R','S','T'), title('Inverter currents')