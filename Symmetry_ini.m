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
C_Network=[1e-12, 1e-12, 1e-12];                    %[F]

% Control_Current 
Control_Current_frequency=[50,    50,    50];       %[Hz]
Control_Current_Amplitude=[20,    20,    20];       %[A]
Control_Current_Phase=    [0,     2/3*pi,4/3*pi];   %[rad]
Control_Current_DC=       [0,     0,     0];        %[A]
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
         %%%Ohmic Loads%%%
         Switch_Load_R=[1,1,1];                     %[Boolean]
         Load_R=[50,50,50];                         %[Ohm]
         %%%Inductive Loads%%%
         Switch_Load_RL=[1,1,1];                    %[Boolean]
         LoadRL=[35.35,   35.35,   35.35;...        %[Ohm]
                 0.1125,  0.1125,  0.1125];         %[H]
         %%%Capacitive Loads%%%
         Switch_Load_RC=[1,1,1];                    %[Boolean]
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
         Capacitive_Load_R_Switching_Speed=[10,10,10];%[s/sample]
         Capacitive_Load_S_Switching_Speed=[10,10,10];%[s/sample]
         Capacitive_Load_T_Switching_Speed=[10,10,10];%[s/sample]
         

% Simulation
paramNameValStruct.AbsTol         = '1e-9';
paramNameValStruct.RelTol         = '1e-9';
sim('Symmetry_Control_Current');

%plotting
%%%Transformator Station%%%
        figure
        %Voltage Source Signals
        plot(Sources.time,Sources.signals.values(:,1),...
            Sources.time,Sources.signals.values(:,2),...
            Sources.time,Sources.signals.values(:,3))
        grid on
        title('Source Voltage Signals')
        xlabel('t')
        ylabel('Source Volage Signals Values (RST)')

        figure
        %Voltage Source 
        plot(Voltage_Sources.time,Voltage_Sources.signals.values(:,1),...
            Voltage_Sources.time,Voltage_Sources.signals.values(:,2),...
            Voltage_Sources.time,Voltage_Sources.signals.values(:,3))
        grid on
        title('Source Voltage')
        xlabel('t')
        ylabel('Source Volage Values (RSTN)')

%%%Network Voltage%%%
        figure
        %Network Voltage 
        plot(Network_Voltage.time,Network_Voltage.signals.values(:,1),...
            Network_Voltage.time,Network_Voltage.signals.values(:,2),...
            Network_Voltage.time,Network_Voltage.signals.values(:,3))
        grid on
        title('Network Voltage')
        xlabel('t')
        ylabel('Network Volage Values (RST)')

%%%Control Current%%%
        figure
        %Control Current
        plot(Control_Current.time,Control_Current.signals.values(:,1),...
            Control_Current.time,Control_Current.signals.values(:,2),...
            Control_Current.time,Control_Current.signals.values(:,3))
        grid on
        title('Control Current')
        xlabel('t')
        ylabel('Control Current Values (RST)')

        figure
        %Control Current Values
        plot(Control_Current_Values.time,Control_Current_Values.signals.values(:,1),...
            Control_Current_Values.time,Control_Current_Values.signals.values(:,2),...
            Control_Current_Values.time,Control_Current_Values.signals.values(:,3))
        grid on
        title('Control Current')
        xlabel('t')
        ylabel('Control Current Values (RST)')
        
%%%Load Voltage Measurement%%%
        figure
        %Connection Voltage THD
        plot(Connection_Voltage_THD_RST.time,Connection_Voltage_THD_RST.signals.values(:,1),...
            Connection_Voltage_THD_RST.time,Connection_Voltage_THD_RST.signals.values(:,2),...
            Connection_Voltage_THD_RST.time,Connection_Voltage_THD_RST.signals.values(:,3))
        grid on
        title('Connection Voltage THD')
        xlabel('t')
        ylabel('Connection Voltage THD Values (RST)')
        
        figure
        %Connection Voltage FFT
        plot(Connection_Voltage_FFT_RST.time,Connection_Voltage_FFT_RST.signals.values(:,1),...
            Connection_Voltage_FFT_RST.time,Connection_Voltage_FFT_RST.signals.values(:,2),...
            Connection_Voltage_FFT_RST.time,Connection_Voltage_FFT_RST.signals.values(:,3))
        grid on
        title('Connection Voltage FFT')
        xlabel('t')
        ylabel('Connection Voltage FFT Values (RST)')
        
        figure
        %Connection Voltage RMS
        plot(Connection_Voltage_RMS_RST.time,Connection_Voltage_RMS_RST.signals.values(:,1),...
            Connection_Voltage_RMS_RST.time,Connection_Voltage_RMS_RST.signals.values(:,2),...
            Connection_Voltage_RMS_RST.time,Connection_Voltage_RMS_RST.signals.values(:,3))
        grid on
        title('Connection Voltage RMS')
        xlabel('t')
        ylabel('Connection Voltage RMS Values (RST)')
        
        figure
        %Connection Voltage 
        plot(Connection_Voltage_RST.time,Connection_Voltage_RST.signals.values(:,1),...
            Connection_Voltage_RST.time,Connection_Voltage_RST.signals.values(:,2),...
            Connection_Voltage_RST.time,Connection_Voltage_RST.signals.values(:,3))
        grid on
        title('Connection Voltage')
        xlabel('t')
        ylabel('Connection Voltage Values (RST)')
        
%%%Load Power Measurement%%%
        figure
        %Connection_P_Q (ezt az ábrát még rendezni kell (szín vonal stb)
        plot(Connection_P_Q_RST.time,Connection_P_Q_RST.signals.values(:,1),...
            Connection_P_Q_RST.time,Connection_P_Q_RST.signals.values(:,2),...
            Connection_P_Q_RST.time,Connection_P_Q_RST.signals.values(:,3),...
            Connection_P_Q_RST.time,Connection_P_Q_RST.signals.values(:,4),...
            Connection_P_Q_RST.time,Connection_P_Q_RST.signals.values(:,5),...
            Connection_P_Q_RST.time,Connection_P_Q_RST.signals.values(:,6))
        grid on
        title('Connection_P_Q')
        xlabel('t')
        ylabel('Connection_P_Q Values (RST)')
        
%%%Load Current Measurement%%%
        figure
        %Connection Current RMS
        plot(Connection_Current_RMS_RST.time,Connection_Current_RMS_RST.signals.values(:,1),...
            Connection_Current_RMS_RST.time,Connection_Current_RMS_RST.signals.values(:,2),...
            Connection_Current_RMS_RST.time,Connection_Current_RMS_RST.signals.values(:,3))
        grid on
        title('Connection Current RMS')
        xlabel('t')
        ylabel('Connection Current RMS Values (RST)')
        
        figure
        %Connection Current 
        plot(Connection_Current_RST.time,Connection_Voltage_RST.Current.values(:,1),...
            Connection_Current_RST.time,Connection_Voltage_RST.Current.values(:,2),...
            Connection_Current_RST.time,Connection_Voltage_RST.Current.values(:,3))
        grid on
        title('Connection Current')
        xlabel('t')
        ylabel('Connection Current Values (RST)')