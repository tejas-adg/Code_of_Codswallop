import os, re, sys, word_compare_test
import pandas as pd

csv_file = sys.argv[1]
try:
    df = pd.read_csv(csv_file).reset_index(drop = True)
    csv = True
except UnicodeDecodeError:
    df = pd.read_excel(csv_file).reset_index(drop = True)
    csv = False
'''
df['TfIdf_Custom_n-gram'] = df.apply(lambda x: word_compare_test.compare_words1(x['String1'], x['String2']), axis = 1)
df['TfIdf_word_analyzer'] = df.apply(lambda x: word_compare_test.compare_words2(x['String1'], x['String2']), axis = 1)
df['TfIdf_char_analyzer'] = df.apply(lambda x: word_compare_test.compare_words3(x['String1'], x['String2']), axis = 1)
df['My_char_Vectorizer'] = df.apply(lambda x: word_compare_test.compare_words4(x['String1'], x['String2']), axis = 1)
df['My_word_Vectorizer'] = df.apply(lambda x: word_compare_test.compare_words5(x['String1'], x['String2']), axis = 1)
'''

for row in range(df.shape[0]):
    if pd.isna(df.loc[row, 'TfIdf_Custom_n-gram']):
        print(f'{row + 1} is empty')
        df.loc[row, 'TfIdf_Custom_n-gram'] = word_compare_test.compare_words1(df.loc[row, 'String1'], df.loc[row, 'String2'])
        df.loc[row, 'TfIdf_word_analyzer'] = word_compare_test.compare_words2(df.loc[row, 'String1'], df.loc[row, 'String2'])
        df.loc[row, 'TfIdf_char_analyzer'] = word_compare_test.compare_words3(df.loc[row, 'String1'], df.loc[row, 'String2'])
        df.loc[row, 'My_char_Vectorizer'] = word_compare_test.compare_words4(df.loc[row, 'String1'], df.loc[row, 'String2'])
        df.loc[row, 'My_word_Vectorizer'] = word_compare_test.compare_words5(df.loc[row, 'String1'], df.loc[row, 'String2'])

if csv:
    df.to_csv(csv_file, index = False)
else:
    df.to_excel(csv_file, index = False)
