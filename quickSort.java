

public class quicksort {

	public static void main(String[] args) {
		int[] arr= {1,12,5,26,7,13,3,7,2};
		quicksort(arr,0,arr.length-1);
		for(int a:arr)
		{
			System.out.print(a+" ");
		}
		

	}
	public static void quicksort(int[] arr,int lo,int ho)
	{
		if(lo>=ho)
		{
			return;
		}
		int mid =(lo+ho)/2;
		int pivot= arr[mid];
		
		int left =lo;
		int right=ho;
		while(left<right)
		{
			while(arr[left]< pivot)
			{
				left++;
				
			}
			while(arr[right]>pivot)
			{
				right--;
				
			}
			if(left<=right)
			{
				int temp=arr[left];
				arr[left]=arr[right];
				arr[right]=temp;
				left++;
				right--;
				
			}
			
		}
		quicksort(arr,lo,right);
		quicksort(arr,left,ho);
	}

}
