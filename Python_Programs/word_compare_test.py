from sklearn.metrics.pairwise import cosine_similarity
from sklearn.feature_extraction.text import TfidfVectorizer
import os, re, sys

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
    letters = set(string1 + string2) #commit test
    lis = []
    for _str in [string1, string2]:
        l = []
        for letter in letters:
            l.append(_str.count)
        lis.append(l)

    return lis


def compare_words3(string1, string2):
    return None
