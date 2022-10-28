def letterCombinations(self, digits: str) -> List[str]:
  words={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
  if len(digits)==0:
    return []
  else:
def dfs(start,path):
  if start==len(digits):
    res.append(''.join(path))
    return
    next=digits[start]
  for i in words[next]:
    path.append(i)
    dfs(start+1,path)
    path.pop()
    res=[]
    dfs(0,[])
    return res
