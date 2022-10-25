
def TOH(n , s, d, aux):
	if n==1:
		print ("Move disk 1 from ",s,"to ",d)
		return
	TOH(n-1, s, aux, d)
	print ("Move disk",n,"from ",s,"to ",d)
	TOH(n-1, aux, d, s)
n = 4
TOH(n,'A','B','C')