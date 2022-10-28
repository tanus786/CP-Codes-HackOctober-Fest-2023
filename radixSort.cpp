class Solution {
public:
    
    int getDigit(int num, int factor) 
    {
        return (abs(num) / abs(factor)) % 10;
    }
    
    void radixCountingSort(vector<int> &nums, int factor) 
    {
        int freqSize = 10, size = nums.size();
        vector<int> freq(freqSize, 0), sorted(size, 0);
        
        for (int ind = 0; ind < size; ind++)
            freq[getDigit(nums[ind], factor)]++;
        
        /* cout << "\n\n Freq array changed: ";
        for (int ind = 0; ind < freqSize; ind++)
            cout << freq[ind] <<  " "; */
        
        for (int ind = 1; ind < freqSize; ind++)
            freq[ind] += freq[ind - 1];
        
        /* cout << "\n\n Freq array further changed: ";
        for (int ind = 0; ind < freqSize; ind++)
            cout << freq[ind] <<  " "; */
        
        // for stable sorting start ind from end and decrement till 0
        
        for (int ind = size - 1; ind >= 0; ind--) 
            sorted[freq[getDigit(nums[ind], factor)]-- - 1] = nums[ind];
        
        nums = sorted;
        
        /* cout << "\n\n nums array formed: ";
        for (int ind = 0; ind < size; ind++)
            cout << nums[ind] <<  " "; */
    }
    
    void radixSort(vector<int> &nums)
    {
        int minVal = *min_element(nums.begin(), nums.end());
        
        /* cout << "\n \n Minimum element in original array is: " << minVal <<endl;
        cout << "\n Array elements after subtracting minval from each one of elements: "; */
        
        for(auto &num : nums) {
            num -= minVal;
            /* cout << num << " "; */ 
        }
        
        int factor = 1, maxVal = *max_element(nums.begin(), nums.end());
        /* cout << "\n \n Maximum element in changed or upper line array is: " << maxVal; */
        
        while (maxVal / factor) 
        {
            /* cout << "\n\n While Loop ith iteration: " << endl;
            cout << "\n " << maxVal << "/" << factor << " : " << maxVal/factor; */  
            radixCountingSort(nums, factor);
            factor *= 10;
        }
        
        /*cout << "\n\n While loop ended" << endl;*/
        
        for (auto &num : nums) 
            num += minVal;
        
        /* cout << "\n After adding minval to each element which we subtracted in the beginning: ";
        cout << "\n\n Final sorted nums array: ";
            
        for (auto &num : nums) 
            cout << num << " "; */
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        /* cout << "\n Original array: ";
        for(int i=0; i<nums.size(); i++)
            cout << nums[i] << " "; */
        
        radixSort(nums);
        return nums;
        
    }
};