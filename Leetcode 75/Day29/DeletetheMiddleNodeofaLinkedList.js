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
var deleteMiddle = function(head) {
    if (head.next == null || head == null) return null
    let prev = null
    let slow = head
    let fast = head

    while(fast!=null && fast.next != null){
        prev = slow
        slow = slow.next
        fast = fast.next.next
    }
    prev.next = slow.next
    slow = null
    return head
};