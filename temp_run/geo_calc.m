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
       %%
%         IMtx=[xi(1) yi(1);xi(2) yi(2)];
%         RMtx =[xr(1) yr(1);xr(2) yr(2)];
%        
%         x=(-det(RMtx)/(RMtx(2,2)-RMtx(1,2))+det(IMtx)/(IMtx(2,1)-IMtx(1,1)))/...
%             ((IMtx(2,2)-IMtx(1,2)/(IMtx(2,1)-IMtx(1,1)))-(RMtx(2,2)-RMtx(1,2)/(RMtx(2,1)-RMtx(1,1))));
%         
%         y=(det(RMtx)/(RMtx(2,2)-RMtx(1,2))-det(IMtx)/(IMtx(2,2)-IMtx(1,2)))/...
%             ((IMtx(2,1)-IMtx(1,1)/(IMtx(2,2)-IMtx(1,2)))-(RMtx(2,1)-RMtx(1,1)/(RMtx(2,2)-RMtx(1,2))));
        %%
        XYI=[xi(1:3)', yi(1:3)', circshift(xi(1:3)',1), circshift(yi(1:3)',1)];
        XYR=[xr(1:3)', yr(1:3)', circshift(xr(1:3)',1), circshift(yr(1:3)',1)];
        A=lineSegmentIntersect(XYI,XYR);
        %Sort out valid intersection points
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
        
       %[xintersect,yintersect]=polyxpoly(xi,yi,xr,yr);
       
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