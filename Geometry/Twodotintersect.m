function [x4,y4,x5,y5] = TwoDotIntersect(x1,y1,x2,y2,x3,y3,n2)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
%square



   switch n2
        case 0.1
            %square
            x4 = [x2(1),x2(2),x3(1),x3(2),x2(1)];
            y4 = [y2(1),y2(2),y3(1),y3(2),y2(1)];
            k=convhull(x4,y4);
            %%square_intersect=polyarea(x4(k),y4(k));
            x4=x4(k);
            y4=y4(k);
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x1(3),y1(3),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x1(3),x3(1)];
            y5 = [y3(1),y3(2),y1(3),y3(1)];
            %%triangle_intersect = polyarea(x5,y5);
            %%triangle_intersect = abs(tianglera);
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                %%triangle_intersect=0;
            end
        case 0.2
            %square
            x4 = [x1(1),x1(2),x3(1),x3(2),x1(1)];
            y4 = [y1(1),y1(2),y3(1),y3(2),y1(1)];
            k=convhull(x4,y4);
            %square_intersect=polyarea(x4(k),y4(k));
            x4=x4(k);
            y4=y4(k);
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x2(3),y2(3),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x2(3),x3(1)];
            y5 = [y3(1),y3(2),y2(3),y3(1)];
            %%triangle_intersect = polyarea(x5,y5);
            %%triangle_intersect = abs(tianglera);
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                %triangle_intersect=0;
            end
        case 1.1
            x4 = [x1(2),x1(3),x3(1),x3(2),x1(2)];
            y4 = [y1(2),y1(3),y3(1),y3(2),y1(2)];
            k=convhull(x4,y4);
            %%square_intersect=polyarea(x4(k),y4(k));
            x4=x4(k);
            y4=y4(k);
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x2(1),y2(1),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x2(1),x3(1)];
            y5 = [y3(1),y3(2),y2(1),y3(1)];
            %triangle_intersect = polyarea(x5,y5);
            %%triangle_intersect = abs(tianglera);
             else
                x5=zeros(1,4);
                y5=zeros(1,4);
                %triangle_intersect=0;
            end
            case 1.2
            %square
            x4 = [x2(2),x2(3),x3(1),x3(2),x2(2)];
            y4 = [y2(2),y2(3),y3(1),y3(2),y2(2)];
            k=convhull(x4,y4);
            %square_intersect=polyarea(x4(k),y4(k));
            x4=x4(k);
            y4=y4(k);
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x1(1),y1(1),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x1(1),x3(1)];
            y5 = [y3(1),y3(2),y1(1),y3(1)];
            %triangle_intersect = polyarea(x5,y5);
            %%triangle_intersect = abs(tianglera);
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                %triangle_intersect=0;
            end
        case 2.1
            x4 = [x2(3),x2(1),x3(1),x3(2),x2(3)];
            y4 = [y2(3),y2(1),y3(1),y3(2),y2(3)];
            k=convhull(x4,y4);
            %square_intersect=polyarea(x4(k),y4(k));
            x4=x4(k);
            y4=y4(k);
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x1(2),y1(2),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x1(2),x3(1)];
            y5 = [y3(1),y3(2),y1(2),y3(1)];
            %triangle_intersect = polyarea(x5,y5);
            %%triangle_intersect = abs(tianglera);
            
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                %triangle_intersect=0;
            end
        case 2.2
            x4 = [x1(3),x1(1),x3(1),x3(2),x1(3)];
            y4 = [y1(3),y1(1),y3(1),y3(2),y1(3)];
            k=convhull(x4,y4);
            %square_intersect=polyarea(x4(k),y4(k));
            x4=x4(k);
            y4=y4(k);
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x2(2),y2(2),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x2(2),x3(1)];
            y5 = [y3(1),y3(2),y2(2),y3(1)];
            %triangle_intersect = polyarea(x5,y5);
            %%triangle_intersect = abs(tianglera);
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                %triangle_intersect=0;
            end
   end
    
end

