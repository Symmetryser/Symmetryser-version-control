% Symmetriser power model initialization
clear all;
close all;

%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=1.5;                                           %[s]
sample=10e-5;                                       %[s/sample]
t=0:sample:tfin;                                    %[tick]

%% Transformator Station parameters
Urms_Source=[230,230,230];                          %[Vrms]
Source_Frequency=[50,50,50];                        %[Hz]
Phase_Source=[0,2/3*pi,4/3*pi];                     %[rad]
R_Source=[0.4, 0.4, 0.4];                           %[Ohm]
L_Source=[3.185e-3, 3.185e-3, 3.185e-3];            %[H]

%% Network parameters
R_Network=[0.4, 0.4, 0.4, 0.4];                     %[Ohm]
L_Network=[3.185e-3, 3.185e-3, 3.185e-3, 3.185e-3]; %[H]
C_Network=[0, 0, 0];                                %[F]

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
        size_t=size(t);
        Control_Current.time=t;
        CC=[CC_mtx(1,1)*sin(2*pi*CC_mtx(1,2)*t+CC_mtx(1,3))+CC_mtx(1,4),...
            CC_mtx(2,1)*sin(2*pi*CC_mtx(2,2)*t+CC_mtx(2,3))+CC_mtx(2,4),...
            CC_mtx(3,1)*sin(2*pi*CC_mtx(3,2)*t+CC_mtx(3,3))+CC_mtx(3,4)];
        Control_Current.signals.values=CC;

