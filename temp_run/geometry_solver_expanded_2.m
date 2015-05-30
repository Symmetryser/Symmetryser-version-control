function [GEO_norm] = geometry_solver_expanded_2( Amplitude_1_ex, Phase_1_ex, Amplitude_2_ex, Phase_2_ex)
    %% write in cartesian
    [xi,yi] = pol2cart(Phase_1_ex,Amplitude_1_ex);
    [xr,yr] = pol2cart(Phase_2_ex,Amplitude_2_ex);
    % find crossing points
    [IntersectX,IntersectY]=polyxpoly(xi,yi,xr,yr);
    % Identify points inside the triangle
    Inside_triangle=zeros(1,3);
    for i=1:3
       Inside_triangle(i)=inpolygon(xr(i),yr(i),xi,yi);
       if Inside_triangle(i)==1
           IntersectX(end+1)=xr(i);
           IntersectY(end+1)=yr(i);
       end
    end
    % Create convex polygon
    if size(IntersectX,1)<3||size(IntersectY,1)<3 
        GEO_norm=polyarea(xi,yi);
    else
        k = convhull(IntersectX,IntersectY);
        IntersectX=IntersectX(k);
        IntersectY=IntersectY(k);
    % calculate error area
    GEO_norm=polyarea(xi,yi)+polyarea(xr,yr)-2*polyarea(IntersectX,IntersectY);
    end
end

