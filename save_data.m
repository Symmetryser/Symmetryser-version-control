%% Save
clear all
close all
load('saved_data/PQ_R_saved.mat')
load('saved_data/PQ_S_saved.mat')
load('saved_data/PQ_T_saved.mat')

load('saved_data/AMP_CONTROL_saved.mat')

load('saved_data/PHASE_CONTROL_saved.mat')

load('saved_data/REG_saved.mat')
load('saved_data/VEC_saved.mat')
load('saved_data/GEO_saved.mat')

sample=10e-5;  

prompt = {'Enter the START time of data log','Enter the END time of data log','Enter measurement detail'};
        dlg_title = 'Save Data';
        num_lines = 1;
        defAns = {'0.5','20','100'};
        options = 'off';
        answer = inputdlg(prompt,dlg_title,num_lines,defAns,options);
        %Error handling
        if str2num(answer{2})>max(VEC_saved.time) 
                errordlg('Time out of time range!')
        end
        if str2num(answer{1})>=str2num(answer{2})
                errordlg('No valid range of data!')
        end

        logstart = str2num(answer{1})/sample;
        logend =  str2num(answer{2})/sample;
        detail=str2num(answer{3});
        


REG_=[REG_saved.time(logstart:detail:logend),REG_saved.data((logstart:detail:logend),1)];
VEC_=[VEC_saved.time(logstart:detail:logend),VEC_saved.data((logstart:detail:logend),1)*1e-3];
GEO_=[GEO_saved.time(logstart:detail:logend),GEO_saved.data((logstart:detail:logend),1)*1e-3];

P_R=[PQ_R_saved.time(logstart:detail:logend),PQ_R_saved.data((logstart:detail:logend),1)];
P_S=[PQ_S_saved.time(logstart:detail:logend),PQ_S_saved.data((logstart:detail:logend),1)];
P_T=[PQ_T_saved.time(logstart:detail:logend),PQ_T_saved.data((logstart:detail:logend),1)];
Q_R=[PQ_R_saved.time(logstart:detail:logend),PQ_R_saved.data((logstart:detail:logend),2)];
Q_S=[PQ_S_saved.time(logstart:detail:logend),PQ_S_saved.data((logstart:detail:logend),2)];
Q_T=[PQ_T_saved.time(logstart:detail:logend),PQ_T_saved.data((logstart:detail:logend),2)];

AMP_C_R=[AMP_CONTROL_saved.time(logstart:detail:logend),AMP_CONTROL_saved.data((logstart:detail:logend),1)];
AMP_C_S=[AMP_CONTROL_saved.time(logstart:detail:logend),AMP_CONTROL_saved.data((logstart:detail:logend),2)];
AMP_C_T=[AMP_CONTROL_saved.time(logstart:detail:logend),AMP_CONTROL_saved.data((logstart:detail:logend),3)];

PHASE_C_R=[PHASE_CONTROL_saved.time(logstart:detail:logend),PHASE_CONTROL_saved.data((logstart:detail:logend),1)];
PHASE_C_S=[PHASE_CONTROL_saved.time(logstart:detail:logend),PHASE_CONTROL_saved.data((logstart:detail:logend),2)];
PHASE_C_T=[PHASE_CONTROL_saved.time(logstart:detail:logend),PHASE_CONTROL_saved.data((logstart:detail:logend),3)];

    save('plot/REG.dat','REG_','-ascii');
    save('plot/VEC.dat','VEC_','-ascii');
    save('plot/GEO.dat','GEO_','-ascii');
    
    save('plot/P_R.dat','P_R','-ascii');
    save('plot/P_S.dat','P_S','-ascii');
    save('plot/P_T.dat','P_T','-ascii');
    save('plot/Q_R.dat','Q_R','-ascii');
    save('plot/Q_S.dat','Q_S','-ascii');
    save('plot/Q_T.dat','Q_T','-ascii');
    
    save('plot/AMP_C_R.dat','AMP_C_R','-ascii');
    save('plot/AMP_C_S.dat','AMP_C_S','-ascii');
    save('plot/AMP_C_T.dat','AMP_C_T','-ascii');
    
    save('plot/PHASE_C_R.dat','PHASE_C_R','-ascii');
    save('plot/PHASE_C_S.dat','PHASE_C_S','-ascii');
    save('plot/PHASE_C_T.dat','PHASE_C_T','-ascii');

