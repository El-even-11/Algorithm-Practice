import java.util.Arrays;

class Solution {
    public static int compareVersion(String version1, String version2) {
        String[] nums1 = version1.split(".");
        String[] nums2 = version2.split(".");

        int max = Math.max(nums1.length, nums2.length);

        int[] n1 = new int[max];
        int[] n2 = new int[max];
        Arrays.fill(n1, 0);
        Arrays.fill(n2, 0);

        for (int i = 0; i < nums1.length; i++) {
            n1[i] = Integer.parseInt(nums1[i]);
        }

        for (int i = 0; i < nums2.length; i++) {
            n2[i] = Integer.parseInt(nums2[i]);
        }

        for (int i = 0; i < max; i++) {
            if (n1[i] > n2[i]) {
                return 1;
            }
            if (n1[i] < n2[i]) {
                return -1;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        System.out.println(compareVersion("0.1", "1.1"));
    }
}