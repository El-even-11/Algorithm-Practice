import java.util.HashMap;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class Solution {
    public Node copyRandomList(Node head) {

        if (head == null) {
            return null;
        }

        Node ret = new Node(head.val);
        Node p = head.next;
        Node q = ret;

        for (; p != null; p = p.next, q = q.next) {
            q.next = new Node(p.val);

        }

        p = head;
        q = ret;
        HashMap<Node, Node> map = new HashMap<>();

        for (; p != null; p = p.next, q = q.next) {
            map.put(p, q);
        }

        p = head;
        q = ret;

        for (; p != null; p = p.next, q = q.next) {
            q.random = map.get(p.random);
        }

        return ret;
    }
}