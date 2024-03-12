import time

class TreeNode:
    def __init__(self, max_keys):
        self.max_keys = max_keys
        self.keys = []
        self.children = []
        self.is_leaf_node = True
        self.next = None

    def insert_key(self, key):
        if key in self.keys:
            print(f"{key} 값이 존재하여 삽입할 수 없음")
            return False
        if self.is_leaf_node:
            self.keys.append(key)
            self.keys.sort()
        else:
            for i, key_value in enumerate(self.keys):
                if key < key_value:
                    return self.children[i].insert_key(key)
            return self.children[-1].insert_key(key)
        return True

    def split(self):
        mid_index = self.max_keys // 2
        if self.is_leaf_node:
            # if leaf node
            new_node = TreeNode(self.max_keys)
            new_node.keys = self.keys[mid_index:]
            new_node.is_leaf_node = True
            new_node.next = self.next
            self.next = new_node
            self.keys = self.keys[:mid_index]
            # Return the new sibling and the lowest key of the new sibling
            return new_node, new_node.keys[0]
        else:
            # elif Internal node
            new_node = TreeNode(self.max_keys)
            new_node.keys = self.keys[mid_index+1:]
            new_node.children = self.children[mid_index+1:]
            new_node.is_leaf_node = False
            self.keys = self.keys[:mid_index]
            self.children = self.children[:mid_index+1]
            # Return the new sibling and the middle key
            return new_node, self.keys[mid_index]

    def is_full(self):
        return len(self.keys) >= self.max_keys

    def range_search(self, min_key, max_key):
        result = []
        node = self
        while not node.is_leaf_node:
            node = node.children[0]
        while node:
            for key in node.keys:
                if min_key <= key <= max_key:
                    result.append(key)
            node = node.next
        return result

class BplusTree:
    def __init__(self, order):
        self.root = TreeNode(order)

    def insert(self, key):
        if not self.root.insert_key(key):
            return
        if self.root.is_full():
            new_root, mid_key = self.root.split()
            new_root_node = TreeNode(self.root.max_keys)
            new_root_node.keys = [mid_key]
            new_root_node.children = [self.root, new_root]
            new_root_node.is_leaf_node = False
            self.root = new_root_node

    def Range(self, min_key, max_key):
        found_keys = self.root.range_search(min_key, max_key)
        if not found_keys:
            print("값을 알 수 없음")
        else:
            return found_keys


bpt = BplusTree(32) 

# open file 
with open("input.txt", "r") as file:
    lines = file.readlines()
    keys = []
    for line in lines:
        elements = line.split(", ") 
        for i in range(len(elements)):
            key = int(elements[i])
            keys.append(key)

# insert          
start = time.time()
for key in keys:
    bpt.insert(key)
insert_t = time.time()-start


# Range
start = time.time()

print(' - Range result')

result = bpt.Range(1, 100) #change

if result:
    print(', '.join(map(str, result)))
else:
    pass

range_t = time.time()-start


print("insert time: ", insert_t)
print("range time: ", range_t)