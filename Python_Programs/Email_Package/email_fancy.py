import os, re, sys


def bold(text):
    return '<b>' + text + '</b>'

def italic(text):
    return '<i>' + text + '</i>'

def underline(text):
    return '<u>' + text + '</u>'

def break():
    return '<br>'

def newLine():
    return '<br>'

def link(text = None, url = None):
    if ((text is None) and (url is None)):
        return None
    elif ((text is None) and (url is not None)):
        text = ""
    elif ((text is not None) and (url is None)):
        url = 'https://www.google.com/search?q=' + text

    return "<a href=\"" + url + "\">" + text + "</a>"
