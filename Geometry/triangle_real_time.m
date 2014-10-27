

n=size(V.signals.values(:,1),1); 
      
for (i=1 : n)
        % kérdés hogy bármely tengelyre illeszthetem-e a referenciát?
        % Ideal parameters
        Amplitude_1=[230,230,230];                     %[V]
        Phase_1=[0,2/3*pi,4/3*pi];                     %[rad]
%        Frequency_1=[50,50,50];                       %[Hz]

        % Real parameters
        Amplitude_2=[Vrms.signals.values(i,1),...
                     Vrms.signals.values(i,2),...
                     Vrms.signals.values(i,3)];        %[V]
        Phase_2=[degtorad(szogt(i,1)),...
                 degtorad(szogt(i,3)),...
                 degtorad(szogt(i,3))];                %[rad]
%        Frequency_2=[50,50,50];                       %[Hz]

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
        %haromszogek között, ekkor az eredeti haromszögek pontjait kell használni,
        %bizonys feltételek melett

        % 2 metszéspont: meg kell írni!!!
        % 1 metszéspont: nem lehet
        % 0 metszéspont: a nagyobból ki kell vonni a kisebbet

        % Calculate the areas of the polygons
        A_1(i) = polyarea(x_1,y_1);
        A_2(i) = polyarea(x_2,y_2);
        A_intersection(i) = polyarea(x_3,y_3);
        A_union(i) = A_1(i)+A_2(i)-A_intersection(i);

        Error_Space(i)=A_union(i)-A_intersection(i);
end
figure
plot(Vrms.time,Error_Space), grid on

% %Polar plot
% figure
% % polar(Phase_2_ex,Amplitude_2_ex,'r-*')
% % hold on
% polar(Phase_1_ex,Amplitude_1_ex,'-*')
% hold on
% polar(Phase_2_ex,Amplitude_2_ex,'r-*')
% plot(x_3,y_3,'k*')
% axis tight
% legend('Ideal','Real','Intersection')