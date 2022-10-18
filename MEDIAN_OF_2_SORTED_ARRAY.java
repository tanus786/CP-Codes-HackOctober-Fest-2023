class Solution {
	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    int index1 = 0;
    int index2 = 0;
    int med1 = 0;
    int med2 = 0;
    for (int i=0; i<=(nums1.length+nums2.length)/2; i++) {
    med1 = med2;
 
    if (index1 == nums1.length) 
    {
        med2 = nums2[index2];
        index2++;
    } 
    else if (index2 == nums2.length) {
        med2 = nums1[index1];
        index1++;
    } 
    else if (nums1[index1] < nums2[index2] ) {
        med2 = nums1[index1];
     index1++;
    }
        else {
        med2 = nums2[index2];
        index2++;
        }
    }

if ((nums1.length+nums2.length)%2 == 0){
        return (float)(med1+med2)/2;
}
 return med2;
}
}