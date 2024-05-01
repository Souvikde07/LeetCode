/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var oddEvenList = function(head) {
    if(head == null || head.next == null || head.next.next == null){
        return head;
    }
    let odd = new ListNode(head.val);
    let even = new ListNode(head.next.val);
    let oddPtr = odd;
    let evenPtr = even;
    let ptr = head.next.next;
    let count = 2;
    while(ptr != null){
        count++;
        if(count % 2 == 0){
            let n = new ListNode(ptr.val);
            evenPtr.next = n;
            evenPtr = evenPtr.next;
        }
        else{
            let n = new ListNode(ptr.val);
            oddPtr.next = n;
            oddPtr = oddPtr.next;
        }
        if(ptr.next == null){
            oddPtr.next = even;
        }
        ptr = ptr.next;
    }
    return odd;
};