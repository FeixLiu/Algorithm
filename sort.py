def quick_sort(a, left, right):
	if left < right:
		i = left
		j = right
		temp = a[left]
		while i < j:
			while a[j] >= temp and i < j:
				j = j - 1
			if i < j:
				a[i] = a[j]
				i = i + 1
			while a[i] <= temp and i < j:
				i = i + 1
			if i < j:
				a[j] = a[i]
				j = j - 1
		a[i] = temp
		quick_sort(a, left, i - 1)
		quick_sort(a, i + 1, right)
		
def bubble_sort(a):
	for i in range(0, len(a) - 1):
		for j in range(0, len(a) - i - 1):
			if a[j] >= a[j + 1]:
				temp = a[j]
				a[j] = a[j + 1]
				a[j + 1] = temp

def insert_sort(a):
	for count in range(1, len(a)):
		current = a[count]
		i = count
		while i >= 1 and a[i - 1] > current:
			a[i] = a[i - 1]
			i = i - 1
		a[i] = current
		print(a)
		
def select_sort(a):
	for i in range(0, len(a)):
		min_dex = i
		for j in range(i + 1, len(a)):
			if a[j] < a[min_dex]:
				min_dex = j
		if min_dex != i:
			temp = a[min_dex]
			a[min_dex] = a[i]
			a[i] = temp

def shell_sort(a):
	gap = (int)(len(a) / 2)
	while gap > 0:
		for i in range(gap, len(a)):
			temp = a[i]
			while i - gap >= 0 and a[i - gap] > temp:
				a[i] = a[i - gap]
				i = i - gap
			a[i] = temp
		gap = (int)(gap / 2)
		
def merge_sort(a, left, right):
	if left < right:
		mid = (int)((left + right) / 2)
		merge_sort(a, left, mid)
		merge_sort(a, mid + 1, right)
		merge(a, left, mid, right)

def merge(a, left, mid, right):
	size = right - left + 1
	temp = [ 0 for _ in range(0, size) ]
	i = left
	j = mid + 1
	count = 0
	while i <= mid and j <= right:
		if a[i] < a[j]:
			temp[count] = a[i]
			i = i + 1
		else:
			temp[count] = a[j]
			j = j + 1
		count = count + 1
	while i <= mid:
		temp[count] = a[i]
		count = count + 1
		i = i + 1
	while j <= right:
		temp[count] = a[j]
		count = count + 1
		j = j + 1
	i = left
	count = 0
	while i <= right:
		a[i] = temp[count]
		i = i + 1
		count = count + 1
		
def create_heap(a, size):
	for i in range((int)(size / 2), 0, -1):
		heap_adjust(a, size, i)

def heap_adjust(a, size, par):
	while par <= (int)(size / 2):
		temp = a[par]
		lc = par << 1
		rc = lc + 1
		if a[par] < a[lc]:
			a[par] = a[lc]
			pos = lc
		if rc <= size and a[par] < a[rc]:
			a[par] = a[rc]
			pos = rc
		if par == pos:
			break
		else:
			a[pos] = temp
		par = pos

def heap_sort(a, size):
	for temp in range(size, 0, -1):
		inter = a[size]
		a[size] = a[1]
		a[1] = inter
		size -= 1
		heap_adjust(a, size, 1)

a = [5, 10, 6, 2, 1, 8, 4, 9, 7, 3]
create_heap(a, 10)
heap_sort(a, 10)
print(a)
