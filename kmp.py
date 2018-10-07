def kmp(s, subs, nextpos, pos):
	i = pos - 1
	j = -1
	while i < len(s) and j < len(subs):
		if j == -1 or s[i] == subs[j]:
			i = i + 1
			j = j + 1
		else:
			j = nextpos[j]
	if j >= len(subs):
		return i - len(subs)
	else:
		return -1

def getNext(subs, Next):
	Next[0] = -1
	i = 0
	j = -1
	while i < len(subs):
		if j == -1 or subs[i] == subs[j]:
			i = i + 1
			j = j + 1
			Next[i] = j
		else:
			j = Next[j]

def getNextVal(subs, NextVal):
	NextVal[0] = -1
	i = 0
	j = -1
	while i < len(subs):
		if j == -1 or subs[i] == subs[j]:
			i = i + 1
			j = j + 1
			if subs[i] != subs[j]:
				NextVal[i] = j
			else:
				NextVal[i] = NextVal[j]
		else:
			j = NextVal[j]
