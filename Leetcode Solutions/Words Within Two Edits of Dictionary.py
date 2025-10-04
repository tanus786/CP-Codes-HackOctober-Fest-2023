def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
  
        
        n = len(dictionary[0])
        res = []
        
        for i in range(len(queries)):
               
            for j in range(len(dictionary)):
                count = 0
                k = 0
                a = 0
                while a < n and k < len(dictionary[j]):
                    
                    if queries[i][a] == dictionary[j][k]:
                        count+=1
                    a+=1
                    k+=1
                        
                if n - count <= 2:
                    res.append(queries[i])
                    break
                        
        return res
                
