class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        line, length = [], 0
        i = 0

        while i < len(words):
            if length + len(line) + len(words[i]) > maxWidth:
                # line Complete
                extra_space = maxWidth - length
                spaces = extra_space // max(1, len(line) - 1)
                remainder = extra_space % max(1, len(line) - 1)

                for j in range(max(1, len(line) - 1)):
                    line[j] += " " * spaces
                    if remainder:
                        line[j] += " "
                        remainder -= 1

                res.append("". join(line))
                line, length = [], 0 #Reset line and length

            line.append(words[i])
            length += len(words[i])
            i += 1
        #Handling the last line
        last_line = " ".join(line)
        trailing_space = maxWidth - len(last_line)
        res.append(last_line + " " * trailing_space)
        return res