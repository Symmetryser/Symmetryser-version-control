function [GEO_norm] = geometry_solver_expanded_1( Amplitude_1_ex, Phase_1_ex, Amplitude_2_ex, Phase_2_ex)
    %% write in cartesian
    [xi,yi] = pol2cart(Phase_1_ex,Amplitude_1_ex);
    [xr,yr] = pol2cart(Phase_2_ex,Amplitude_2_ex);
    % find crossing points
    XYI=[xi(1:3)', yi(1:3)', circshift(xi(1:3)',1), circshift(yi(1:3)',1)];
    XYR=[xr(1:3)', yr(1:3)', circshift(xr(1:3)',1), circshift(yr(1:3)',1)];
    A=lineSegmentIntersect(XYI,XYR);
    %Sort out invalid intersection points
    IntersectX=[A.intMatrixX(1,:),A.intMatrixX(2,:),A.intMatrixX(3,:)];
    IntersectY=[A.intMatrixY(1,:),A.intMatrixY(2,:),A.intMatrixY(3,:)];
    % Miért kell ezt 3-szor futtatni??
    for s=1:3
        i=0;
        while i<length(IntersectX)
            i=i+1;
            if IntersectX(i)==0 && IntersectY(i)==0
                IntersectX(i)=[];
                IntersectY(i)=[];
            end
        end
    end
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

