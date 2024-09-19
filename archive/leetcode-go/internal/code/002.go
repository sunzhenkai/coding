package code

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var r *ListNode = nil
	var loop *ListNode = nil
	carry := 0
	remain := 0
	for l1 != nil || l2 != nil || carry > 0 {
		if l1 != nil {
			remain += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			remain += l2.Val
			l2 = l2.Next
		}

		if remain > 9 {
			carry = remain / 10
			remain %= 10
		}
		cn := &ListNode{
			Next: nil,
			Val:  remain,
		}
		if r == nil {
			r = cn
		} else {
			loop.Next = cn
		}
		loop = cn
	}
	return r
}
