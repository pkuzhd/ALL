while not aStack.isEmpty() or pointer:
	while pointer != None:
		# 1号访问点 # No.1 visiting point
		element.pointer = pointer
		element.tag = Left
		aStack.push(element)
		pointer = pointer.leftchild
	element = aStack.pop()
	pointer = element.pointer
	if element.tag == Left:
		# 2号访问点 # No.2 visiting point
		element.tag = Right
		aStack.push(element)
		pointer = pointer.rightchild
	else:
		# 3号访问点 # No.3 visiting point
		pointer = None




