import os

f = open(os.path.join(os.path.abspath(os.path.join(__file__, '..')), 'num_and_char.txt'), 'w', encoding = 'utf_8')
for num in range(0x100):
	f.write(f'{num:03d}:0x{num:02x}:{num:08b}:{num:1c}')
	f.write('\n')

f.close()
