function [  ] = transformation(  )
    HOME = [0 0 0 ; 50 50 0 ; 50 0 0];
    
        if i == 1
            TRANS_MAT =  [1 0 0 ; 0 1 0 ; 0 0 1];
        end
        if i == 2
             angle = 30 * 22 / 7 / 180;
            TRANS_MAT =  [cos(angle) -sin(angle) 0 ; sin(angle) cos(angle) 0 ; 0 0 1];
         end
         if i == 3
            TRANS_MAT =  [-1 0 0 ; 0 1 0 ; 0 0 1];
         end
         if i == 4
             scale = 0.3;
            TRANS_MAT =  [scale 0 0 ; 0 scale 0 ; 0 0 1];
         end
         if i == 5
             skewx = 0.3;
            TRANS_MAT =  [1 skewx 0 ; 0 1 0 ; 0 0 1];
         end
         if i == 6
             transx = 30;
             transy = 20;
            TRANS_MAT =  [1 0 transx ; 0 1 transy ; 0 0 1];
         end
        newHome_X = [];
        newHome_Y = [];
        for j =1:length(HOME)
            oldPoint = [ HOME(j,1) ; HOME(j,2) ; 1 ];
            newPoint = TRANS_MAT * oldPoint;
            newHome_X(end+1) = newPoint(1);
            newHome_Y(end+1) = newPoint(2);

        end
        subplot(3,2,i);
        plot(newHome_X,newHome_Y);
        title('Transformation');
    end