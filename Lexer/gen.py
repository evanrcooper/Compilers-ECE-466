with open('tokens.h', 'r') as file:
    lines = file.readlines()[8:-2]


str_builder = ''
for line in lines:
    token = line.split(', //')[0].strip()
    keyword = line.split(', //')[1].strip()
    str_builder += f'\"{keyword}\" \t\t{{return {token};}}\n'

print(str_builder)