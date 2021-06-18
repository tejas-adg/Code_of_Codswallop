import os

f = open(os.path.join(os.path.abspath(os.path.join(__file__, '..')), 'num_and_char.txt'), 'w', encoding = 'utf-32')

for num in range(0x110000):
    f.write(rf'{num}: {chr(num)}')
    f.write('\n')

f.close()
