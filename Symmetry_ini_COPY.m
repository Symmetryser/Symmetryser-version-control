% Symmetriser power model initialization
clear all;
close all;

%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=2;                                           %[s]
sample=10e-5;                                       %[s/sample]
t=0:sample:tfin;                                    %[tick]
%% FFT
s=zeros(1,128);
s(2)=1;
% s(4)=1;
% s(6)=1;
% s(8)=1;
% s(10)=1;
% s(12)=1;
%% Transformator Station parameters
Urms_Source=[230,230,230];                          %[Vrms]
Source_Frequency=[50,50,50];                        %[Hz]
Phase_Source=[0,-2/3*pi,-4/3*pi];                     %[rad]
R_Source=[0.4, 0.4, 0.4];                           %[Ohm]
L_Source=[3.185e-3, 3.185e-3, 3.185e-3];            %[H]

%% Network parameters
R_Network=[0.4, 0.4, 0.4, 0.4];                     %[Ohm]
L_Network=[3.185e-3, 3.185e-3, 3.185e-3, 3.185e-3]; %[H]
C_Network=[0, 0, 0];                                %[F]

% %% Control_Current 
Butterworth_filter_order=8;
Butterworth_passband_frequency=5000;


%% Network Loads
Load_Wire_Resistance=[0.1,0.2];                     %[Ohm]
Switch_Load_R= [1,0,0];                             %[Boolean]
Switch_Load_RL=[0,1,0];                             %[Boolean]
Switch_Load_RC=[0,0,1];                             %[Boolean]

         %%%Ohmic Loads%%%
         Load_R=[50,50,50];                         %[Ohm]
         Ohmic_Load_Switching_Speed=[0.01,0.01,0.01];
         Ohmic_Load_Switching_Sequence_=[randi([0 1],1,tfin/Ohmic_Load_Switching_Speed(1));...
                                         randi([0 1],1,tfin/Ohmic_Load_Switching_Speed(2));...
                                         randi([0 1],1,tfin/Ohmic_Load_Switching_Speed(3))];
%          Ohmic_Load_Switching_Sequence=Ohmic_Load_Switching_Sequence_';
         Ohmic_Load_Switching_Sequence=ones(3,tfin/Ohmic_Load_Switching_Speed(1))';
         
         %%%Inductive Loads%%%
         Load_RL=[35.35,   35.35,   35.35;...       %[Ohm]
                 0.1125,  0.1125,  0.1125];         %[H]
         Inductive_Load_Switching_Speed=[0.01,0.01,0.01];
         Inductive_Load_Switching_Sequence_=[randi([0 1],1,tfin/Inductive_Load_Switching_Speed(1));...
                                             randi([0 1],1,tfin/Inductive_Load_Switching_Speed(2));...
                                             randi([0 1],1,tfin/Inductive_Load_Switching_Speed(3))];
         %Inductive_Load_Switching_Sequence=Inductive_Load_Switching_Sequence_';
         Inductive_Load_Switching_Sequence=ones(3,tfin/Inductive_Load_Switching_Speed(1))';
         %%%Capacitive Loads%%%
         Capacitive_Load_R_RC=[60e-3,  120e-3,  80e-3;...  %[Ohm]
                               1e-3, 5e-3, 3e-3];  %[F]
         Capacitive_Load_S_RC=[60e-3,  120e-3,  80e-3;...  %[Ohm]
                               1e-3, 5e-3, 3e-3];  %[F]
         Capacitive_Load_T_RC=[60e-3,  120e-3,  80e-3;...  %[Ohm]
                               1e-3, 5e-3, 3e-3];  %[F]
         %%%Randomised Switching Sequence%%%
         Capacitive_Load_R_Switching_Speed=[0.01,0.01,0.01];%[s]
         Capacitive_Load_S_Switching_Speed=[0.01,0.01,0.01];%[s]
         Capacitive_Load_T_Switching_Speed=[0.01,0.01,0.01];%[s]                  
         Capacitive_Load_R_Switching_Sequence_=[randi([0 1],1,tfin/Capacitive_Load_R_Switching_Speed(1));...
                                                randi([0 1],1,tfin/Capacitive_Load_R_Switching_Speed(2));...
                                                randi([0 1],1,tfin/Capacitive_Load_R_Switching_Speed(3))];
         Capacitive_Load_S_Switching_Sequence_=[randi([0 1],1,tfin/Capacitive_Load_S_Switching_Speed(1));...
                                                randi([0 1],1,tfin/Capacitive_Load_S_Switching_Speed(2));...
                                                randi([0 1],1,tfin/Capacitive_Load_S_Switching_Speed(3))];
         Capacitive_Load_T_Switching_Sequence_=[randi([0 1],1,tfin/Capacitive_Load_T_Switching_Speed(1));...
                                                randi([0 1],1,tfin/Capacitive_Load_T_Switching_Speed(2));...
                                                randi([0 1],1,tfin/Capacitive_Load_T_Switching_Speed(3))]; 
                                     
