The following are the specifications for the assigned task:

Write a program that receives (1) a word, and (2) a dictionary file. It shall then find all anagrams of the given word in the dictionary.

Dictionary files can be downloaded for various languages (e.g., German = de_neu) from CTAN
Implementation

The program shall perform the following steps:

  - Check if all required arguments have been provided

  - Convert the given word (the first argument) to lower case.

  - Open the dictionary file and read it line by line (it contains one word per line)

    For each line, do the following:

    - Read the line into memory (you may use fgets() and a fixed buffer size of 1024)

    - Check if the line fit into the buffer (the last character in the line must be \n)

    - Check if the line contains non-alphabetic characters (isalpha() from <ctype.h>), and if so, skip the line (this may be the case for Umlauts in the german dictionary).

       - Otherwise, convert it to lower case

    - Check if it is the given word, and if so, skip the line (we already know that dampfschiff is an anagram of dampfschiff)

    - Check if it is an anagram of the given word (see below)

        - If it is, print the word.

Anagram Checking

Two words are anagrams of each other if they contain the exact same letters, and only differ in their order. For example, post and stop are anagrams.

You need to develop an algorithm that checks:

    If both words are of the same length

    If both words contain the same letters. 
