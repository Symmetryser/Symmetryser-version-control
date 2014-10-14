% Symmetriser power model initialization
clear all;
close all;

% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=0.1;                                           %[s]
sample=10e-5;                                       %[s/sample]
t=0:sample:tfin;                                    %[tick]

% Transformator Station parameters
Urms_Source=[230,230,230];                          %[Vrms]
Source_Frequency=[50,50,50];                        %[Hz]
Phase_Source=[0,2/3*pi,4/3*pi];                     %[rad]
R_Source=[0.4, 0.4, 0.4];                           %[Ohm]
L_Source=[3.185e-3, 3.185e-3, 3.185e-3];            %[H]

% Network parameters
R_Network=[0.4, 0.4, 0.4, 0.4];                     %[Ohm]
L_Network=[3.185e-3, 3.185e-3, 3.185e-3, 3.185e-3]; %[H]
C_Network=[0, 0, 0];                                %[F]

% Control_Current 
Butterworth_filter_order=8;
Butterworth_passband_frequency=5000;
% Control_Current_frequency=[20,     30,     40];       %[Hz]
% Control_Current_Amplitude=[0,     0,     0];       %[A]
% Control_Current_Phase=    [0,      2/3*pi, 4/3*pi];   %[rad]
% Control_Current_DC=       [0,      0,      0];        %[A]
% Input dialog
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

% Network Loads
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
         %%%Inductive Loads%%%
         Load_RL=[35.35,   35.35,   35.35;...       %[Ohm]
                 0.1125,  0.1125,  0.1125];         %[H]
         %%%Capacitive Loads%%%
         Capacitive_Load_R_RC=[25,    50,   35;...  %[Ohm]
                               10e-3, 5e-3, 7e-3];  %[F]
         Capacitive_Load_S_RC=[25,    50,   35;...  %[Ohm]
                               10e-3, 5e-3, 7e-3];  %[F]
         Capacitive_Load_T_RC=[25,    50,   35;...  %[Ohm]
                               10e-3, 5e-3, 7e-3];  %[F]
         Capacitive_Load_R_Switching_Sequence_=[1, 1, 0, 0, 0, 0, 0, 0, 0, 0;...
                                                0, 0, 0, 1, 1, 0, 0, 0, 0, 0;...
                                                0, 0, 0, 0, 1, 0, 0, 0, 0, 0];
         Capacitive_Load_S_Switching_Sequence_=[1, 1, 0, 0, 0, 0, 0, 0, 0, 0;...
                                                0, 0, 0, 1, 1, 0, 0, 0, 0, 0;...
                                                0, 0, 0, 0, 1, 0, 0, 0, 0, 0];
         Capacitive_Load_T_Switching_Sequence_=[1, 1, 0, 0, 0, 0, 0, 0, 0, 0;...
                                                0, 0, 0, 1, 1, 0, 0, 0, 0, 0;...
                                                0, 0, 0, 0, 1, 0, 0, 0, 0, 0];
         Capacitive_Load_R_Switching_Sequence=Capacitive_Load_R_Switching_Sequence_';
         Capacitive_Load_S_Switching_Sequence=Capacitive_Load_S_Switching_Sequence_';
         Capacitive_Load_T_Switching_Sequence=Capacitive_Load_T_Switching_Sequence_';
         Capacitive_Load_R_Switching_Speed=[10,10,10];%[s]
         Capacitive_Load_S_Switching_Speed=[10,10,10];%[s]
         Capacitive_Load_T_Switching_Speed=[10,10,10];%[s]
         

% Simulation
paramNameValStruct.AbsTol         = '1e-9';
paramNameValStruct.RelTol         = '1e-9';
sim('Symmetry');

% %plotting
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