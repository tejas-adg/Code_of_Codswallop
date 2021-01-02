import re, os, sys

raw_file = sys.argv[1]
target_file = sys.argv[2]

rf = open(raw_file)
tf = open(target_file, 'w')

tf.write(re.sub('[!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~\n]+', '', rf.read()))

rf.close()
tf.close()
