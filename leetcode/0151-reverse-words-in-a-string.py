class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        s = s.strip()
        if not s:
            return ''
        tokens = s.split()
        tokens = tokens[::-1]

        tokens2 = []
        for t in tokens:
            tokens2.append( t )
            tokens2.append( ' ' )

        tokens2.pop()

        return ''.join( tokens2 )