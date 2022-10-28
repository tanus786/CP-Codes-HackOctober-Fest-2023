int x = 1 ; int y = 1 ;//taking 2 variables for checking 0s in the 0th row and col ;;
        
      for(int j = 0 ; j < matrix[0].length ; j++){//for checking if there is any 0 in the 0th col ;
          if(matrix[0][j] == 0){
               y = 0 ;
          }
      } 
        for(int i = 0 ; i < matrix.length ; i++ ){//for checking if there is any 0 in the 0th row ;
            if(matrix[i][0] == 0){
                x = 0 ;
            }
        }
//now checking for zeroes in the matrix whothout tkaing the 0th row and column in play 
//and making the 0th row and col if we find any ;
        for(int i = 0  ; i < matrix.length ; i++){
            for(int j = 0 ; j < matrix[i].length ; j++){
                if(matrix[i][j] == 0 ){
                    matrix[0][j] = 0 ;
                    matrix[i][0] = 0 ;
                }
            }
        }
        //we are only making the column zero first when finding 0 in the row 
        for(int j = 1 ; j < matrix[0].length ; j++){
        if(matrix[0][j] == 0){
            for(int i = 0 ; i < matrix.length ; i++){
                matrix[i][j] =0 ;
               }
            }    
        }
        //here we are making the whole row to be 0 only not the column ;
        for(int i = 1 ; i < matrix.length ; i++){
            if(matrix[i][0] == 0 ){
                for(int j = 0 ; j < matrix[0].length ; j++){
                    matrix[i][j] = 0 ;
                }
            }
        }
        
        if(y == 0){//making the whole 0th row zero if ew had found any 0s before in it ;
            for(int i = 0 ; i <matrix[0].length ; i++){
                matrix[0][i] = 0 ;
            }
        }
        if(x == 0){//doing the same for 0th column ;
            for(int i = 0 ; i < matrix.length ; i++){
                matrix[i][0] = 0 ;
            }
        }
       //we are not returning anything bcz the function is void ;
