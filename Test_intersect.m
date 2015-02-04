%close all;
load('saved_data/GEO_saved.mat');
load('saved_data/V_AMP_saved.mat');
load('saved_data/V_ANG_saved.mat');
sample=10e-5; 
%% Ideal parameters
Amplitude_1=[325.3,325.3,325.3];                          %[A]
Phase_1=[-1.5855,2.6033,0.5089];
%Phase_1=[0,-2/3*pi,-4/3*pi];                     %[rad]


%% Real parameters

prompt = {'Enter the measurement time'};
        dlg_title = 'Inspect Geometry';
        num_lines = 1;
        defAns = {'4'};
        options = 'off';
        answer = inputdlg(prompt,dlg_title,num_lines,defAns,options);
        if str2num(answer{1})>max(V_AMP_saved.time)
                errordlg('Time out of time range')
        end

i=str2num(answer{1})/sample;

% Amplitude_2=[Vrms.signals.values(i,1),...
%              Vrms.signals.values(i,2),...
%              Vrms.signals.values(i,3)];                           %[A]
% Phase_2=[degtorad(szogt(i,1)),...
%          degtorad(szogt(i,3)),...
%          degtorad(szogt(i,3))];        %[rad]

Amplitude_2=V_AMP_saved.data(i,:);
Phase_2=V_ANG_saved.data(i,:);
             

%% Extension of the vectors with the first element to get closed triangles on
%plots and for use as polygons
Amplitude_1_ex=[Amplitude_1 Amplitude_1(1)];
Phase_1_ex=[Phase_1 Phase_1(1)];
Amplitude_2_ex=[Amplitude_2 Amplitude_2(1)];
Phase_2_ex=[Phase_2 Phase_2(1)];
%Transforming to Cartesian coordinates
[x1,y1] = pol2cart(Phase_1_ex,Amplitude_1_ex);
[x2,y2] = pol2cart(Phase_2_ex,Amplitude_2_ex);

figure
polar(Phase_1_ex,Amplitude_1_ex,'-*')
hold on
polar(Phase_2_ex,Amplitude_2_ex,'r-*')
axis tight
legend('Ideal','Real','Intersection')


[xa, ya] = polybool('union', x1, y1, x2, y2);
[xb, yb] = polybool('intersection', x1, y1, x2, y2);
[xc, yc] = polybool('xor', x1, y1, x2, y2);
[xd, yd] = polybool('subtraction', x1, y1, x2, y2);

areas_u_i_x_s=[polyarea(xa,ya),polyarea(xb,yb),polyarea(xc,yc),polyarea(xd,yd)]

figure
plot(x1,y1,'b','LineWidth',3), hold on
plot(x2,y2,'r','LineWidth',3),hold on
fill(xa,ya,'g'), hold on
fill(xb,yb,'c'), grid on
legend('Ideal','Real','Union','Intersection')

figure
subplot(2, 2, 1)
patch(xa, ya, 1, 'FaceColor', 'g')
axis equal, axis off, hold on
plot(x1, y1, x2, y2, 'Color', 'k')
title('Union')

subplot(2, 2, 2)
patch(xb, yb, 1, 'FaceColor', 'c')
axis equal, axis off, hold on
plot(x1, y1, x2, y2, 'Color', 'k')
title('Intersection')

subplot(2, 2, 3)
% The output of the exclusive-or operation consists of disjoint
% regions.  It can be plotted as a single patch object using the
% face-vertex form.  Use poly2fv to convert a polygonal region
% to face-vertex form.
[f, v] = poly2fv(xc, yc);
patch('Faces', f, 'Vertices', v, 'FaceColor', 'r', ...
  'EdgeColor', 'none')
axis equal, axis off, hold on
plot(x1, y1, x2, y2, 'Color', 'k')
title('Exclusive Or')

subplot(2, 2, 4)
patch(xd, yd, 1, 'FaceColor', 'b')
axis equal, axis off, hold on
plot(x1, y1, x2, y2, 'Color', 'k')
title('Subtraction')