class Solution(object):
    def inorderTraversal(self, root):
        stack = []
        ret = []
        temp = root
        while temp or stack:
            while temp:
                stack.append(temp)
                temp = temp.left
            if stack:
                temp = stack.pop()
                ret.append(temp.val)
                temp = temp.right
        return ret
