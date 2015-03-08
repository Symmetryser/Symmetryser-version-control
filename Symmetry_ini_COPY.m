% Symmetriser power model initialization
clear all;
close all;
%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=10;                                           %[s]
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
R_Network=[0.4, 0.4, 0.4, 0.4];                     %[Ohm]
L_Network=[3.185e-3, 3.185e-3, 3.185e-3, 3.185e-3]; %[H]
C_Network=[0, 0, 0];                                %[F]
% Network Loads
Load_Wire_Resistance=[0.1,0.2];                     %[Ohm]
Switch_Load_R= [1,0,0];                             %[Boolean]
Switch_Load_RL=[0,1,0];                             %[Boolean]
Switch_Load_RC=[0,0,1];                             %[Boolean]

START_Load_R= [0.001,100,100];                             %[Boolean in time]
START_Load_RL=[100,0.001,100];                             %[Boolean in time]
START_Load_RC=[100,100,0.001];                             %[Boolean in time]

%          %%Ohmic Loads%%%
          Load_R=[50,50,50];                         %[Ohm]
%          Ohmic_Load_Switching_Speed=[0.01,0.01,0.01];
%          Ohmic_Load_Switching_Sequence_=[randi([0 1],1,tfin/Ohmic_Load_Switching_Speed(1));...
%                                          randi([0 1],1,tfin/Ohmic_Load_Switching_Speed(2));...
%                                          randi([0 1],1,tfin/Ohmic_Load_Switching_Speed(3))];
%          %Ohmic_Load_Switching_Sequence=Ohmic_Load_Switching_Sequence_';
%          Ohmic_Load_Switching_Sequence=ones(3,tfin/Ohmic_Load_Switching_Speed(1))';
%          
%          %%Inductive Loads%%%
          Load_RL=[35.35,   35.35,   35.35;...       %[Ohm]
                  0.1125,  0.1125,  0.1125];         %[H]
%          Inductive_Load_Switching_Speed=[0.01,0.01,0.01];
%          Inductive_Load_Switching_Sequence_=[randi([0 1],1,tfin/Inductive_Load_Switching_Speed(1));...
%                                              randi([0 1],1,tfin/Inductive_Load_Switching_Speed(2));...
%                                              randi([0 1],1,tfin/Inductive_Load_Switching_Speed(3))];
%          %Inductive_Load_Switching_Sequence=Inductive_Load_Switching_Sequence_';
%          Inductive_Load_Switching_Sequence=ones(3,tfin/Inductive_Load_Switching_Speed(1))';
%          %%Capacitive Loads%%%
          Capacitive_Load_R_RC=[60e-3,  120e-3,  80e-3;...  %[Ohm]
                                1e-3, 5e-3, 3e-3];  %[F]
          Capacitive_Load_S_RC=[60e-3,  120e-3,  80e-3;...  %[Ohm]
                               1e-3, 5e-3, 3e-3];  %[F]
          Capacitive_Load_T_RC=[60e-3,  120e-3,  80e-3;...  %[Ohm]
                                1e-3, 5e-3, 3e-3];  %[F]
