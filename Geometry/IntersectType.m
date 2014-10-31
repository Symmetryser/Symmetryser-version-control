function [ n1] = IntersectType( A1,A2,x1,y1,x2,y2,x3)
    %UNTITLED4 Summary of this function goes here
    %   Detailed explanation goes here
    lateria=distance(x1(1:3),y1(1:3),x2(1:3),y2(1:3));
    p=0;
    for i=1:size(x1,2)-1
        if lateria(i)==0
           p=p+1;
        end
    end
    if A1==A2
        n1=0;
    end
    if (A1~=A2 && size(x3,2)==0) 
        n1=1;
    end  
    if size(x3,2)==2
        n1=2;
    end  
    if size(x3,2)==3
        n1=3;
    end
        if p>1 %one side is shared of the triangles
            n1=1;
        else
            n1=4;
        end
end


