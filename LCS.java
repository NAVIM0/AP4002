public class LCS {
    public static int lcs(String str1, String str2, int str1len, int str2len, int count) {
        if (str1len == 0 || str2len == 0) {
            return count;
        }
        if (str1.charAt(str1len-1) == str2.charAt(str2len-1)){
            count = lcs(str1, str2 ,str1len-1, str2len-1,count + 1);
        }
        int count2 = lcs(str1, str2, str1len-1, str2len, 0);
        int count3 = lcs(str1, str2, str1len, str2len-1, 0);
    
        return Math.max(count,Math.max(count2, count3));
    }
      
    public static void main(String[] args) {
        System.out.println(lcs("FirstString", "SecondString", 11, 12,0));
    }
}

