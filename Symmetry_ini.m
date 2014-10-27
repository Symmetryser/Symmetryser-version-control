% Symmetriser power model initialization
clear all;
close all;

%% Simulation initialisation parameters
CLK=1000;                                           %[sample/s]
tfin=0.2;                                           %[s]
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
            szogt(i,1)=180*(szog1/s1)-60;           %fél periódusonként szög számolása
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
%% Voltage Asymmetry Norm

for (i=1 : n)
        % kérdés hogy bármely tengelyre illeszthetem-e a referenciát?
        % Ideal parameters
        Amplitude_1=[230,230,230];                     %[V]
        Phase_1=[0,2/3*pi,4/3*pi];                     %[rad]
%        Frequency_1=[50,50,50];                       %[Hz]

        % Real parameters
        Amplitude_2=[Vrms.signals.values(i,1),...
                     Vrms.signals.values(i,2),...
                     Vrms.signals.values(i,3)];        %[V]
        Phase_2=[degtorad(szogt(i,1)),...
                 degtorad(szogt(i,3)),...
                 degtorad(szogt(i,3))];                %[rad]
%        Frequency_2=[50,50,50];                       %[Hz]

        %Extension of the vectors with the first element to get closed triangles on
        %plots and for use as polygons
        Amplitude_1_ex=[Amplitude_1 Amplitude_1(1)];
        Phase_1_ex=[Phase_1 Phase_1(1)];
        Amplitude_2_ex=[Amplitude_2 Amplitude_2(1)];
        Phase_2_ex=[Phase_2 Phase_2(1)];
        %Transforming to Cartesian coordinates
        [x_1,y_1] = pol2cart(Phase_1_ex,Amplitude_1_ex);
        [x_2,y_2] = pol2cart(Phase_2_ex,Amplitude_2_ex);

        %Intersection of the triangles
        Intersection = poly2poly([x_1;y_1],[x_2;y_2]);
        x_3 = Intersection(1,:);
        y_3 = Intersection(2,:);
        %[x_3,y_3]=poly2ccw(x_3,y_3);
        %Mukodni latszik, de akkor van gond, ha csak 2 vagy 1? metszespont van a
        %haromszogek között, ekkor az eredeti haromszögek pontjait kell használni,
        %bizonys feltételek melett

        % 2 metszéspont: meg kell írni!!!
        % 1 metszéspont: nem lehet
        % 0 metszéspont: a nagyobból ki kell vonni a kisebbet

        % Calculate the areas of the polygons
        A_1(i) = polyarea(x_1,y_1);
        A_2(i) = polyarea(x_2,y_2);
        A_intersection(i) = polyarea(x_3,y_3);
        A_union(i) = A_1(i)+A_2(i)-A_intersection(i);

        Error_Space(i)=A_union(i)-A_intersection(i);
end
figure
plot(Vrms.time,Error_Space), grid on
title('Vector Triangle Union-Intersectrion')
xlabel('t')
ylabel('Geometry Norm')    
       
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