%          %%Randomised Switching Sequence%%%
%          Capacitive_Load_R_Switching_Speed=[0.1,0.1,0.1];%[s]
%          Capacitive_Load_S_Switching_Speed=[0.1,0.1,0.1];%[s]
%          Capacitive_Load_T_Switching_Speed=[0.1,0.1,0.1];%[s] 
%          
%          Capacitive_Load_R_Switching_Sequence_=[randi([0 1],1,tfin/Capacitive_Load_R_Switching_Speed(1));...
%                                                 randi([0 1],1,tfin/Capacitive_Load_R_Switching_Speed(2));...
%                                                 randi([0 1],1,tfin/Capacitive_Load_R_Switching_Speed(3))];
%          Capacitive_Load_S_Switching_Sequence_=[randi([0 1],1,tfin/Capacitive_Load_S_Switching_Speed(1));...
%                                                 randi([0 1],1,tfin/Capacitive_Load_S_Switching_Speed(2));...
%                                                 randi([0 1],1,tfin/Capacitive_Load_S_Switching_Speed(3))];
%          Capacitive_Load_T_Switching_Sequence_=[randi([0 1],1,tfin/Capacitive_Load_T_Switching_Speed(1));...
%                                                 randi([0 1],1,tfin/Capacitive_Load_T_Switching_Speed(2));...
%                                                 randi([0 1],1,tfin/Capacitive_Load_T_Switching_Speed(3))]; 
%                                      
%          Capacitive_Load_R_Switching_Sequence=Capacitive_Load_R_Switching_Sequence_';
%          Capacitive_Load_S_Switching_Sequence=Capacitive_Load_S_Switching_Sequence_';
%          Capacitive_Load_T_Switching_Sequence=Capacitive_Load_T_Switching_Sequence_';
%          
%          UsedCapacitanceR=(Capacitive_Load_R_Switching_Sequence(:,1)*Capacitive_Load_R_RC(2,1))+...
%                           (Capacitive_Load_R_Switching_Sequence(:,2)*Capacitive_Load_R_RC(2,2))+...
%                           (Capacitive_Load_R_Switching_Sequence(:,3)*Capacitive_Load_R_RC(2,3));
%          UsedCapacitanceS=(Capacitive_Load_S_Switching_Sequence(:,1)*Capacitive_Load_S_RC(2,1))+...
%                           (Capacitive_Load_S_Switching_Sequence(:,2)*Capacitive_Load_S_RC(2,2))+...
%                           (Capacitive_Load_S_Switching_Sequence(:,3)*Capacitive_Load_S_RC(2,3));
%          UsedCapacitanceT=(Capacitive_Load_T_Switching_Sequence(:,1)*Capacitive_Load_T_RC(2,1))+...
%                           (Capacitive_Load_T_Switching_Sequence(:,2)*Capacitive_Load_T_RC(2,2))+...
%                           (Capacitive_Load_T_Switching_Sequence(:,3)*Capacitive_Load_T_RC(2,3));
%          
%          Capacitive_Load_R_Switching_Sequence=ones(3,tfin/Capacitive_Load_R_Switching_Speed(1))';
%          Capacitive_Load_S_Switching_Sequence=ones(3,tfin/Capacitive_Load_R_Switching_Speed(1))';
%          Capacitive_Load_T_Switching_Sequence=ones(3,tfin/Capacitive_Load_R_Switching_Speed(1))';
                      

%% Inverter
Bridge_Inductances=4e-3;
Current_Comparator_Frequencys=5e-4;
Buffer_Capacitance=10e-3;
Buffer_Initial_Voltage=600;

%% Controller

PowerGain=5e-5;
Start_Control=1;
P_gain=0.00001;
stair_sample=0.02;
mask_sample=0.1;
switch_sample=0.02;
step_size =     [5,5,5,...          %amp[A]
                 0.36,0.36,0.36];   %phase[rad]
test_step =     [0.5,0.5,0.5,...    %amp[A]
                 0.02,0.02,0.02];      %phase[rad]   
initial_value = [0.00,0.00,0.00,... %amp[A]
                 0,0,0];            %phase[rad]

amp_feedback_saturation=400;
phase_feedback_saturation=pi;

%% %% Controller
% Start_Control=1;
% P_gain=0.0001;
% stair_sample=0.02;
% mask_sample=0.1;
% switch_sample=0.02;
% step_size =     [2,2,2,...          %amp[A]
%                  0.08,0.08,0.08];   %phase[rad]
% test_step =     [0.5,0.5,0.5,...    %amp[A]
%                  0.02,0.02,0.02];      %phase[rad]   
% initial_value = [0.00,0.00,0.00,... %amp[A]
%                  0,0,0];            %phase[rad]
% 
% amp_feedback_saturation=400;
% phase_feedback_saturation=pi;

%% Simulation
        paramNameValStruct.AbsTol         = '1e-9';
        paramNameValStruct.RelTol         = '1e-9';
        %feature('ModeIterationsInAlgLoops',0)
        %set_param('Symmetry_Inverter','AlgebraicLoopSolver','LineSearch')
        sim('Symmetry_Inverter_imagined');



h = msgbox('Operation Completed','Success');