%% Network Loads
Load_Wire_Resistance=[0.1,0.2];                     %[Ohm]
Switch_Load_R= [1,1,1];                             %[Boolean]
Switch_Load_RL=[1,1,1];                             %[Boolean]
Switch_Load_RC=[1,1,1];                             %[Boolean]
%          %%%FFT%%%
%          s=zeros(1,128);
%          s(4)=1;
%          s(6)=1;
%          s(8)=1;
%          s(10)=1;
%          s(12)=1;
         %%%Ohmic Loads%%%
         Load_R=[50,50,50];                         %[Ohm]
         Ohmic_Load_Switching_Speed=[0.01,0.01,0.01];
         Ohmic_Load_Switching_Sequence_=[randi([0 1],1,tfin/Ohmic_Load_Switching_Speed(1));...
                                         randi([0 1],1,tfin/Ohmic_Load_Switching_Speed(2));...
                                         randi([0 1],1,tfin/Ohmic_Load_Switching_Speed(3))];
         Ohmic_Load_Switching_Sequence=Ohmic_Load_Switching_Sequence_';
         %%%Inductive Loads%%%
         Load_RL=[35.35,   35.35,   35.35;...       %[Ohm]
                 0.1125,  0.1125,  0.1125];         %[H]
         Inductive_Load_Switching_Speed=[0.01,0.01,0.01];
         Inductive_Load_Switching_Sequence_=[randi([0 1],1,tfin/Inductive_Load_Switching_Speed(1));...
                                             randi([0 1],1,tfin/Inductive_Load_Switching_Speed(2));...
                                             randi([0 1],1,tfin/Inductive_Load_Switching_Speed(3))];
         Inductive_Load_Switching_Sequence=Inductive_Load_Switching_Sequence_';
         %%%Capacitive Loads%%%
         Capacitive_Load_R_RC=[30e-3,  60e-3,  40e-3;...  %[Ohm]
                               1e-3, 5e-3, 3e-3];  %[F]
         Capacitive_Load_S_RC=[30e-3,  60e-3,  40e-3;...  %[Ohm]
                               1e-3, 5e-3, 3e-3];  %[F]
         Capacitive_Load_T_RC=[30e-3,  60e-3,  40e-3;...  %[Ohm]
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

%% Simulation
        paramNameValStruct.AbsTol         = '1e-9';
        paramNameValStruct.RelTol         = '1e-9';
        sim('Symmetry');

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
       figure
       plot(V.time,szogt(:,1),V.time,szogt(:,2),V.time,szogt(:,3)),grid on
       title('Phase Angle')
       xlabel('t')
       ylabel('Phase Angle Values (RST)')   
%% Plotting
% %%%Transformator Station%%%
%         figure
%         %Voltage Source Signals
%         plot(Sources.time,Sources.signals.values(:,1),...
%             Sources.time,Sources.signals.values(:,2),...
%             Sources.time,Sources.signals.values(:,3))
%         grid on
%         title('Source Voltage Signals')
%         xlabel('t')
%         ylabel('Source Volage Signals Values (RST)')
% 
%         figure
%         %Voltage Source 
%         plot(Voltage_Sources.time,Voltage_Sources.signals.values(:,1),...
%             Voltage_Sources.time,Voltage_Sources.signals.values(:,2),...
%             Voltage_Sources.time,Voltage_Sources.signals.values(:,3))
%         grid on
%         title('Source Voltage')
%         xlabel('t')
%         ylabel('Source Volage Values (RSTN)')
% 
% %%%Network Voltage%%%
%         figure
%         %Network Voltage 
%         plot(Network_Voltage.time,Network_Voltage.signals.values(:,1),...
%             Network_Voltage.time,Network_Voltage.signals.values(:,2),...
%             Network_Voltage.time,Network_Voltage.signals.values(:,3))
%         grid on
%         title('Network Voltage')
%         xlabel('t')
%         ylabel('Network Volage Values (RST)')
% %%%Control Current%%%
        figure
        %Control Current Values
        plot(Control_Current_Values.time,Control_Current_Values.signals.values(:,1),...
            Control_Current_Values.time,Control_Current_Values.signals.values(:,2),...
            Control_Current_Values.time,Control_Current_Values.signals.values(:,3))
        grid on
        title('Control Current')
        xlabel('t')
        ylabel('Control Current Values (RST)')
        
%         figure
%         plot(Phase_Diff.time,Phase_Diff.signals.values(:,1),...
%              Phase_Diff.time,Phase_Diff.signals.values(:,2),...
%              Phase_Diff.time,Phase_Diff.signals.values(:,3));
%          grid on
%         title('Phase_Shift')
%         xlabel('t')
%         ylabel('Phase_Shift (rad)')
%         
%%%THD%%%
%         figure
%         %Connection Voltage THD
%         plot(Connection_Voltage_THD_RST.time,Connection_Voltage_THD_RST.signals.values(:,1),...
%             Connection_Voltage_THD_RST.time,Connection_Voltage_THD_RST.signals.values(:,2),...
%             Connection_Voltage_THD_RST.time,Connection_Voltage_THD_RST.signals.values(:,3))
%         grid on
%         title('Connection Voltage THD')
%         xlabel('t')
%         ylabel('Connection Voltage THD Values (RST)')
%         
%%%FFT%%%
%         %Connection Voltage FFT
%         plot(Connection_Voltage_FFT_RST.time,Connection_Voltage_FFT_RST.signals.values(:,1),...
%             Connection_Voltage_FFT_RST.time,Connection_Voltage_FFT_RST.signals.values(:,2),...
%             Connection_Voltage_FFT_RST.time,Connection_Voltage_FFT_RST.signals.values(:,3))
%         grid on
%         title('Connection Voltage FFT')
%         xlabel('t')
%         ylabel('Connection Voltage FFT Values (RST)')
        
%%%Load Power Measurement%%%
        figure
        plot(Connection_P_Q_RST)
        grid on
        title('Connection_P_Q')
        xlabel('t')
        ylabel('Connection_P_Q Values (RST)')
%%%RMS%%%
        figure
        subplot(2,1,1)
        %Connection Voltage RMS
        plot(Connection_Voltage_RMS_RST)
        grid on
        title('Connection Voltage RMS')
        xlabel('t')
        ylabel('Connection Voltage RMS Values (RST)')
        subplot(2,1,2)
        %Connection Current RMS
        plot(Connection_Currnet_RMS_RST)
        grid on
        title('Connection Current RMS')
        xlabel('t')
        ylabel('Connection Current RMS Values (RST)')
        
        figure
        subplot(2,1,1)
%%%Connection%%%
        plot(Connection_Voltage_RST)
        grid on
        title('Connection Voltage')
        xlabel('t')
        ylabel('Connection Voltage Values (RST)')
        subplot(2,1,2)
        %Connection Current RMS
        plot(Connection_Current_RST)
        grid on
        title('Connection Current')
        xlabel('t')
        ylabel('Connection Current Values (RST)')
        
%%Save variables form 0.5s to 0.6s (k�s�bb dial�gus ablakot bele!)
    
  prompt = {'Enter the START time of data log','Enter the END time of data log'};
        dlg_title = 'Logging parameters';
        num_lines = 1;
        defAns = {'0.5','0.6'};
        options = 'off';
        answer = inputdlg(prompt,dlg_title,num_lines,defAns,options);
        % Error handling
        if str2num(answer{2})>max(Vrms.time) 
                errordlg('Time out of time range!')
        end
        if str2num(answer{1})>=str2num(answer{2})
                errordlg('No valid range of data!')
        end
        
        logstart = str2num(answer{1})/sample;
        logend =  str2num(answer{2})/sample;

    VR=[t(logstart:logend),V.signals.values((logstart:logend),1)];
    VS=[t(logstart:logend),V.signals.values((logstart:logend),2)];
    VT=[t(logstart:logend),V.signals.values((logstart:logend),3)];
    
    VrmsR=[t(logstart:logend),Vrms.signals.values((logstart:logend),1)];
    VrmsS=[t(logstart:logend),Vrms.signals.values((logstart:logend),2)];
    VrmsT=[t(logstart:logend),Vrms.signals.values((logstart:logend),3)];
   
    angleR=[t(logstart:logend),szogt((logstart:logend),1)];
    angleS=[t(logstart:logend),szogt((logstart:logend),2)];
    angleT=[t(logstart:logend),szogt((logstart:logend),3)];
    
    CCR=[t(logstart:logend),Control_Current_Values.signals.values((logstart:logend),1)];
    CCS=[t(logstart:logend),Control_Current_Values.signals.values((logstart:logend),2)];
    CCT=[t(logstart:logend),Control_Current_Values.signals.values((logstart:logend),3)];
    
    
    save('Measurements/VoltageR.dat','VR','-ascii');
    save('Measurements/VoltageS.dat','VS','-ascii');
    save('Measurements/VoltageT.dat','VT','-ascii');
    
    save('Measurements/VrmsR.dat','VrmsR','-ascii');
    save('Measurements/VrmsS.dat','VrmsS','-ascii');
    save('Measurements/VrmsT.dat','VrmsT','-ascii');
    
    save('Measurements/angleR.dat','angleR','-ascii');
    save('Measurements/angleS.dat','angleS','-ascii');
    save('Measurements/angleT.dat','angleT','-ascii');
    
    save('Measurements/ConnectionCurrentR.dat','CCR','-ascii');
    save('Measurements/ConnectionCurrentS.dat','CCS','-ascii');
    save('Measurements/ConnectionCurrentT.dat','CCT','-ascii');
    