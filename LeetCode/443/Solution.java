public class Solution {
    public static int compress(char[] chars) {
        int p1 = 0;
		int p2 = 0;
		while (p2 < chars.length) {
			char now = chars[p2];
			int p = p2;
			while (p2 < chars.length && chars[p2] == now) {
				p2++;
			}
			int cnt = p2 - p;
			chars[p1] = now;
			if (cnt > 1) {
				for (int i = 0; i < ("" + cnt).length(); i++) {
					p1++;
					chars[p1] = ("" + cnt).charAt(i);
				}
				
			}
            p1++;
		}
		return p1;
    }

    public static void main(String[] args){
        compress(new char[]{'a','a','b','b','c','c','c'});
    }
}