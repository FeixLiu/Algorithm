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

a = [5, 10, 6, 2, 1, 8, 4, 9, 7, 3]
shell_sort(a)
print(a)
