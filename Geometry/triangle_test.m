%% Ideal parameters
Amplitude_1=[9,9,9];                          %[A]
Frequency1=[50,50,50];                        %[Hz]
Phase_1=[0,2/3*pi,4/3*pi];                     %[rad]

%% Real parameters
Amplitude_2=[5,5,10];                          %[A]
Frequency2=[50,50,50];                        %[Hz]
Phase_2=[0,2/3*pi,4/3*pi];                     %[rad]

%% Extension of the vectors with the first element to get closed triangles on
%plots and for use as polygons
Amplitude_1_ex=[Amplitude_1 Amplitude_1(1)];
Phase_1_ex=[Phase_1 Phase_1(1)];
Amplitude_2_ex=[Amplitude_2 Amplitude_2(1)];
Phase_2_ex=[Phase_2 Phase_2(1)];
%Transforming to Cartesian coordinates
[x1,y1] = pol2cart(Phase_1_ex,Amplitude_1_ex);
[x2,y2] = pol2cart(Phase_2_ex,Amplitude_2_ex);

%% Intersection points of the triangles
Intersection = poly2poly([x1;y1],[x2;y2]);
x3 = Intersection(1,:);
y3 = Intersection(2,:);

%% Calculate the areas of the polygons
A1 = polyarea(x1,y1);
A2 = polyarea(x2,y2);

%% Calculate intersection aera
if A1==A2
    n1=0;
end
if A1~=A2 && size(x3,2)==0
    n1=1;
end
if A1~=A2 && size(x3,2)==2
    n1=2;
else
    n1=3;
end

switch n1
    case 0
       Error_Space = 0;
        x4=x1;
        y4=y1;
        x5=zeros(1,4);
        y5=zeros(1,4);
    case 1
       Error_Space=abs(A1-A2);
       if (A1-A2)>0
           x4=x1;
           y4=y1;
       else
           x4=x2;
           y4=y2;
       end
       x5=zeros(1,4);
       y5=zeros(1,4);
    case 3
        k=convhull(x3,y3);
        A_intersection = polyarea(x3(k),y3(k));
        A_union = A1+A2-A_intersection;
        Error_Space = A_union-A_intersection;
        x4=x3(k);
        y4=y3(k);
        x5=zeros(1,4);
        y5=zeros(1,4);
    case 2
%% two inters. points



