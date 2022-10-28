
def merge_two_binary_trees(tree1, tree2):
    # fill in
    return tree1


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

tree1 = Node(4)
tree1.left = Node(1)
tree1.right = Node(3)

tree2 = Node(5)
tree2.left = Node(10)
tree2.left.left = Node(17)
tree2.left.right = Node(3)
tree2.right = Node(8)

tree3 = Node(6)
tree3.left = Node(3)

tree4 = Node(5)
tree4.left = Node(3)
tree4.left.left = Node(2)
tree4.left.left.left = Node(1)

tree5 = Node(8)
tree5.left = Node(6)
tree5.right = Node(9)
tree5.left.left = Node(5)
tree5.left.right = Node(7)
tree5.right.right = Node(10)


def tree_to_arr(root):
    nodes = []
    stack = [root]
    while stack:
        cur_node = stack[0]
        stack = stack[1:]
        nodes.append(cur_node.val)
        if cur_node.left:
            stack.append(cur_node.left)
        if cur_node.right:
            stack.append(cur_node.right)
    return nodes


import unittest


class Test(unittest.TestCase):
    def test_1(self):
        assert callable(merge_two_binary_trees) == True
        print("PASSED: merge_two_binary_trees should be a function")

    def test_2(self):
        assert tree_to_arr(merge_two_binary_trees(tree1, tree2)) == [9, 11, 11, 17, 3]
        print(
            "PASSED: merge_two_binary_trees(tree1, tree2) should return a merged tree"
        )


if __name__ == "__main__":
    unittest.main(verbosity=2)
    print("Nice job, 2/2 tests passed!")