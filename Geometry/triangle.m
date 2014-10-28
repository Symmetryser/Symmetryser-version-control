%Triangle plot and area calculation from tri-phase current parameters

% Ideal parameters
Amplitude_1=[9,9,9];                          %[A]
Frequency_1=[50,50,50];                        %[Hz]
Phase_1=[0,2/3*pi,4/3*pi];                     %[rad]

% Real parameters
Amplitude_2=[5,5,9];                          %[A]
Frequency_2=[50,50,50];                        %[Hz]
Phase_2=[0,2/3*pi,4/3*pi]+0.1;                     %[rad]

%Extension of the vectors with the first element to get closed triangles on
%plots and for use as polygons
Amplitude_1_ex=[Amplitude_1 Amplitude_1(1)];
Phase_1_ex=[Phase_1 Phase_1(1)];
Amplitude_2_ex=[Amplitude_2 Amplitude_2(1)];
Phase_2_ex=[Phase_2 Phase_2(1)];
%Transforming to Cartesian coordinates
[x_1,y_1] = pol2cart(Phase_1_ex,Amplitude_1_ex);
[x_2,y_2] = pol2cart(Phase_2_ex,Amplitude_2_ex);

%Intersection of the triangles
Intersection = poly2poly([x_1;y_1],[x_2;y_2]);
%Intersection = polyxpoly(x_1,y_1,x_2,y_2);
Isize=size(Intersection);
x_3 = Intersection(1,:);
y_3 = Intersection(2,:);
%[x_3,y_3]=poly2ccw(x_3,y_3);
%Mukodni latszik, de akkor van gond, ha csak 2 vagy 1? metszespont van a
%haromszogek között, ekkor az eredeti haromszögek pontjait kell használni,
%bizonys feltételek melett

% 2 metszéspont: meg kell írni!!!
% 1 metszéspont: nem lehet
% 0 metszéspont: a nagyobból ki kell vonni a kisebbet

% Calculate the areas of the polygons

A1 = polyarea(x_1,y_1)
A2 = polyarea(x_2,y_2)

if A1==A2
    Error_Space = 0;
else if Isize(2)==0
        Error_Space=abs(A1-A2);
    else if Isize(2)==2
            A_intersection = polyarea(Twodotintersect(Phase_1_ex,Amplitude_1_ex,Phase_2_ex,Amplitude_2_ex));
            A_union = A1+A2-A_intersection;
            Error_Space = A_union-A_intersection;
         else
            A_intersection = polyarea(x_3,y_3);
            A_union = A1+A2-A_intersection;
            Error_Space = A_union-A_intersection;
         end
    end
end




%Polar plot
figure
% polar(Phase_2_ex,Amplitude_2_ex,'r-*')
% hold on
polar(Phase_1_ex,Amplitude_1_ex,'-*')
hold on
polar(Phase_2_ex,Amplitude_2_ex,'r-*')
plot(x_3,y_3,'k*')
axis tight
legend('Ideal','Real','Intersection')