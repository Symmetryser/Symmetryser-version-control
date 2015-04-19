% Symmetriser power model initialization
clear all;
close all;
%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=20;                                           %[s]
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
%% Malfunctions
TransformerBreaker=[1e5,1e5,1e5;...                  %[Nullify RSTN line at given sim.time]
                    1e5,1e5,1e5];
NetworkBreaker=[1e5,1e5,1e5,1e5];                %[Break RSTN line at given sim.time]
%% Network parameters
R_Network=[0.4, 0.4, 0.4, 0.4];                     %[Ohm]
L_Network=[3.185e-3, 3.185e-3, 3.185e-3, 3.185e-3]; %[H]
C_Network=[0, 0, 0];                                %[F]

%% Loads
START_Load= [0.001,100,100;...                             
            100,0.001,100;...                            
            100,100,0.001];                          

%          %%Ohmic Loads%%%
          Load_R=[50,50,50];                         %[Ohm]

%          %%Inductive Loads%%%
          Load_RL=[35.35,   35.35,   35.35;...       %[Ohm]
                  0.1125,  0.1125,  0.1125];         %[H]

%          %%Capacitive Loads%%%
          Capacitive_Load_RC=[60e-3,  120e-3,  80e-3;...  %[Ohm]
                                1e-3, 5e-3, 3e-3];  %[F]
         

%% Controller
k_symmetrcal_gain=1e2;                              %[Gain of symmetrycal]
PV_Power_Capacity=2e4;
PowerGain=[1e-5,1e-5,0];
Start_Control=1;
P_gain=0.00001;
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