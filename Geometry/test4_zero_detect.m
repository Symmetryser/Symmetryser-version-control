%% 2#
        n=size(V.signals.values(:,1),1); 
        r=0;
        s=1;
        s1=97;
        s2=97;
        szog=s1/3;
        szog2=s2*2/3;
        for (i=1 : n)
                r=r+1;
            if i<n && V.signals.values(i,1)*V.signals.values(i+1,1) <= 0 
                s=r;
                r=0;
            end
            if i<n && V.signals.values(i,2)*V.signals.values(i+1,2) <= 0 && s1~=s
                s1=s;
                szog=r;
            end
            
            if i<n && V.signals.values(i,3)*V.signals.values(i+1,3) <= 0 && s2~=s
                s2=s;
                szog2=r;
            end

          
            szogt(i,1)=180*(szog/s1)-60;           %fél periódusonként szög számolása
            szogt(i,2)=180*(szog2/s2); 
            if szogt(i,1)>360
                szogt(i,1)=360;
            end
            if szogt(i,2)>360
                szogt(i,2)=360;
            end
        end
       plot(V.time,szogt(:,1),V.time,szogt(:,2),V.time,(360-(szogt(:,2)+szogt(:,1)))),grid on
    
      