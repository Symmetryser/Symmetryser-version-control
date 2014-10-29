function [ x4,y4 ] = Twodotintersect(Phase_1_ex,Amplitude_1_ex,Phase_2_ex,Amplitude_2_ex)
% Only triangles 
[x1,y1] = pol2cart(Phase_1_ex,Amplitude_1_ex);
[x2,y2] = pol2cart(Phase_2_ex,Amplitude_2_ex);
Intersection = poly2poly([x1;y1],[x2;y2]);
x3 = Intersection(1,:);
y3 = Intersection(2,:);
% If it is not a two point intersection, throw an error
Psize=size(x1);
Isize=size(Intersection);
if Isize(1)~=2
    errordlg('Inproper use of function "Twodotintersect", the number of intersection points are not equal to 2!')
end


%% Sequence of intersection points
angle1=asin(x3(1)/(x3(1)^2+y3(1)^2));
angle2=asin(x3(2)/(x3(1)^2+y3(1)^2));
if angle1>angle2
    %[x3(1),y3(1)] is left to [x3(2),y3(2)]
    a=1;
else
    %[x3(1),y3(1)] is right to [x3(2),y3(2)]
    a=0;
end
%% Compare the lenghts from the Origo
Lenght=zeros(2,Psize(1)-1);
comp = zeros(1,Psize(1)-1);
    
    for i=1:Psize(1)-1
        Lenght(i,1)=pitagoras(x1(i),x2(i));
        Lenght(i,2)=pitagoras(x1(i),x2(i));
        
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
% Pick non intersecting points
%% The third point doesn't intersect
    if comp(1)==comp(2)

        if comp(1)==1
            %the first triangle is larger so the second triangle's first 
            %and second point is needed the first intersection point 
            %then the first triangle's third point then the second intersection point
            %then the first point again
                if a==1
                    x4 = [x2(1),x2(2),x3(1),x1(3),x3(2),x2(1)];
                    y4 = [y2(1),y2(2),y3(1),y1(3),y3(2),y2(1)];
                else
                    x4 = [x2(1),x2(2),x3(2),x1(3),x3(1),x2(1)];
                    y4 = [y2(1),y2(2),y3(2),y1(3),y3(1),y2(1)];
                end
            else
                if a==1
                    x4 = [x1(1),x1(2),x3(1),x2(3),x3(2),x1(1)];
                    y4 = [y1(1),y1(2),y3(1),y2(3),y3(2),y1(1)];
                else
                    x4 = [x2(1),x2(2),x3(2),x1(3),x3(1),x2(1)];
                    y4 = [y2(1),y2(2),y3(2),y1(3),y3(1),y2(1)];
                end
            end
    end
%% The first point doesn't intersect
    if comp(2)==comp(3)

            if comp(2)==1
                if a==1
                    x4 = [x2(2),x2(3),x3(1),x1(1),x3(2),x2(2)];
                    y4 = [y2(2),y2(3),y3(1),y1(1),y3(2),y2(2)];
                else
                    x4 = [x2(2),x2(3),x3(2),x1(1),x3(1),x2(2)];
                    y4 = [y2(2),y2(3),y3(2),y1(1),y3(1),y2(2)];
                end
            else
                if a==1
                    x4 = [x1(2),x1(3),x3(1),x2(1),x3(2),x1(2)];
                    y4 = [y1(2),y1(3),y3(1),y2(1),y3(2),y1(2)];
                else
                    x4 = [x1(2),x1(3),x3(2),x2(1),x3(1),x1(2)];
                    y4 = [y1(2),y1(3),y3(2),y2(1),y3(1),y1(2)];
                end
            end
    end
%% The second point doesn't intersect
    if comp(1)==comp(3)
        
        if comp(2)==1
            if a==1
                x4 = [x1(3),x1(1),x3(1),x2(2),x3(2),x1(3)];
                y4 = [y1(3),y1(1),y3(1),y2(2),y3(2),y1(3)];
            else
                x4 = [x1(3),x1(1),x3(2),x2(2),x3(1),x1(3)];
                y4 = [y1(3),y1(1),y3(2),y2(2),y3(1),y1(3)];
            end
        else
            if a==1
                x4 = [x2(3),x2(1),x3(1),x1(2),x3(2),x2(3)];
                y4 = [y2(3),y2(1),y3(1),y1(2),y3(2),y2(3)];
            else
                x4 = [x2(3),x2(1),x3(2),x1(2),x3(1),x2(3)];
                y4 = [y2(3),y2(1),y3(2),y1(2),y3(1),y2(3)];
            end
        end
    end
%% If there is no two similar points
    if comp(1)~=comp(3) && comp(1)~=comp(2) && comp(2)~=comp(3) 
         errordlg('Inproper use of function "Twodotintersect", calc error!')
    end
    
end

