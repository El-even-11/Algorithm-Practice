import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Solution {

    public static String countOfAtoms(String formula) {
		HashMap<String, Integer> atoms = new HashMap<>();

		Stack<String> stack = new Stack<>();
		Queue<String> queue = new LinkedList<>();

		for (int i = 0; i < formula.length(); i++) {
			if (formula.charAt(i) >= 'A' && formula.charAt(i) <= 'Z' && i + 1 < formula.length()
					&& formula.charAt(i + 1) >= 'a' && formula.charAt(i + 1) <= 'z') {

				StringBuilder atom = new StringBuilder();
				atom.append(formula.charAt(i)).append(formula.charAt(i + 1));
				queue.offer(atom.toString());
				i++;

			} else if (formula.charAt(i) >= '0' && formula.charAt(i) <= '9') {
				StringBuilder num = new StringBuilder();
				int k = 0;
				for (; k + i < formula.length() && formula.charAt(k + i) >= '0' && formula.charAt(k + i) <= '9'; k++) {
					num.append(formula.charAt(k + i));
				}
				queue.offer(num.toString());
				i += (k - 1);
			} else {
				StringBuilder atom = new StringBuilder();
				atom.append(formula.charAt(i));
				queue.offer(atom.toString());
			}
		}

		while (!queue.isEmpty()) {
			String x = queue.poll();
			if (x.charAt(0) >= 'A' && x.charAt(0) <= 'Z') {
				if (queue.isEmpty() || queue.peek().charAt(0) >= 'A' && queue.peek().charAt(0) <= 'Z'
						|| queue.peek().charAt(0) == '(') {
					atoms.put(x, atoms.getOrDefault(x, 0) + 1);
				} else {
					String times = queue.poll();
				}
			}
		}

		return null;
	}
}