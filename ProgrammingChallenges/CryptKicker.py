#!/usr/bin/env python

import sys
import copy

def ReadInput(wordDictionary):
	wordCount = raw_input('word count > ')
	for i in xrange(0, int(wordCount), 1):
		word = raw_input(">")
		if len(word) in wordDictionary.keys():
			wordDictionary[len(word)].append(word)
		else:
			wordDictionary[len(word)] = [ word ]
	
	line = raw_input("encoded line > ")
	while len(line) > 0:
		Decode(line, wordDictionary)
		line = raw_input("encoded line >")

def Decode(text, wordDictionary):
	words = text.split()
	bRet = False

	uniqueWords = set(words)
	decodedWords = []
	decodedAlphabet = {}
	encryptedLine = text
	bRet = Backtrack(uniqueWords, decodedWords, wordDictionary, decodedAlphabet, encryptedLine)

	if bRet is False:
		for letter in encryptedLine:
			sys.stdout.write('*')
		print "\n"
	

def Backtrack(undecodedWords, decodedWords, wordDictionary, decodedAlphabet, encryptedLine):

	bRet = False
	if IsASolution(undecodedWords):
		ProcessSolution(encryptedLine, decodedAlphabet)
		bRet = True
	else:
		currentWord = undecodedWords.pop()
		if currentWord not in decodedWords:
			candidates = ConstructCandidates(currentWord, wordDictionary)
			
			for candidate in candidates:
				currentAlphabet = copy.deepcopy(decodedAlphabet)
				candidateOk = True
				for i in xrange(0, len(currentWord), 1):
					if currentWord[i] not in currentAlphabet:
						currentAlphabet[currentWord[i]] = candidate[i]
					elif currentAlphabet[currentWord[i]] != candidate[i]:
						candidateOk = False
						break
				if candidateOk == True:
					decodedWords.append(currentWord)
					bRet = Backtrack(undecodedWords, decodedWords, wordDictionary, currentAlphabet, encryptedLine)
				if bRet is True:
					break

	return bRet



def IsASolution(undecodedWords):
	if len(undecodedWords) == 0:
		return True
	return False

def ProcessSolution(text, decodedAlphabet):
	words = text.split()

	for word in words:
		for letter in word:
			sys.stdout.write(decodedAlphabet[letter])
		print ' ',
	print "\n"

def ConstructCandidates(word, wordDictionary):
	result = []
	wordLen = len(word)
	if wordLen in wordDictionary.keys():
		result =  wordDictionary[wordLen]

	return result

def main():
	wordDictionary = {}
	encodedLines = []
	ReadInput(wordDictionary)



if __name__ == "__main__":
	main()