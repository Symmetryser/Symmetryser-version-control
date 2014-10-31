theta = linspace(0, 2*pi, 100);
x1 = cos(theta) - 0.5;
y1 = -sin(theta);    % -sin(theta) to make a clockwise contour
x2 = x1 + 1;
y2 = y1;

%[x1,y1] = poly2cw([15;15;14;15],[15;16;16;15]); % triangle
%[x3,y3] = poly2cw([15;15;14;15]/19,[15;16;16;15]/19); % triangle2

%% Ideal parameters
Amplitude_1=[10,10,10];                          %[A]
Frequency1=[50,50,50];                        %[Hz]
Phase_1=[0,2/3*pi,4/3*pi];                     %[rad]

%% Real parameters
Amplitude_2=[15,44,5];                          %[A]
Frequency2=[50,50,50];                        %[Hz]
Phase_2=[0,2/3*pi,4/3*pi]+2*pi;                     %[rad]

%% Extension of the vectors with the first element to get closed triangles on
%plots and for use as polygons
Amplitude_1_ex=[Amplitude_1 Amplitude_1(1)];
Phase_1_ex=[Phase_1 Phase_1(1)];
Amplitude_2_ex=[Amplitude_2 Amplitude_2(1)];
Phase_2_ex=[Phase_2 Phase_2(1)];
%Transforming to Cartesian coordinates
[x1,y1] = pol2cart(Phase_1_ex,Amplitude_1_ex);
[x2,y2] = pol2cart(Phase_2_ex,Amplitude_2_ex);


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