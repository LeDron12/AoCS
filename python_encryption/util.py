import constants
import time


class Util:

    def printTests(self, var, sort_keys, amount):
        start_time = time.time()
        path = ""
        if var == 1:
            path = constants.Constants.path1
        elif var == 2:
            path = constants.Constants.path2
        elif var == 3:
            path = constants.Constants.path3
        with open(path, 'r') as file:
            file_content = file.readlines()
            self.sortLines(sort_keys, file_content, amount)
            for i in range(amount):
                print(f'Test № {i + 1}')
                print(f'sort key: {sort_keys[i]}')
                self.printMatch(file_content[i])
        print("time for printing tests spent: ~%s m.s." % (int((time.time() - start_time) * 1000)) + '\n')

    def printMatch(self, str):
        line = str.split()
        str = ''
        for i in range(26):
            str += constants.Constants.keys[i] + ' '
        print(str)
        str = ''
        for i in range(26):
            str += '↓' + ' '
        print(str)
        str = ''
        for i in range(26):
            str += line[i] + ' '
        print(str)
        str = ''
        print('~')
        for i in range(52):
            str += '~'
        print(str)
        print('~')

    def sortLines(self, sort_keys, lines, amount):
        for i in range(amount - 1):
            for j in range(amount - 1):
                if sort_keys[j] < sort_keys[j + 1]:
                    x = sort_keys[j]
                    y = lines[j]
                    sort_keys[j] = sort_keys[j + 1]
                    lines[j] = lines[j + 1]
                    sort_keys[j + 1] = x
                    lines[j + 1] = y
