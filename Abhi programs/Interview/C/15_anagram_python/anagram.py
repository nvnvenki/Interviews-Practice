def check_anagram(string1, string2):

	length1 = len(string1);
	length2 = len(string2)

	if length1 != length2:
		return False

	else:

		string1 = sorted(string1);
		string2 = sorted(string2);
		
		for eachTuple in zip(string1, string2):

			if eachTuple[0] != eachTuple[1]:
				return False


		return True



if __name__ == '__main__':
	
	string1 = "ape"
	string2 = "ped"
	result = check_anagram(string1, string2);

	if result == False:
		print "The two strings are not anagrams of each other"
	else:
		print "The two strings are anagrams of each other"