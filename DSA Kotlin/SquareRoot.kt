class Solution {
    fun mySqrt(x: Int): Int {
        var s : Long  = 0
        var e : Long = x.toLong()

        var mid : Long = s + (e-s)/2
        var res : Long = 0

        while(s<=e){

            if(mid*mid == x.toLong())         
            return mid.toInt()
            else if(mid*mid > x.toLong())
            e = mid - 1
            else{
                res = mid;
                s = mid + 1
            }

            mid = s + (e-s)/2
        }

        return res.toInt()
    }
}