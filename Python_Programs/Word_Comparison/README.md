# Word Comparison

A python program to test the different types of comparing strings

## Usage

Pass two strings using command line and it will print the result of each method

`> python word_compare_test.py <word1> <word2>`

As always, to include spaces enclose the word in double quotes

To utilize the file and run your own tests, see `Csv_input.py`

## Documentation

The program mainly uses [Cosine Similarity](https://www.google.com/search?q=cosine+similarity) but with different vectorizers, so basically it is a test of different vectorizers with the cosine similarity technique.

### Method - 1: TF-IDF vectorizer with custom analyzer

The custom analyzer generates a list of all possible 'n' letter combinations from the string

### Method - 2: TF-IDF vectorizer with default analyzer

analyzer = 'word'

### Method - 3: TF-IDF vectorizer with default analyzer

analyzer = 'char'

### Method - 4: Count vectorizer

The count vectorizer generates vectors with the count of each letter in the string

### Method - 5: Count vectorizer

The count vectorizer generates vectors with the count of each word in the string
