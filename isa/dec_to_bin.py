import json

with open('json/isa.json', 'r') as file:
    data = json.load(file)

# convert the 'opcodeDec' field to 'opcodeBin'
for instruction in data:
    opcode_bin = int(bin(int(instruction.pop('opcodeDec')))[2:], 2)
    instruction['opcodeBin'] = format(opcode_bin, '08b').replace(' ', ' 0')

# save the modified data back to the file
with open('json/isa_bin.json', 'w') as file:
    json.dump(data, file, indent=4)


# print(data)