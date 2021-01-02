from sklearn.metrics.pairwise import cosine_similarity
from sklearn.feature_extraction.text import TfidfVectorizer
import os, re, sys
import numpy as np

def clean_text(string):
    if string.strip():
        return ' '.join(re.sub('[^A-Za-z0-9 ]+', '', string.strip()).split())
    else:
        return ''

def ngrams(string, n=3):
    return [''.join(ngram) for ngram in zip(*[clean_text(string)[i:] for i in range(n)])]

def compare_words1(string1, string2):
    vectorizer = TfidfVectorizer(min_df=1, analyzer=ngrams)
    tf_idf_matrix = vectorizer.fit_transform([string1, string2])
    return cosine_similarity(tf_idf_matrix)[0][1]

def compare_words2(string1, string2):
    vectorizer = TfidfVectorizer()
    tf_idf_matrix = vectorizer.fit_transform([string1, string2])
    return cosine_similarity(tf_idf_matrix)[0][1]

def my_vectorizer(string1, string2):
    letters = list(set(string1 + string2))
    letters.sort()
    lis = []
    for _str in [string1, string2]:
        l = []
        for letter in letters:
            l.append(_str.count(letter))
        lis.append(l)

    return lis


def compare_words3(string1, string2):
    return cosine_similarity(np.array(my_vectorizer(string1, string2)))[0][1]


if __name__ == '__main__':
    s1 = sys.argv[1]
    s2 = sys.argv[2]
    if not all([type(_str) == str for _str in [s1, s2]]):
        print("Please pass strings only")
        sys.exit(-1)
    print(f'String1 :- {s1}\nString2 :- {s2}')
    print(f'Method1 :- {compare_words1(s1, s2)}')
    print(f'Method2 :- {compare_words2(s1, s2)}')
    print(f'Method3 :- {compare_words3(s1, s2)}')
