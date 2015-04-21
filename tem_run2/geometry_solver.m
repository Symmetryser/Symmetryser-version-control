function [GEO_norm] = geometry_solver( Amplitude_1_ex, Phase_1_ex, Amplitude_2_ex, Phase_2_ex)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here


%Transforming to Cartesian coordinates

        [x1,y1] = pol2cart(Phase_1_ex,Amplitude_1_ex);
        [x2,y2] = pol2cart(Phase_2_ex,Amplitude_2_ex);
        [xa, ya] = polybool('union', x1, y1, x2, y2);
        [xb, yb] = polybool('intersection', x1, y1, x2, y2);
        GEO_norm=polyarea(xa,ya)-polyarea(xb,yb);

end

