class Solution {
    fun isPalindrome(x: Int): Boolean {
        var num = x.toString()
        var check = true

        for(i in 0..((num.length-1)/2)){
            if(num[i]!=num[num.length-1-i])
            {
                check = false
                break;
            }
        }

        return check
    }
}
