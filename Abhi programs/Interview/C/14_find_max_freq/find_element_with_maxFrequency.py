def find_element_max_frequency(my_list):

	frequency_dict = {}

	for eachElement in my_list:

		if frequency_dict.get(eachElement,0) == 0:
			frequency_dict[eachElement] = 1
		else:
			frequency_dict[eachElement] += 1

	print max(frequency_dict.iteritems(), key = lambda x:x[1])




if __name__ == '__main__':

	my_list = [2,3,3,1,2,3,4,2,3,4,5,6];
	find_element_max_frequency(my_list)
	