%          Capacitive_Load_R_Switching_Sequence_=[0, 1, 1, 1, 1, 1, 1, 1, 1, 1;...
%                                                 0, 0, 1, 1, 1, 1, 1, 1, 1, 0;...
%                                                 0, 0, 0, 1, 1, 1, 1, 1, 0, 0];
%          Capacitive_Load_S_Switching_Sequence_=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0;...
%                                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;...
%                                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
%          Capacitive_Load_T_Switching_Sequence_=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0;...
%                                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;...
%                                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
         Capacitive_Load_R_Switching_Sequence=Capacitive_Load_R_Switching_Sequence_';
         Capacitive_Load_S_Switching_Sequence=Capacitive_Load_S_Switching_Sequence_';
         Capacitive_Load_T_Switching_Sequence=Capacitive_Load_T_Switching_Sequence_';
         
         UsedCapacitanceR=(Capacitive_Load_R_Switching_Sequence(:,1)*Capacitive_Load_R_RC(2,1))+...
                          (Capacitive_Load_R_Switching_Sequence(:,2)*Capacitive_Load_R_RC(2,2))+...
                          (Capacitive_Load_R_Switching_Sequence(:,3)*Capacitive_Load_R_RC(2,3));
         UsedCapacitanceS=(Capacitive_Load_S_Switching_Sequence(:,1)*Capacitive_Load_S_RC(2,1))+...
                          (Capacitive_Load_S_Switching_Sequence(:,2)*Capacitive_Load_S_RC(2,2))+...
                          (Capacitive_Load_S_Switching_Sequence(:,3)*Capacitive_Load_S_RC(2,3));
         UsedCapacitanceT=(Capacitive_Load_T_Switching_Sequence(:,1)*Capacitive_Load_T_RC(2,1))+...
                          (Capacitive_Load_T_Switching_Sequence(:,2)*Capacitive_Load_T_RC(2,2))+...
                          (Capacitive_Load_T_Switching_Sequence(:,3)*Capacitive_Load_T_RC(2,3));
         
         Capacitive_Load_R_Switching_Sequence=ones(3,tfin/Capacitive_Load_R_Switching_Speed(1))';
         Capacitive_Load_S_Switching_Sequence=ones(3,tfin/Capacitive_Load_R_Switching_Speed(1))';
         Capacitive_Load_T_Switching_Sequence=ones(3,tfin/Capacitive_Load_R_Switching_Speed(1))';
                      
%% Controller
Start_Control=0.4;
P_gain=0.01;
step_size =     [1,1,1,...          %amp
                 0.18,0.18,0.18];   %phase
test_step =     [1,1,1,...          %amp
                 0.08,0.08,0.08];   %phase   
initial_value = [0.00,0.00,0.00,...          %amp
                 0,-2/3*pi,-4/3*pi];%phase

amp_feedback_saturation=400;
phase_feedback_saturation=pi;


%% Simulation
        paramNameValStruct.AbsTol         = '1e-9';
        paramNameValStruct.RelTol         = '1e-9';
        sim('Symmetry_COPY');


   
%% Plotting

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

figure
%Voltage Source 
plot(CC.time,CC.signals.values(:,1),...
    CC.time,CC.signals.values(:,2),...
    CC.time,CC.signals.values(:,3))
grid on
title('CC')
xlabel('t')
ylabel('A')

%Indicator norms
figure
plot(REG.time,REG.signals.values(:,1),...
     VEC.time,VEC.signals.values(:,1)*1e-3,...
     GEO.time,GEO.signals.values(:,1)*1e-3), grid on
xlabel('t')
title('Norms')
legend('A_x','VEC*1e-3','GEO*1e-3')

%% Save
prompt = {'Enter the START time of data log','Enter the END time of data log','Enter measurement detail'};
        dlg_title = 'Logging parameters';
        num_lines = 1;
        defAns = {'0.3','1','1'};
        options = 'off';
        answer = inputdlg(prompt,dlg_title,num_lines,defAns,options);
        %Error handling
        if str2num(answer{2})>max(V_conn.time) 
                errordlg('Time out of time range!')
        end
        if str2num(answer{1})>=str2num(answer{2})
                errordlg('No valid range of data!')
        end
        
        logstart = str2num(answer{1})/sample;
        logend =  str2num(answer{2})/sample;
        logstart_switch = round((str2num(answer{1})/sample)*Capacitive_Load_R_Switching_Speed(1));
        logend_switch =  round((str2num(answer{2})/sample)*Capacitive_Load_R_Switching_Speed(1));
        detail=str2num(answer{3});

REG_=[t(logstart:detail:logend)',REG.signals.values((logstart:detail:logend),1)];
VEC_=[t(logstart:detail:logend)',VEC.signals.values((logstart:detail:logend),1)*1e-3];
GEO_=[t(logstart:detail:logend)',GEO.signals.values((logstart:detail:logend),1)*1e-4];
     
    save('norm_measure/REG1.dat','REG_','-ascii');
    save('norm_measure/VEC.dat','VEC_','-ascii');
    save('norm_measure/GEO1.dat','GEO_','-ascii');

