close all
clear all
clc

% function GEO_norm = fcn(amplitude_R,amplitude_S,amplitude_T,phase_R,phase_S,phase_T)
        %% Ideal parameters
        Amplitude_1=[325.3,325.3,325.3];                     %[V]
        %Phase_1=[-1.5855,2.6033,0.5089];
        Phase_1=[0,-2/3*pi,-4/3*pi];                     %[rad]
        % Real parameters
        Amplitude_2=[325.3,320,50];
        Phase_2=[-1.5855,2.6033,0.5089];
        %Amplitude_2=[amplitude_R,amplitude_S,amplitude_T];
        %Phase_2=[phase_R,phase_S,phase_T];
        Amplitude_1_ex=[Amplitude_1 Amplitude_1(1)];
        Phase_1_ex=[Phase_1 Phase_1(1)];
        Amplitude_2_ex=[Amplitude_2 Amplitude_2(1)];
        Phase_2_ex=[Phase_2 Phase_2(1)];
        [xi,yi] = pol2cart(Phase_1_ex,Amplitude_1_ex);
        [xr,yr] = pol2cart(Phase_2_ex,Amplitude_2_ex);
      
        %% Call LinesgementIntersect
            XY1=[xi(1:3)', yi(1:3)', circshift(xi(1:3)',1), circshift(yi(1:3)',1)];
            XY2=[xr(1:3)', yr(1:3)', circshift(xr(1:3)',1), circshift(yr(1:3)',1)];
            % validation
            validateattributes(XY1,{'numeric'},{'2d','finite'});
            validateattributes(XY2,{'numeric'},{'2d','finite'});
            [n_rows_1,n_cols_1] = size(XY1);
            [n_rows_2,n_cols_2] = size(XY2);
            if n_cols_1 ~= 4 || n_cols_2 ~= 4
                error('Arguments must be a Nx4 matrices.');
            end
            % Prepare matrices for vectorized computation of line intersection points.
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
            A.intMatrixX = INT_X .* INT_B;
            A.intMatrixY = INT_Y .* INT_B;
        %% Give variables to further calculation
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

       xcross=IntersectX;
       ycross=IntersectY;
       Inside_triangle=zeros(1,3);
       for i=1:3
           Inside_triangle(i)=inpolygon(xr(i),yr(i),xi,yi);
           
           if Inside_triangle(i)==1
               xcross(end+1)=xr(i);
               ycross(end+1)=yr(i);
           end
       end
k = convhull(xcross,ycross);
xcross=xcross(k);
ycross=ycross(k);
error=polyarea(xi,yi)+polyarea(xr,yr)-2*polyarea(xcross,ycross);

%plot
polar(Phase_1_ex,Amplitude_1_ex,'b-*')
hold on
text(xi(1)*1.1,yi(1)*1.1,'R')
text(xi(2)*1.1,yi(2)*1.1,'S')
text(xi(3)*1.1,yi(3)*1.1,'T')
polar(Phase_2_ex,Amplitude_2_ex,'k-*')
text(xr(1)*1.1,yr(1)*1.1,'R`')
text(xr(2)*1.1,yr(2)*1.1,'S`') 
text(xr(3)*1.1,yr(3)*1.1,'T`')
axis tight
polar(Phase_1_ex,Amplitude_1_ex,'b-*')
plot(xcross,ycross,'o','LineWidth',2,'MarkerSize',10,'MarkerEdgeColor','m')
fill(xcross,ycross,'g')
plot(IntersectX,IntersectY,'o','LineWidth',2,'MarkerSize',10,'MarkerEdgeColor','k')
hold off