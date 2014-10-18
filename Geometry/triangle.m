%Triangle plot and area calculation from tri-phase current parameters

% Ideal parameters
Amplitude_1=[10,10,10];                          %[A]
Frequency_1=[50,50,50];                        %[Hz]
Phase_1=[0,2/3*pi,4/3*pi];                     %[rad]

% Real parameters
Amplitude_2=[11,10,9];                          %[A]
Frequency_2=[50,50,50];                        %[Hz]
Phase_2=[0.1*pi,0.6*pi,1.25*pi];                     %[rad]

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
x_3 = Intersection(1,:);
y_3 = Intersection(2,:);
%[x_3,y_3]=poly2ccw(x_3,y_3);
%Mukodni latszik, de akkor van gond, ha csak 2 vagy 1? metszespont van a
%haromszogek k�z�tt, ekkor az eredeti haromsz�gek pontjait kell haszn�lni,
%bizonys felt�telek melett


% Calculate the areas of the polygons
A_1 = polyarea(x_1,y_1)
A_2 = polyarea(x_2,y_2)
A_intersection = polyarea(x_3,y_3)
A_union = A_1+A_2-A_intersection

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