Lenght=zeros(2,size(x1,2)-1);
comp = zeros(1,size(x1,2)-1);
    
    for i=1:size(x1,2)-1
        Lenght(i,1)=pitagoras(x1(i),y1(i));
        Lenght(i,2)=pitagoras(x2(i),y2(i));
        
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
    
    switch n2
        case 0.1
            %square
            x4 = [x2(1),x2(2),x3(1),x3(2),x2(1)];
            y4 = [y2(1),y2(2),y3(1),y3(2),y2(1)];
            k=convhull(x4,y4);
            square_intersect=polyarea(x4(k),y4(k));
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x1(3),y1(3),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x1(3),x3(1)];
            y5 = [y3(1),y3(2),y1(3),y3(1)];
            %triangle_intersect = polyaera(x5,y5);
            triangle_intersect = abs(tianglera);
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                triangle_intersect=0;
            end
        case 0.2
            %square
            x4 = [x1(1),x1(2),x3(1),x3(2),x1(1)];
            y4 = [y1(1),y1(2),y3(1),y3(2),y1(1)];
            k=convhull(x4,y4);
            square_intersect=polyarea(x4(k),y4(k));
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x2(3),y2(3),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x2(3),x3(1)];
            y5 = [y3(1),y3(2),y2(3),y3(1)];
            %triangle_intersect = polyaera(x5,y5);
            triangle_intersect = abs(tianglera);
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                triangle_intersect=0;
            end
        case 1.1
            %square
            x4 = [x2(2),x2(3),x3(1),x3(2),x2(2)];
            y4 = [y2(2),y2(3),y3(1),y3(2),y2(2)];
            k=convhull(x4,y4);
            square_intersect=polyarea(x4(k),y4(k));
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x1(1),y1(1),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x1(1),x3(1)];
            y5 = [y3(1),y3(2),y1(1),y3(1)];
            %triangle_intersect = polyaera(x5,y5);
            triangle_intersect = abs(tianglera);
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                triangle_intersect=0;
            end
        case 1.2
            x4 = [x1(2),x1(3),x3(1),x3(2),x1(2)];
            y4 = [y1(2),y1(3),y3(1),y3(2),y1(2)];
            k=convhull(x4,y4);
            square_intersect=polyarea(x4(k),y4(k));
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x2(1),y2(1),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x2(1),x3(1)];
            y5 = [y3(1),y3(2),y2(1),y3(1)];
            %triangle_intersect = polyaera(x5,y5);
            triangle_intersect = abs(tianglera);
             else
                x5=zeros(1,4);
                y5=zeros(1,4);
                triangle_intersect=0;
            end
        case 2.1
            x4 = [x2(3),x2(1),x3(1),x3(2),x2(3)];
            y4 = [y2(3),y2(1),y3(1),y3(2),y2(3)];
            k=convhull(x4,y4);
            square_intersect=polyarea(x4(k),y4(k));
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x1(2),y1(2),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x1(2),x3(1)];
            y5 = [y3(1),y3(2),y1(2),y3(1)];
            %triangle_intersect = polyaera(x5,y5);
            triangle_intersect = abs(tianglera);
            
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                triangle_intersect=0;
            end
        case 2.2
            x4 = [x1(3),x1(1),x3(1),x3(2),x1(3)];
            y4 = [y1(3),y1(1),y3(1),y3(2),y1(3)];
            k=convhull(x4,y4);
            square_intersect=polyarea(x4(k),y4(k));
            %triangle
            tianglera=det(0.5*[x3(1),y3(1),1;x3(2),y3(2),1;x2(2),y2(2),1]);
            if abs(tianglera)>0.01
            x5 = [x3(1),x3(2),x2(2),x3(1)];
            y5 = [y3(1),y3(2),y2(2),y3(1)];
            %triangle_intersect = polyaera(x5,y5);
            triangle_intersect = abs(tianglera);
            else
                x5=zeros(1,4);
                y5=zeros(1,4);
                triangle_intersect=0;
            end
    end
     
    A_intersection = square_intersect + triangle_intersect;
    A_union = A1+A2-A_intersection;
    Error_Space = A_union-A_intersection;
    
        
end


progr=[n1,n2]
Aeras=[A1,A2]
Sections=[square_intersect,triangle_intersect,A_union,Error_Space]

% if A1==A2
%     Error_Space = 0;
% else if size(x3,2)==0
%         Error_Space=abs(A1-A2);
%     else if size(x3,2)==2
%             A_intersection = polyarea(Twodotintersect(Phase_1_ex,Amplitude_1_ex,Phase_2_ex,Amplitude_2_ex));
%             A_union = A1+A2-A_intersection;
%             Error_Space = A_union-A_intersection;
%          else
%             A_intersection = polyarea(x3,y3);
%             A_union = A1+A2-A_intersection;
%             Error_Space = A_union-A_intersection;
%          end
%     end
% end
%% Polar plot
figure
% polar(Phase_2_ex,Amplitude_2_ex,'r-*')
% hold on
polar(Phase_1_ex,Amplitude_1_ex,'-*')
hold on
polar(Phase_2_ex,Amplitude_2_ex,'r-*')
plot(x3,y3,'k*')
axis tight
legend('Ideal','Real','Intersection')

figure
plot(x1,y1,'b'), hold on, plot(x2,y2,'r'),hold on, fill(x4,y4,'g'), hold on, fill(x5,y5,'c'), grid on