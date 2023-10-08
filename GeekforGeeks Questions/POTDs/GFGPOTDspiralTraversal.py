def findSpiral(root):
    if root==None: return []
    l=[]
    k=[]
    k.append(root)
    
    while(len(k)!=0):
        n=len(k)
        p=[]
        for i in range(n):
            curr=k[0]
            
            if curr.left!=None:
                k.append(curr.left)
                
            if curr.right!=None:
                k.append(curr.right)
                
            p.append(curr.data)
            k.pop(0)
        
        l.append(p)
    
    s=''
    for i in range(len(l)):
        if i%2==0:
            s+=' '.join(map(str,l[i][::-1]))
            s+=' '
        else:
            s+=' '.join(map(str,l[i]))
            s+=' '
    
    li=list(map(int,s.split()))
    return li