%% 2#
        n=size(V.signals.values(:,1),1); 
        r=0;
        s=1;
        s1=2;
        szog=1;
        for (i=1 : n)
                r=r+1;
            if ( i<n && (V.signals.values(i,2)*V.signals.values(i+1,2) < 0) && r > 500)
                s=r;
                t=0;
            end
            if ( i<n && (V.signals.values(i,1)*V.signals.values(i+1,1) < 0) && (V.signals.values(i+1,1)*V.signals.values(i,2)>0) && s1~=s )
                s1=s;
                szog=r;
            end
            szogt(i,1)=180*(szog/s1);           %fél periódusonként szög számolása
      end