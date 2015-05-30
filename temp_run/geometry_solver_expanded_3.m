function [GEO_norm] = geometry_solver_expanded_3( Amplitude_1_ex, Phase_1_ex, Amplitude_2_ex, Phase_2_ex)
    %% write in cartesian
    [xi,yi] = pol2cart(Phase_1_ex,Amplitude_1_ex);
    [xr,yr] = pol2cart(Phase_2_ex,Amplitude_2_ex);
    % find crossing points
    XY1=[xi(1:3)', yi(1:3)', circshift(xi(1:3)',1), circshift(yi(1:3)',1)];
    XY2=[xr(1:3)', yr(1:3)', circshift(xr(1:3)',1), circshift(yr(1:3)',1)];
    
    %%
    validateattributes(XY1,{'numeric'},{'2d','finite'});
    validateattributes(XY2,{'numeric'},{'2d','finite'});

    [n_rows_1,n_cols_1] = size(XY1);
    [n_rows_2,n_cols_2] = size(XY2);

    if n_cols_1 ~= 4 || n_cols_2 ~= 4
        error('Arguments must be a Nx4 matrices.');
    end

    %%% Prepare matrices for vectorized computation of line intersection points.
    %-------------------------------------------------------------------------------
    X1 = repmat(XY1(:,1),1,n_rows_2);
    X2 = repmat(XY1(:,3),1,n_rows_2);
    Y1 = repmat(XY1(:,2),1,n_rows_2);
    Y2 = repmat(XY1(:,4),1,n_rows_2);

    XY2 = XY2';

    X3 = repmat(XY2(1,:),n_rows_1,1);
    X4 = repmat(XY2(3,:),n_rows_1,1);
    Y3 = repmat(XY2(2,:),n_rows_1,1);
    Y4 = repmat(XY2(4,:),n_rows_1,1);

    X4_X3 = (X4-X3);
    Y1_Y3 = (Y1-Y3);
    Y4_Y3 = (Y4-Y3);
    X1_X3 = (X1-X3);
    X2_X1 = (X2-X1);
    Y2_Y1 = (Y2-Y1);

    numerator_a = X4_X3 .* Y1_Y3 - Y4_Y3 .* X1_X3;
    numerator_b = X2_X1 .* Y1_Y3 - Y2_Y1 .* X1_X3;
    denominator = Y4_Y3 .* X2_X1 - X4_X3 .* Y2_Y1;

    u_a = numerator_a ./ denominator;
    u_b = numerator_b ./ denominator;

    % Find the adjacency matrix A of intersecting lines.
    INT_X = X1+X2_X1.*u_a;
    INT_Y = Y1+Y2_Y1.*u_a;
    INT_B = (u_a >= 0) & (u_a <= 1) & (u_b >= 0) & (u_b <= 1);
    PAR_B = denominator == 0;
    COINC_B = (numerator_a == 0 & numerator_b == 0 & PAR_B);


    % Arrange output.
    out.intAdjacencyMatrix = INT_B;
    out.intMatrixX = INT_X .* INT_B;
    out.intMatrixY = INT_Y .* INT_B;
    out.intNormalizedDistance1To2 = u_a;
    out.intNormalizedDistance2To1 = u_b;
    out.parAdjacencyMatrix = PAR_B;
    out.coincAdjacencyMatrix= COINC_B;
    %%
    %Sort out invalid intersection points
    IntersectX=[out.intMatrixX(1,:),out.intMatrixX(2,:),out.intMatrixX(3,:)];
    IntersectY=[out.intMatrixY(1,:),out.intMatrixY(2,:),out.intMatrixY(3,:)];
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

