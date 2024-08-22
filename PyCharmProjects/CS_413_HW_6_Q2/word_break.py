def word_break(s, wordDict):
    word_set = set(wordDict)
    M = [False] * (len(s) + 1)
    M[0] = True

    # START CODE HERE
    for i in range(1, len(s) + 1):
        for j in range(i):
            if M[j] and s[j:i] in word_set:
                M[i] = True
                break
    # END CODE HERE

    return M[-1]

if __name__ == '__main__':
    s = "applepenapple"
    wordDict = ["apple", "pen"]
    print(word_break(s, wordDict))  # Output: True
