

%The triangles are build from the points you provide to the delauny function. 
% The numbers it contains are the indices in xd/yd used to create a triagle. 
% Since a triangle has 3 corner points you have 3 indices in TRI and the indices are the same for xd and yd 
% (thats why you have 3 values instead of 6).
% Maybe use triplot to see how the triangulation looks to get a better feeling for it.
% After delauny was called use:

% triplot(tri,xd,yd)
% hold on
% plot(xd,yd,'r*')
% hold off

%From what I can see it seems like your area is convex anyway so you might 
%can call polyare directly with xd and yd instead of doing the triangulation.
%So as example

a= 5;
b = 8;
t=(0:pi/20:2*pi);
x1=a*cos(t);
y1=b*sin(t);
x2=a*cos(t);
y2=b*sin(t);
[xd, yd] = polybool('intersection', x1, y1, x2, y2);%donner les points appartenent ? la fois ? xi et xj
pa = polyarea(xd,yd)

%used triangulation
tri = delaunay(xd,yd);
%returns a set of triangles such that no data points 
% Each row of the numt-by-3  matrix TRI defines one such triangle 
% and contains indices into the
areaintersect=0;
for i=1:size(tri,1)
    areaintersect = areaintersect + polyarea([xd(tri(i,1)),xd(tri(i,2)),xd(tri(i,3))], [yd(tri(i,1)),yd(tri(i,2)),yd(tri(i,3))] );
end
areaintersect

triplot(tri,xd,yd)
hold on
plot(xd,yd,'r*')
hold off

