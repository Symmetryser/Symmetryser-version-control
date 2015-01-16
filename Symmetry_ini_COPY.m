% Symmetriser power model initialization
clear all;
close all;

%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=5;                                           %[s]
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
Start_Control=0.1;
P_gain=0.01;
step_size =     [1,1,1,...          %amp
                 0.16,0.16,0.16];   %phase
test_step =     [1,1,1,...          %amp
                 0.08,0.08,0.08];   %phase   
initial_value = [1,1,1,...          %amp
                 0,-2/3*pi,-4/3*pi];%phase

amp_feedback_saturation=400;
phase_feedback_saturation=pi;


%% Simulation
        paramNameValStruct.AbsTol         = '1e-9';
        paramNameValStruct.RelTol         = '1e-9';
        sim('Symmetry_COPY');

%% Angle
        n=size(V.signals.values(:,1),1); 
        r=0;
        s=1;
        s1=2;
        s2=2;
        szog1=s1/3;
        szog2=s2*2/3;
        for (i=1 : n)
                r=r+1;
            if i<n && V.signals.values(i,1)*V.signals.values(i+1,1) <= 0 
                s=r;
                r=0;
            end
            if i<n && V.signals.values(i,2)*V.signals.values(i+1,2) <= 0 && s1~=s
                s1=s;
                szog1=r;
            end
            if i<n && V.signals.values(i,3)*V.signals.values(i+1,3) <= 0 && s2~=s
                s2=s;
                szog2=r;
            end
            szogt(i,1)=180*(szog1/s1)-60;           %f�l peri�dusonk�nt sz�g sz�mol�sa
            szogt(i,2)=180*(szog2/s2); 
            if szogt(i,1)>360
                szogt(i,1)=360;
            end
            if szogt(i,2)>360
                szogt(i,2)=360;
            end
            szogt(i,3)=360-(szogt(i,2)+szogt(i,1));
        end
   
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


%%
r=tfin/Capacitive_Load_R_Switching_Speed(1);
t_axis_switch=zeros(1,r);
for i=2:r
    t_axis_switch(i)=t_axis_switch(i-1)+Capacitive_Load_R_Switching_Speed(1);
    
end
t_axis_switch=t_axis_switch';




        
% %% Save variables
%     VR=[t,V.signals.values(:,1)];
%     VS=[t,V.signals.values(:,2)];
%     VT=[t,V.signals.values(:,3)];
%     
%     VrmsR=[t,Vrms.signals.values(:,1)];
%     VrmsS=[t,Vrms.signals.values(:,2)];
%     VrmsT=[t,Vrms.signals.values(:,3)];
%    
%     angleR=[t,szogt(:,1)];
%     angleS=[t,szogt(:,2)];
%     angleT=[t,szogt(:,3)];
%     
%     CCR=[t,Control_Current_Values.signals.values(:,1)];
%     CCS=[t,Control_Current_Values.signals.values(:,2)];
%     CCT=[t,Control_Current_Values.signals.values(:,3)];
% 
% % Save variables form 0.5s to 0.6s (k�s�bb dial�gus ablakot bele!)
%     
%   prompt = {'Enter the START time of data log','Enter the END time of data log'};
%         dlg_title = 'Logging parameters';
%         num_lines = 1;
%         defAns = {'0.8','1'};
%         options = 'off';
%         answer = inputdlg(prompt,dlg_title,num_lines,defAns,options);
% %        Error handling
%         if str2num(answer{2})>max(Vrms.time) 
%                 errordlg('Time out of time range!')
%         end
%         if str2num(answer{1})>=str2num(answer{2})
%                 errordlg('No valid range of data!')
%         end
%         
%         logstart = str2num(answer{1})/sample;
%         logend =  str2num(answer{2})/sample;
%         logstart_switch = round((str2num(answer{1})/sample)*Capacitive_Load_R_Switching_Speed(1));
%         logend_switch =  round((str2num(answer{2})/sample)*Capacitive_Load_R_Switching_Speed(1));
% 
%     VR=[t(logstart:logend),V.signals.values((logstart:logend),1)];
%     VS=[t(logstart:logend),V.signals.values((logstart:logend),2)];
%     VT=[t(logstart:logend),V.signals.values((logstart:logend),3)];
%     
%     VrmsR=[t(logstart:logend),Vrms.signals.values((logstart:logend),1)];
%     VrmsS=[t(logstart:logend),Vrms.signals.values((logstart:logend),2)];
%     VrmsT=[t(logstart:logend),Vrms.signals.values((logstart:logend),3)];
%    
%     angleR=[t(logstart:logend),szogt((logstart:logend),1)];
%     angleS=[t(logstart:logend),szogt((logstart:logend),2)];
%     angleT=[t(logstart:logend),szogt((logstart:logend),3)];
%     
%     CCR=[t(logstart:logend),Control_Current_Values.signals.values((logstart:logend),1)];
%     CCS=[t(logstart:logend),Control_Current_Values.signals.values((logstart:logend),2)];
%     CCT=[t(logstart:logend),Control_Current_Values.signals.values((logstart:logend),3)];
%     
%     CapacityAmountR=[t_axis_switch(logstart_switch:logend_switch),UsedCapacitanceR(logstart_switch:logend_switch)];
%     CapacityAmountS=[t_axis_switch(logstart_switch:logend_switch),UsedCapacitanceS(logstart_switch:logend_switch)];
%     CapacityAmountT=[t_axis_switch(logstart_switch:logend_switch),UsedCapacitanceT(logstart_switch:logend_switch)];
%     
%     save('Measurements/VoltageR.dat','VR','-ascii');
%     save('Measurements/VoltageS.dat','VS','-ascii');
%     save('Measurements/VoltageT.dat','VT','-ascii');
%     
%     save('Measurements/VrmsR.dat','VrmsR','-ascii');
%     save('Measurements/VrmsS.dat','VrmsS','-ascii');
%     save('Measurements/VrmsT.dat','VrmsT','-ascii');
%     
%     save('Measurements/angleR.dat','angleR','-ascii');
%     save('Measurements/angleS.dat','angleS','-ascii');
%     save('Measurements/angleT.dat','angleT','-ascii');
%     
%     save('Measurements/ConnectionCurrentR.dat','CCR','-ascii');
%     save('Measurements/ConnectionCurrentS.dat','CCS','-ascii');
%     save('Measurements/ConnectionCurrentT.dat','CCT','-ascii');
%     
%     save('Measurements/CapacityAmountR.dat','CapacityAmountR','-ascii');
%     save('Measurements/CapacityAmountS.dat','CapacityAmountS','-ascii');
%     save('Measurements/CapacityAmountT.dat','CapacityAmountT','-ascii');
