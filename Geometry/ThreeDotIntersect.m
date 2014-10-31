function [x4,y4] = ThreeDotIntersect(x1,y1,x2,y2,x3,y3)

    for i=1:size(x1,2)-1
            Lenght(i,1)=pitagoras(x1(i),y1(i));
            Lenght(i,2)=pitagoras(x2(i),y2(i));
    end  
    
        [Sorted_Legnght,order]=sort([Lenght(:,1)',Lenght(:,2)']);
        %the inner point
        if order(1)<3 % the point is inside the first triangle
            x4 = [x2(order(1)),x3,x2(order(1))];
            y4 = [y2(order(1)),y3,y2(order(1))];
            k=convhull(x4,y4);
            x4=x4(k);
            y4=y4(k);
        else
            x4 = [x1(order(1)-3),x3,x1(order(1)-3)];
            y4 = [y1(order(1)-3),y3,y1(order(1)-3)];
            k=convhull(x4,y4);
            x4=x4(k);
            y4=y4(k);
        end
end