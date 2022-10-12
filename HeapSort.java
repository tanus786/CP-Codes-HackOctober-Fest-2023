public class HeapSort {
	public static void sort(int arr[])
	{
		int N = arr.length;

		// Build heap 
		for (int i = N / 2 - 1; i >= 0; i--)
			heapify(arr, N, i);

		
		for (int i = N - 1; i > 0; i--) {
			// Move current root to end
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;

			// call max heapify on the reduced heap
			heapify(arr, i, 0);
		}
	}

	public static void heapify(int arr[], int N, int i)
	{
		int largest = i; 
		int l = 2 * i + 1; 
		int r = 2 * i + 2; 

		// If left child is larger than root
		if (l < N && arr[l] > arr[largest])
			largest = l;

		// If right child is larger than largest so far
		if (r < N && arr[r] > arr[largest])
			largest = r;

		// If largest is not root
		if (largest != i) {
			int swap = arr[i];
			arr[i] = arr[largest];
			arr[largest] = swap;

			// Recursively heapify the affected sub-tree
			heapify(arr, N, largest);
		}
	}

	public static void main(String args[])
	{
        int n = 50;
		int[] arr = new int[n];
		
		for(int i=0;i<n;i++){
            arr[i]=n-i;
        }
        long t1=System.nanoTime();
        sort(arr);
        long t2=System.nanoTime();
        
        System.out.println("input : "+n+" running time : "+(t2-t1));
		
	}
}

