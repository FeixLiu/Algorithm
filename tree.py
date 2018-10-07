from queue import Queue

class Node:
	def __init__(self, data, lc = None, rc = None):
		self.data = data
		self._lc = lc
		self._rc = rc
	
	def get_data(self):
		return str(self.data)
		
	def get_rc(self):
		return rc
		
	def get_lc(self):
		return lc

def preorder(root):
	print(root.get_data())
	if root.get_lc() != None:
		preorder(root.get_lc())
	if root.get_rc() != None:
		preorder(root.get_rc())
		
def midorder(root):
	if root.get_lc() != None:
		midorder(root.get_lc())
	print(root.get_data())
	if root.get_rc() != None:
		midorder(root.get_rc())
		
def lastorder(root):
	if root.get_lc() != None:
		lastorder(root.get_lc())
	if root.get_rc() != None:
		lastorder(root.get_rc())
	print(root.get_data())
	
def depth_first(root):
	if root is None:
		return
	nodeset = set()
	nodeset.add(root)
	while nodeset:
		cur = nodeset.pop(0)
		print(cur.get_data())
		if root.get_lc() != None:
			nodeset.add(root.get_lc())
		if root.get_rc() != None:
			nodeset.add(root.get_rc())
		
def width_first(root):
	if root is None:
		return
	nodeset = set()
	nodeset.insert(root)
	while nodeset:
		cur = nodeset.pop(0)
		print(cur.get_data())
		if root.get_lc() != None:
			nodeset.insert(root.get_lc())
		if root.get_rc() != None:
			nodeset.insert(root.get_rc())
		
