import random

def create_intdata(d_from, d_to, amount):
	return [random.randint(d_from, d_to) for i in range(amount)]

def create_floatdata(d_from, d_to, amount):
	return [round(random.random() * (d_to - d_from) + d_from, 2) for i in range(amount)]

def create_stringdata(str_len, amount, avail_symbols = []):
	# Symbols [a-z]
	if not avail_symbols:
		avail_symbols = [chr(i) for i in range(97, 123)]

	res = []
	for i in range(amount + 1):
		res.append('')
		for j in range(str_len + 1):
			res[i] += random.choice(avail_symbols)

	return res


def main():
	# data = create_stringdata(5, 300)
	# data = create_floatdata(0, 1000, 300)
	data = create_intdata(0, 1000, 300)

	with open('array.txt', 'w') as f:
		f.write(str(data))

if __name__ == '__main__':
	main()