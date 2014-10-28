%% Angle
        n=size(Control_Current_Values.signals.values(:,1),1); 
        r=0;
        s=1;
        s1=2;
        s2=2;
        szog1=s1/3;
        szog2=s2*2/3;
        for i=1 : n
                r=r+1;
            if i<n && Control_Current_Values.signals.values(i,1)*Control_Current_Values.signals.values(i+1,1) <= 0 
                s=r;
                r=0;
            end
            if i<n && Control_Current_Values.signals.values(i,2)*Control_Current_Values.signals.values(i+1,2) <= 0 && s1~=s
                s1=s;
                szog1=r;
            end
            if i<n && Control_Current_Values.signals.values(i,3)*Control_Current_Values.signals.values(i+1,3) <= 0 && s2~=s
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