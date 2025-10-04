def oddString(self, words: List[str]) -> str:
        
        N  = len(words)
        n = len(words[0])
        
        d = {"a":0,"b":1,"c":2,"d":3,"e":4,"f":5,"g":6,"h":7,"i":8,"j":9,"k":10,"l":11,"m":12,"n":13,"o":14,"p":15,"q":16,"r":17,
            "s":18,"t":19,"u":20,"v":21,"w":22,"x":23,"y":24,"z":25}
        
        
        diff_arr = []
        
        for i in range(N):
            res = []
            
            for j in range(1,n):
                res.append(d[words[i][j]]-d[words[i][j-1]])
                
            diff_arr.append(res)
        
        
        a = diff_arr[0]
        b = diff_arr[1]
        c = diff_arr[2]
        
        if a == b == c:
            ele = a
            for i in range(len(diff_arr)):
                
                if ele != diff_arr[i]:
                    u = i
                    
        elif a == b:
            u = 2
        elif a == c:
            u = 1
        elif b == c:
            u = 0
        
        return words[u]
        
