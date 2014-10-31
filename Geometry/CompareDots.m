function [ n2 ] = CompareDots(x1,y1,x2,y2)

Lenght=zeros(2,size(x1,2)-1);
comp = zeros(1,size(x1,2)-1);
    
    for i=1:size(x1,2)-1
        Lenght(i,1)=pitagoras(x1(i),y1(i));
        Lenght(i,2)=pitagoras(x2(i),y2(i));
    end
    %ide be kell szúrni egy jobb összehasonlítást, 
    %ha 180fok körüli eltérés van, a háromszöget rosszul számítja a program
    % A háromszögek csúcsait nem páronként kell összevetni
    
%     for i=1:size(x1,2)-1   
%         for j=1:size(x1,2)-1 
%             if Lenght(i,1)>Lenght(j,2)
%                 comp(i)(j)=1;
%             end
%             if Lenght(i,1)==Lenght(j,2)
%                 comp(i)(j)=1;
%             end
%             if Lenght(i,1)<Lenght(j,2)
%                 comp(i)(j)=1;
%             end
%         end
%     end
    
    
    for i=1:size(x1,2)-1   
        if Lenght(i,1)>Lenght(i,2)
            comp(i)=1;
        end
        if Lenght(i,1)<Lenght(i,2)
            comp(i)=-1;
        end
        if Lenght(i,1)==Lenght(i,2)
            comp(i)=0;
        end
    end
    
    if comp(1)==comp(2)
        if comp(1)==1 %az ideális hátomszög a nagyobb?
            n2=0.1;
        else n2=0.2; 
        end
    end
    if comp(2)==comp(3)
        if comp(1)==2 %az ideális hátomszög a nagyobb?
            n2=1.1;
        else n2=1.2; 
        end   
    end
    if comp(3)==comp(1)
        if comp(3)==1 %az ideális hátomszög a nagyobb?
            n2=2.1;
        else n2=2.2; 
        end
    end
    
end

