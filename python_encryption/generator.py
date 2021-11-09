import random
import time
import constants


class Generator:

    def genTests(self, n, var):
        sort_keys = []
        start_time = time.time()
        if var == 1:
            open(constants.Constants.path1, 'w').close()  # Clearing file1.
            print(f'test have been written to {constants.Constants.path1}')
        elif var == 2:
            open(constants.Constants.path2, 'w').close()  # Clearing file2.
            print(f'test have been written to {constants.Constants.path2}')
        elif var == 3:
            open(constants.Constants.path3, 'w').close()  # Clearing file3.
            print(f'test have been written to {constants.Constants.path3}')

        for i in range(n):
            if var == 1:
                sort_keys.append(self.genTest1())
            elif var == 2:
                sort_keys.append(self.genTest2())
            elif var == 3:
                sort_keys.append(self.genTest3())
        print("time for tests generation spent: ~%s m.s." % (int((time.time() - start_time) * 1000)) + '\n')
        return sort_keys

    def genTest1(self):
        sort_key = 0.0
        dictionary = {}
        with open(constants.Constants.path1, 'a') as file:
            for i in range(26):
                for j in range(999):  # it would break much earlier.
                    x = random.randint(0, 25)
                    if constants.Constants.keys[x] not in dictionary:
                        file.write(constants.Constants.keys[x] + ' ')
                        dictionary[constants.Constants.keys[x]] = x
                        sort_key += ord(constants.Constants.keys[x]);
                        break
            file.write('\n')
        return sort_key * random.randint(0, 10000) / 26.6

    def genTest2(self):
        sort_key = 0.0
        file = open(constants.Constants.path2, 'a')
        x = random.randint(0, 25)
        for i in range(26):
            file.write(constants.Constants.keys[(i + x) % 26] + ' ')
            sort_key += ord(constants.Constants.keys[(i + x) % 26])
        file.write('\n')
        return sort_key * random.randint(0, 10000) / 26.6

    def genTest3(self):
        sort_key = 0.0
        dictionary = {}
        with open(constants.Constants.path3, 'a') as file:
            for i in range(26):
                for j in range(999):
                    x = random.randint(0, 99)
                    if x not in dictionary:
                        dictionary[x] = x
                        file.write(str(x) + ' ')
                        sort_key += x;
                        break
            file.write('\n')
        return sort_key * random.randint(0, 10000) / 26.6
