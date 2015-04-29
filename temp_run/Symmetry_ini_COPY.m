% Symmetriser power model initialization
clear all;
close all;
%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=100;                                           %[s]
sample=10e-5;                                       %[s/sample]
t=0:sample:tfin;                                    %[tick]
%% FFT
s=zeros(1,128);
s(2)=1;
%% Transformator Station parameters
Urms_Source=[230,230,230];                          %[Vrms]
Source_Frequency=[50,50,50];                        %[Hz]
Phase_Source=[0,-2/3*pi,-4/3*pi];                     %[rad]
R_Source=[0.4, 0.4, 0.4];                           %[Ohm]
L_Source=[3.185e-3, 3.185e-3, 3.185e-3];            %[H]

%% Control_Current 
Butterworth_filter_order=8;
Butterworth_passband_frequency=5000;
%% Network parameters
Network_lenght=[1,1,1,1,1,1];
Network_Wire_Resistance=0.4;
R_Network=[0.4, 0.4, 0.4, 0.4];                     %[Ohm]
L_Network=[3.185e-3, 3.185e-3, 3.185e-3, 3.185e-3]; %[H]
C_Network=[0, 0, 0];                                %[F]
%% Malfunction
TransformerBreaker=[1e5,1e5,1e5;...                  %[Nullify RSTN line at given sim.time]
                    1e5,1e5,1e5];
NetworkBreaker=[1e5,1e5,1e5,1e5];                %[Break RSTN line at given sim.time]
%% Loads
Load_Wire_Resistance=[0.1,0.2];                     %[Ohm]
Switch_Load_R= [1,0,0];                             %[Boolean]
Switch_Load_RL=[0,1,0];                             %[Boolean]
Switch_Load_RC=[0,0,1];                             %[Boolean]

START_Load_R= [0.001,100,100];                             %[Boolean in time]
START_Load_RL=[100,0.001,100];                             %[Boolean in time]
START_Load_RC=[100,100,0.001];                             %[Boolean in time]

%          %%Ohmic Loads%%%
          Load_R=[50,50,50];                         %[Ohm]

%          %%Inductive Loads%%%
          Load_RL=[35.35,   35.35,   35.35;...       %[Ohm]
                  0.1125,  0.1125,  0.1125];         %[H]

%          %%Capacitive Loads%%%
          Capacitive_Load_R_RC=[60e-3,  120e-3,  80e-3;...  %[Ohm]
                                3e-3, 15e-3, 9e-3];  %[F]
         

%% Controller
k_symmetrcal_gain=1e2;                              %[Gain of symmetrycal]
PV_Power_Capacity=2e4;
PowerGain=[1e-5,1e-5,0];
Start_Control=1;
P_gain=5e-5;                                     %[divide by 10 if simulating malfunction]
stair_sample=0.02;
mask_sample=0.1;
switch_sample=0.02;
step_size =     [1,1,1,...          %amp[A]
                 0.08,0.08,0.08];   %phase[rad]
test_step =     [0.5,0.5,0.5,...    %amp[A]
                 0.02,0.02,0.02];      %phase[rad]   
initial_value = [0.00,0.00,0.00,... %amp[A]
                 0,0,0];            %phase[rad]

amp_feedback_saturation=400;
phase_feedback_saturation=pi;

%% Simulation
        paramNameValStruct.AbsTol         = '1e-9';
        paramNameValStruct.RelTol         = '1e-9';
        set_param('Symmetry_Inverter_imagined','IgnoredZcDiagnostic','none');
        sim('Symmetry_Inverter_imagined');

h = msgbox('Operation Completed','Success');