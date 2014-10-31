close all;
clear all;

%% Ideal parameters
Amplitude_1=[10,10,10];                          %[A]
Frequency1=[50,50,50];                        %[Hz]
Phase_1=[0,2/3*pi,4/3*pi];                     %[rad]

%% Real parameters
Amplitude_2=[15,4,5];                          %[A]
Frequency2=[50,50,50];                        %[Hz]
Phase_2=[0,2/3*pi,4/3*pi]+2/3*pi;                     %[rad]

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

%% Polar Plot
figure
polar(Phase_1_ex,Amplitude_1_ex,'-*')
hold on
polar(Phase_2_ex,Amplitude_2_ex,'r-*')
plot(x3,y3,'k*')
axis tight
legend('Ideal','Real','Intersection')

%% Calculate the areas of the polygons
A1 = polyarea(x1,y1);
A2 = polyarea(x2,y2);
dist_inter=distance(x3(1),y3(1),x3(2),y3(2));
lateria=distance(x1(1:3),y1(1:3),x2(1:3),y2(1:3));
         
%n1 = IntersectType( A1,A2,x1,y1,x2,y2,x3);
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
    end
    if size(x3,2)>3
        n1=4;
    end
n2 = -1;
triangle_intersect = 0;
square_intersect = 0;

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
           x4=x2;
           y4=y2;
       else
           x4=x1;
           y4=y1;
       end
       x5=zeros(1,4);
       y5=zeros(1,4);
    case 2
        
         %% pontok összehasonlítása
        %n2 = CompareDots(x1,y1,x2,y2); 
        Lenght=zeros(2,size(x1,2)-1);
comp = zeros(1,size(x1,2)-1);
    
    for i=1:size(x1,2)-1
        Lenght(i,1)=pitagoras(x1(i),y1(i));
        Lenght(i,2)=pitagoras(x2(i),y2(i));
    end
    %ide be kell szúrni egy jobb összehasonlítást, 
    %ha 180fok körüli eltérés van, a háromszöget rosszul számítja a program
    % A háromszögek csúcsait nem páronként kell összevetni
    
    for i=1:size(x1,2)-1   
        for j=1:size(x1,2)-1 
            if Lenght(i,1)>Lenght(j,2)
                comp(i,j)=1;
            end
            if Lenght(i,1)==Lenght(j,2)
                comp(i,j)=0;
            end
            if Lenght(i,1)<Lenght(j,2)
                comp(i,j)=-1;
            end
        end
    end
    % ezt kell módosítani
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
    
   %% 
        %metszet számítása 2 metszéspont esetén
        [x4,y4,x5,y5] = TwoDotIntersect(x1,y1,x2,y2,x3,y3,n2); 
        square_intersect = polyarea(x4,y4);
        if [x5;y5]~=zeros(2,size(x5,2))
            triangle_intersect = polyarea(x5,y5);
        else
            triangle_intersect = 0;
        end
        A_intersection = square_intersect + triangle_intersect;
        A_union = A1+A2-A_intersection;
        Error_Space = A_union-A_intersection;
    case 3
        [x4,y4] = ThreeDotIntersect(x1,y1,x2,y2,x3,y3);
        A_intersection = polyarea(x4,y4);
        A_union = A1+A2-A_intersection;
        Error_Space = A_union-A_intersection;
   case 4
        k=convhull(x3,y3);
        A_intersection = polyarea(x3(k),y3(k));
        A_union = A1+A2-A_intersection;
        Error_Space = A_union-A_intersection;
        x4=x3(k);
        y4=y3(k);
        x5=zeros(1,4);
        y5=zeros(1,4);
end


progr=[n1,n2]
Aeras=[A1,A2]
Sections=[square_intersect,triangle_intersect,A_union,Error_Space]

%% Plot
figure
plot(x1,y1,'b','LineWidth',2), hold on
plot(x2,y2,'r','LineWidth',2),hold on
fill(x4,y4,'g'), hold on
fill(x5,y5,'c'), grid on
legend('Ideal','Real','Square Intersection','Triangle Intersection')