ll arr[10000007];//stores the no of divisors of the no in it's index

ll f(ll n, ll k){//helper function 
	ll r = 0;
	
	while(n%k == 0){
		n /= k;
		r++;
	}
	
	return r;
}

void sieve(){
	
	arr[1] = 1;
	
	for(ll i=2; i<=1e7; i++){
		
		if(arr[i] == 0){//this is a prime no 
			arr[i] = 2;
			for(ll j=i+i; j<=1e7; j += i){
				if(arr[j] == 0){
					arr[j] = 1;
				}
				ll ans = f(j, i);
				arr[j] *= (ans+1);
			}
		}
		
	}
	
}
