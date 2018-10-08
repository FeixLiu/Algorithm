def eight_queen(spot, placed):
	if not Legal(spot):
		return False
	if placed == 8:
		return True
	for row in range(0, 7):
		for col in range(0, 7):
			if not spot[row][col]:
				spot[row][col] = 1
			if eight_queens(spot, placed + 1):
				return True
			spot[row][col] = 0
	return False
	
def knights_tour(row, col, move_number, num_moves_taken):
	num_moves_taken += 1
	move_number[row, col] = num_moves_taken
	if num_moves_taken == 64:
		return True
	dRows = [-2, -2, -1, 1, 2, 2, 1, -1]
	dCols = [-1, 1, 2, 2, 1, -1, -2, -2]
	for i in range(0, 7):
		"""
		heuristic algorithm
		try the move with the least followings
		r, c = find_the_least_cost(row, col, move_number)
		if knights_tour(r, c, move_number, num_moves_taken):
			return True
		"""
		r = row + dRows[i]
		c = col + dCols[i]
		if r >= 0 and r < NumRows and 
		c >= 0 and c < NumCols and 
		move_number[r, c] == 0:
			if knights_tour(r, c, move_number, num_moves_taken):
				return True
	move_number[row, col] = 0
	return False
	
def combination(index, selections, items, results):
	if index == len(selections):
		result = []
		for i in range(0, len(selections)):
			result.append(items[selections[i]])
		results.append(result)
	else:
		start = 0
		if index > 0:
			start = selections[index - 1]
			#start = selections[index - 1] + 1
			#combination with no duplication
		for i in range(start, len(items)):
			selections[index] = i
			combination(index + 1, selections, items, results)

def permutation(index, selections, items, results):
	if index == len(selections):
		result = []
		for i in range(0, len(selections)):
			result.append(items[selections[i]])
		results.append(result)
	else:
		for i in range(start, len(items)):
			'''
			permutation with no duplication
			used = False
			for j in range (0, index - 1):
				if selections[j] == i:
					used = True
			if not used:
				selections[index] = i
				permutation(index + 1, selections, items, results)
			'''
			selections[index] = i
			permutation(index + 1, selections, items, results)
