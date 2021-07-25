import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public int[] restoreArray(int[][] adjacentPairs) {

        HashMap<Integer, HashSet<Integer>> map = new HashMap<>();
        for (int[] i : adjacentPairs) {
            if (map.get(i[0]) == null) {
                map.put(i[0], new HashSet<>());
            }
            if (map.get(i[1]) == null) {
                map.put(i[1], new HashSet<>());
            }
            map.get(i[0]).add(i[1]);
            map.get(i[1]).add(i[0]);
        }

        int start = 0;
        for (int i : map.keySet()) {
            if (map.get(i).size() == 1) {
                start = i;
                break;
            }
        }

        int[] ret = new int[adjacentPairs.length + 1];

        ret[0] = start;

        for (int i = 1; i < ret.length; i++) {
            Integer[] adjacent = new Integer[map.get(ret[i - 1]).size()];
            map.get(ret[i - 1]).toArray(adjacent);
            if (adjacent.length == 1) {
                ret[i] = adjacent[0];
            } else {
                ret[i] = adjacent[0] == ret[i - 2] ? adjacent[1] : adjacent[0];
            }
        }

        return ret;
    }
}