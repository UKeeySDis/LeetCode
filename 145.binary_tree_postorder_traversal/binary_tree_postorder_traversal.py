class Solution(object):
    def postorderTraversal(self, root):
        ret = []
        stack = []
        pre = None
        cur = root
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack[-1]
            if cur.right == None or cur.right == pre:
                del stack[-1]
                ret.append(cur.val)
                pre = cur
                cur = None
            else:
                cur = cur.right
        return ret
